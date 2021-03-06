#include "../include/mva_analysis.h"
#include "../include/bdt_analysis.h"
#include "../include/mlp_analysis.h"
#include "../include/histo_plot.h"
#include <algorithm>


void MVAAnalysis::get_plots_varying_params(std::vector<DataChain*> bg_chains, int bg_to_train, DataChain* signal_chain, DataChain* data_chain, SuperVars* super_vars,
																					std::string method_name, std::string dir_name, std::vector<const char*> NTrees, std::vector<const char*> BoostType,
																					std::vector<const char*> AdaBoostBeta, std::vector<const char*> SeparationType, std::vector<const char*> nCuts,
																					std::vector<const char*> NeuronType, std::vector<const char*> NCycles, std::vector<const char*> HiddenLayers, std::string mva_cut_str, const char* preprocessing_transform, const char* console_number)
{
// PRODUCES PLOTS WITH AN MVA PARAMTER VARIED SUCH AS NUMBER OF TREES IN A BDT ANALYSIS

//STEP 1 get mva output Tfile with given parameter varied.
////////////////////////////////////////////////////////////////////////////

  std::vector<const char*> file_paths = vary_parameters(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, method_name, dir_name,
																																															   NTrees, BoostType, AdaBoostBeta, SeparationType, nCuts, NeuronType, NCycles, HiddenLayers, mva_cut_str,preprocessing_transform,console_number);

//STEP 2 create a vector of Tfiles and save it in a folder directory
////////////////////////////////////////////////////////////////////////////


  std::vector<TFile*> files = get_files_from_paths(file_paths);
  std::string folder_name = method_name + "_varying_" + dir_name;
  std::cout << "=> Set Folder Name: " << folder_name << std::endl;

//STEP 3 initialise variables
////////////////////////////////////////////////////////////////////////////

  std::vector<Variable*> variables = super_vars->get_signal_cut_vars();

//STEP 4 plot overtraining check i.e. classifier outputs
////////////////////////////////////////////////////////////////////////////

  //ClassifierOutputs::plot_classifiers_for_all_files(files, method_name, folder_name, bg_chains[bg_to_train]->label);
  
//STEP 5 plots roc cruves
////////////////////////////////////////////////////////////////////////////

  RocCurves::get_rocs(files, signal_chain, bg_chains[bg_to_train], super_vars, method_name, folder_name);

}
//END
////////////////////////////////////////////////////////////////////////////


std::vector<TFile*> MVAAnalysis::get_files_from_paths(std::vector<const char*> file_paths)
{
  TFile* files_arr[file_paths.size()];
	 for (int i = 0; i < file_paths.size(); i++)
  	{
    files_arr[i] = TFile::Open(file_paths[i]);
  	}

	 std::vector<TFile*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
  std::cout << "File paths size: " << file_paths.size() << std::endl;
  std::cout << "files size: " << files.size() << std::endl;
	 return files;
}

TFile* MVAAnalysis::get_mva_results(std::vector<DataChain*> bg_chains, int bg_to_train, DataChain* signal_chain, DataChain* data_chain,
																																			SuperVars* super_vars, std::string folder_name, std::string method_name, const char* NTrees,
																																			const char* BoostType, const char* AdaBoostBeta,const char* SeparationType,const char* nCuts,
																																			const char* NeuronType, const char* NCycles, const char* HiddenLayers, std::string mva_cut_str, const char* preprocessing_transform, const char* LearningRate, const char* console_number)
{
//STEP 1 initialize variables
////////////////////////////////////////////////////////////////////////////
std::cout<<"in get_mva_results analysis\n";
	 std::vector<Variable*> vars      = super_vars->get_signal_cut_vars();// variables upon which the preselection cuts are applied
std::cout<<"got signal cut vars\n";
	 std::vector<Variable*> vars2     = super_vars->get_discriminating_vars();// variable which the mva cuts on
std::cout<<"in get_mva_results analysis\n";
	 std::string selection_str        = super_vars->get_final_cuts_str();
	 std::cout<<"about to create tfile\n";
//
  std::string output_path(folder_name);
  output_path.append("/");

//STEP 2 train MVA type
//////////////////////////////////////////////////////////////////////////////
bool train_mva=false;

TFile* trained_output;// = new TFile(output_path.c_str());
	 std::cout<<" created tfile\n";

if (!train_mva)// if mv already trained then trained output is just the file path
{
  if (method_name == "BDT")
  {
    output_path.append(BDTAnalysis::BDT_output_name_str(NTrees, BoostType, AdaBoostBeta,SeparationType,  nCuts, bg_chains[bg_to_train]->label));
  }
  else if (method_name == "MLP")
  {
    output_path.append(MLPAnalysis::MLP_output_name_str(NeuronType, NCycles, HiddenLayers, bg_chains[bg_to_train]->label, preprocessing_transform, LearningRate));
  }
std::cout<<"output path: "<<output_path<<"\n";
trained_output = new TFile(output_path.c_str());
}


else if (train_mva)
{
  if (method_name == "BDT")
  {
    trained_output = BDTAnalysis::create_BDT(bg_chains[bg_to_train], signal_chain, &vars2, folder_name,NTrees,BoostType,AdaBoostBeta, SeparationType, nCuts, console_number);
  }
  else if (method_name == "MLP")
  {
    std::cout<<"about to create mlp\n";
    trained_output = MLPAnalysis::create_MLP(bg_chains[bg_to_train], signal_chain, &vars2, folder_name,NeuronType, NCycles, HiddenLayers, preprocessing_transform, LearningRate, console_number);
  }
}
  std::cout << "=> Trained method " << method_name << ", output file: " << trained_output->GetName() << std::endl;
  std::cout << "=> In folder: " << folder_name << std::endl;	 
//std::cout<<"datachain in out data chains number: "<<i<<" = "<<bg_chains[bg_to_train]->label<<"\n";

//STEP 3 get data, signal and background chains with output friend tree attached
//////////////////////////////////////////////////////////////////////////////
  DataChain* single_bg[] = {bg_chains[bg_to_train]};
  std::vector<DataChain*> single_bg_vector (single_bg, single_bg + sizeof(single_bg) / sizeof(single_bg[0]));  
                    

std::vector<DataChain*> output_bg_chains = get_output_bg_chains(bg_chains, vars, method_name, trained_output, console_number);
std::cout << "=> All background put through MVA" << std::endl;

DataChain* output_signal_chain           = get_output_signal_chain(signal_chain, vars, method_name, trained_output, console_number);
std::cout << "=> Signal put through MVA" << std::endl;

DataChain* output_data_chain = get_output_data_chain(data_chain, vars, method_name, trained_output, console_number);
std::cout << "=> Data put through MVA" << std::endl;

  Variable* mva_output                     = new Variable("output","MVA Output","-1.25","1.5","-1.25","1.5","100","1", "", false);
  std::cout << "=> Declared MVA_Output Variable" << std::endl;
//STEP 4 get output and variable plot names
////////////////////////////////////////////////////////////////////////////

std::string output_graph_name            = build_output_graph_name(trained_output);
std::cout<<"=======>>>output graph name: "<<output_graph_name<<"\n";
  
std::string output_graph_name_mva_cut = HistoPlot::get_mva_name(output_graph_name,mva_output->name, 
                                            mva_cut_str);//sets name for out put graph plot with mva cut

std::string var_graph_name_mva_cut = HistoPlot::get_mva_name(output_graph_name,vars[1]->name, mva_cut_str);

//STEP 5 draw output and variables plots
////////////////////////////////////////////////////////////////////////////
bool with_cut = true;
/*
TH1F* sig_histo = HistoPlot::build_1d_histo(output_signal_chain, vars[0], with_cut, true, "goff", &vars,"", mva_cut_str);
std::cout << "=> plotted signal fine" << std::endl;

TH1F* data_histo = HistoPlot::build_1d_histo(output_data_chain, vars[0], with_cut, true, "goff", &vars,"", mva_cut_str);
std::cout << "=> plotted data fine" << std::endl;

TH1F* gb_histo = HistoPlot::build_1d_histo(output_bg_chains[0], vars[0], with_cut, true, "goff", &vars,"", mva_cut_str);std::cout << "=> plotted background fine" << std::endl;
*/


 HistoPlot::draw_plot(mva_output, output_bg_chains, output_signal_chain, output_data_chain,true, &vars,false, false, output_graph_name,"");
//vars ={alljetsmetnomu_mindphi, metnomu_significance, dijet_deta, jet1_E, jet2_E}
   //   HistoPlot::draw_plot(vars[0],output_bg_chains, output_signal_chain, output_data_chain,true, &vars, false, false, output_graph_name_mva_cut,"",mva_cut_str);
   													
//STEP 6 create datacard
////////////////////////////////////////////////////////////////////////////
bool make_datacard = false;

if(make_datacard)
{ 
  if(train_mva=true){
  std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"<<
             "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"<<
             "******   train_mva set to true so can't create datacard   ******\n"
             "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"<<
             "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
  }

else{
  double arr[bg_chains.size()];
  std::fill_n(arr, bg_chains.size(), 1);
  std::vector<double> mc_weights_vector (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  const char* mva_cut_arr[]={"output>0.0","output>0.1","output>0.2","output>0.3","output>0.4","output>0.5","output>0.6","output>0.7"
 ,"output>0.8","output>0.9","output>1.0"};
  for(int i =0;i<sizeof(mva_cut_arr)/sizeof(mva_cut_arr[0]); i++)
  {
    mva_cut_str=mva_cut_arr[i];
    std::string output_graph_name_mva_cut = HistoPlot::get_mva_name(output_graph_name,mva_output->name, 
                                             mva_cut_str);
   mc_weights_vector = HistoPlot::mc_weights(output_data_chain, output_bg_chains, vars[0], true, &vars,mva_cut_str);


    DataCard::create_datacard(mc_weights_vector,output_data_chain, output_signal_chain, output_bg_chains, vars[1], true, &vars,mva_cut_str, output_graph_name_mva_cut);
    std::cout<<"=> DataCard created\n";   
  }
  }
}
std::cout << "=> Drew MVA Output plot for all backgrounds and signal" << std::endl;
  
  std::cout << "Trained output name: "<< trained_output->GetName() << " " << trained_output << std::endl;
  std::cout << "test mva results " << ", " << (TH2F*) trained_output->Get("CorrelationMatrixS;1") << std::endl;
    return trained_output;


}

std::vector<DataChain*> MVAAnalysis::get_output_bg_chains(std::vector<DataChain*> bg_chains, std::vector<Variable*> vars,
																																																										std::string method_name, TFile* training_output, const char* console_number)
{
  std::vector<DataChain*> output_bg_chains;

	 for (int i = 0; i < bg_chains.size(); i++)
  {
	 		DataChain* combined_output;

	 		if (method_name == "BDT")
	 		{
	 		  combined_output = BDTAnalysis::get_BDT_results(bg_chains[i], &vars, training_output->GetName(), console_number);
	 		}
	 		else if (method_name == "MLP")
	 		{
	 				combined_output = MLPAnalysis::get_MLP_results(bg_chains[i], &vars, training_output->GetName(), console_number);
	 		}
   			
	 		output_bg_chains.push_back(combined_output);
  }

	 return output_bg_chains;
}

DataChain* MVAAnalysis::get_output_signal_chain(DataChain* signal_chain, std::vector<Variable*> vars, std::string method_name,
																																																TFile* training_output, const char* console_number)
{

	 if (method_name == "BDT")
		{
		  return BDTAnalysis::get_BDT_results(signal_chain, &vars, training_output->GetName(), console_number);
		}
		else
		{
		 	return MLPAnalysis::get_MLP_results(signal_chain, &vars, training_output->GetName(), console_number);
		}
}

DataChain* MVAAnalysis::get_output_data_chain(DataChain* data_chain, std::vector<Variable*> vars, std::string method_name,
																																																TFile* training_output, const char* console_number)
{

	 if (method_name == "BDT")
		{
		  return BDTAnalysis::get_BDT_results(data_chain, &vars, training_output->GetName(), console_number);
		}
		else
		{
		 	return MLPAnalysis::get_MLP_results(data_chain, &vars, training_output->GetName(), console_number);
		}
}


std::string MVAAnalysis::build_output_graph_name(TFile* trained_output)
{
  std::string file_name = trained_output->GetName();
  file_name.insert(file_name.find("/") + 1, "output_");

  return HistoPlot::replace_all(file_name, ".root", ".png");
}


std::vector<const char*> MVAAnalysis::vary_parameters(std::vector<DataChain*> bg_chains, int bg_to_train, DataChain* signal_chain,
																																																						DataChain* data_chain, SuperVars* super_vars, std::string method_name,
																																																						std::string dir_name, std::vector<const char*> NTrees, std::vector<const char*> BoostType,
																				                                  std::vector<const char*> AdaBoostBeta, std::vector<const char*> SeparationType,
																																																						std::vector<const char*> nCuts, std::vector<const char*> NeuronType,
																																																						std::vector<const char*> NCycles, std::vector<const char*> HiddenLayers,std::string mva_cut_str, const char* preprocessing_transform, const char* console_number)
{
	 std::string folder_name = method_name + "_varying_" + dir_name;

	 if (method_name == "BDT")
	 {
    if (dir_name == "NTrees")
    	{
    		const char* files_arr[NTrees.size()];
    		for (int i = 0; i < NTrees.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[i],
      														BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"","",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;

      	}
    		 std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		 return files;
    	}
    else if (dir_name == "BoostType")
    	{
    		const char* files_arr[BoostType.size()];
    		for (int i = 0; i < BoostType.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[i], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"","",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
    	}
    else if (dir_name == "AdaBoostBeta")
    	{
    		const char* files_arr[AdaBoostBeta.size()];
    		for (int i = 0; i < AdaBoostBeta.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[i], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"","",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
    	}
    else if (dir_name == "SeparationType")
    	{
    		const char* files_arr[SeparationType.size()];
    		for (int i = 0; i < SeparationType.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[0], SeparationType[i], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"","",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
    	}
    else if (dir_name == "nCuts")
    	{
    		const char* files_arr[nCuts.size()];
    		for (int i = 0; i < nCuts.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[i], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"","",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
    	}
	 }
	 else if (method_name == "MLP")
	 {
	 		if (dir_name == "NeuronType")
	 			{
	 				const char* files_arr[NeuronType.size()];

    		for (int i = 0; i < NeuronType.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[i], NCycles[0], HiddenLayers[0], mva_cut_str, preprocessing_transform,"",console_number);
    				const char* file_path = file->GetName();
    				//std::cout << file_path << std::endl;
    				files_arr[i] = file_path;
    				//std::cout << files_arr[i] << std::endl;
      	}

    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
	 			}
	 		else if (dir_name == "NCycles")
	 			{
	 				const char* files_arr[NCycles.size()];
    		for (int i = 0; i < NCycles.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[i], HiddenLayers[0], mva_cut_str, preprocessing_transform,"",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;
	 			}
	 		else if (dir_name == "HiddenLayers")
	 			{
	 				const char* files_arr[HiddenLayers.size()];
    		for (int i = 0; i < HiddenLayers.size(); i++)
      	{
    				TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      														BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[i], mva_cut_str,preprocessing_transform,"",console_number);
    				const char* file_path = file->GetName();
    				files_arr[i] = file_path;
      	}
    		std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));

    		return files;

	 			}
	 		else if (dir_name == "preprocessing_transform")
	 			{
                                  const char* preprocessing_transform_arr[] = {"N", "G,D,N","U,D,N", "G,P,N","U,P,N"};                                            // Normalise the variable(set to between1- and 1) ,D-variable decomposition, PCA, Uniform, Gauss          
	 		          const char* files_arr[5];

    		                  for (int i = 0; i < 5; i++)
                                    {
    				    TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      							BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,preprocessing_transform_arr[i],"",console_number);
    				    const char* file_path = file->GetName();
    				    files_arr[i] = file_path;
                                    }

    		                 std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
    		                 return files;
	 			}
	 		else if (dir_name == "learning_rate")
	 			{
                                  const char* learning_rate_arr[] = {"0.2", "0.02","0.002"};   //           
	 		          const char* files_arr[6];

    		                  for (int i = 0; i < 6; i++)
                                    {
    				    TFile* file = get_mva_results(bg_chains, bg_to_train, signal_chain, data_chain, super_vars, folder_name, method_name, NTrees[0],
      							BoostType[0], AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0], NCycles[0], HiddenLayers[0], mva_cut_str,"", learning_rate_arr[i],console_number);
    				    const char* file_path = file->GetName();
    				    files_arr[i] = file_path;
                                    }

    		                 std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
    		                 return files;
	 			}
	 }
}

TH1F* MVAAnalysis::plot_output(DataChain* combined_data)
{
  combined_data->chain->Draw("output>>output_hist(100, -0.8, 0.8)");
  TH1F* histo = (TH1F*)gDirectory->Get("output_hist");

  return histo;
}

std::vector<double> MVAAnalysis::get_categories(TH1F* output_histo)
{
  int first_bin = output_histo->FindFirstBinAbove(0.0, 1);
  int zero_bin = output_histo->FindBin(0.0);
  int last_bin = output_histo->FindLastBinAbove(0.0, 1);
  double total_integral = output_histo->Integral(0, output_histo->GetNbinsX() + 1);

  double tmp_integral_bg;
  double tmp_integral_sig;
  int bg_bin;
  int sig_bin;
  //bg
  for (int i = zero_bin; i > first_bin; i--)
  	{
    tmp_integral_bg = output_histo->Integral(first_bin, i);
    bg_bin = i;
    if ((tmp_integral_bg / total_integral) < 0.1)
    	{
    		break;
    	}
  	}
  std::cout << "bg" << bg_bin << std::endl;
  //sig
  for (int i = zero_bin; i < last_bin; i++)
  {
    tmp_integral_sig = output_histo->Integral(i, last_bin);
    sig_bin = i;
    if ((tmp_integral_bg / total_integral) < 0.1)
    {
      break;
    }
  }
  std::cout << "sig" << sig_bin << std::endl;
	 double bg_up_lim = output_histo->GetBinCenter(bg_bin);
  double sig_low_lim = output_histo->GetBinCenter(sig_bin);
  double x_arr[] = {-0.8, bg_up_lim, 0, sig_low_lim, 0.8};
  std::cout << "bg_xmax" << bg_up_lim << std::endl;
  std::cout << "sig_xmin" << sig_low_lim << std::endl;
  std::vector<double> categories (x_arr, x_arr + sizeof(x_arr) / sizeof(x_arr[0]));

  return categories;
}

std::vector<std::string> MVAAnalysis::get_category_strs(std::vector<double> categories)
{
  std::string cat_strs[4];

	 for (int i = 0; i < 4; i++)
  {
    cat_strs[i] = "(output > " + HistoPlot::get_string_from_double(categories[i]) + ")&&(output <= " + HistoPlot::get_string_from_double(categories[i+1]) + ")";
  }
	 std::vector<std::string> cat_strs_vector (cat_strs, cat_strs + sizeof(cat_strs) / sizeof(cat_strs[0]));
	 std::cout << "cat_strs_vector done" << cat_strs_vector[0] << std::endl;
	 return cat_strs_vector;
}

TH1F* MVAAnalysis::build_histo(DataChain* combined_output, std::string selection_str, Variable* variable, std::string histo_label)
{
  std::string hist_label = combined_output->extra_label + histo_label;

  std::string var_arg = variable->build_var_string(hist_label.c_str(), true);

  combined_output->chain->Draw(var_arg.c_str(), selection_str.c_str(), "goff");

  TH1F* histo = (TH1F*)gDirectory->Get(hist_label.c_str());

  return histo;
}

std::string MVAAnalysis::build_output_sel_str(std::string category, std::string final_cuts)
{
	 std::string selection_str = final_cuts;
	 selection_str.insert(selection_str.find("(") + 1, category + "&&");

	 return selection_str;
}

TH1F* MVAAnalysis::draw_signal(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(2);
  combined_output->chain->SetLineWidth(3);
  combined_output->chain->SetFillColor(0);

  TH1F* histo = build_histo(combined_output, build_output_sel_str(category, final_cuts), variable, "signal");

  return histo;
}

TH1F* MVAAnalysis::draw_background(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(1);
  combined_output->chain->SetFillColor(40);

  TH1F* hist = build_histo(combined_output, build_output_sel_str(category, final_cuts), variable, "bg");

  return hist;
}

void MVAAnalysis::style_histo(TH1F* histo)
{
	 histo->GetYaxis()->SetTitle("Events");
	 histo->GetYaxis()->SetLabelSize(0.035);
	 histo->GetYaxis()->SetTitleOffset(1.55);
	 histo->GetXaxis()->SetLabelSize(0);
	 histo->SetStats(kFALSE);
	 histo->SetTitle("");
}

void MVAAnalysis::draw_histo(DataChain* combined_output, std::string final_cuts, Variable* variable)
{
	 std::vector<std::string> category_strs = get_category_strs(get_categories(plot_output(combined_output)));

  TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);
  TCanvas* c1     = new TCanvas("c1", variable->name_styled, 800, 800);
  TPad* p1        = new TPad("p1", "p1", 0.0, 0.95, 1.0, 1.0);
  TPad* p2        = new TPad("p2", "p2", 0.0, 0.2, 1.0, 0.95);
  TPad* p3        = new TPad("p3", "p3", 0.0, 0.0, 1.0, 0.2);

  p1->SetLeftMargin(0.102);
  p2->SetBottomMargin(0.012);
  p2->SetLeftMargin(0.105);
  p3->SetBottomMargin(0.3);
  p3->SetLeftMargin(0.102);
  p1->Draw();
  p2->Draw();
  p3->Draw();
  p2->cd();

  TH1F* very_sig = draw_signal(combined_output, category_strs[3], final_cuts, variable);
  TH1F* very_bg  = draw_background(combined_output, category_strs[0], final_cuts, variable);

  legend->AddEntry(very_sig, "Signal (Top 10% of output)", "f");
  legend->AddEntry(very_bg, "Background (Bottom 10% of output)", "f");
  HistoPlot::style_legend(legend);

  very_bg->Draw();
  very_sig->Draw("SAME");
  legend->Draw("SAME");
  style_histo(very_bg);
  style_histo(very_sig);
  TH1F* plot_histos[2] = {very_sig, very_bg};
  std::vector<TH1F*> plot_histos_vector (plot_histos, plot_histos + sizeof(plot_histos) / sizeof(plot_histos[0]));
  TH1F* max_histo = HistoPlot::get_max_histo(plot_histos_vector);

  very_bg->SetMaximum(HistoPlot::get_histo_y_max(max_histo)*1.1);

  HistoPlot::draw_subtitle(variable, NULL, true, combined_output, final_cuts);

  p3->cd();
  TH1F* data_bg_ratio_histo = HistoPlot::data_to_bg_ratio_histo(plot_histos[0], plot_histos[1]);
  data_bg_ratio_histo->Draw("e1");
  HistoPlot::style_ratio_histo(data_bg_ratio_histo, variable->name_styled, false);
  HistoPlot::draw_yline_on_plot(variable, true, 1.0);
  p1->cd();
  HistoPlot::draw_title((combined_output->extra_label).c_str());
  c1->SaveAs("output_test.png");
  c1->Close();
}

std::string MVAAnalysis::neuron_namer(std::string trained_file_path, int neuron_type_id)
{
  std::string trained_file_name;
  trained_file_name = trained_file_path;
  trained_file_name.append("NeuronType=");
  trained_file_name.append(NeuronType[neuron_type_id]);
  //std::cout<<"neuron type: "<<NeuronType[neuron_type_id]<<"\n";
  trained_file_name.append("-");
  trained_file_name.append( + "NCycles="); 
  trained_file_name.append(NCycles[0]);
  trained_file_name.append("-");
  trained_file_name.append( + "HiddenLayers=");
  trained_file_name.append(HiddenLayers[0]);
  trained_file_name.append(".root");
  return trained_file_name;
}

std::string MVAAnalysis::cycle_namer(std::string trained_file_path, int id)
{
  std::string trained_file_name;
  trained_file_name = trained_file_path;
  trained_file_name.append("NeuronType=");
  trained_file_name.append(NeuronType[0]);
  //std::cout<<"neuron type: "<<NeuronType[neuron_type_id]<<"\n";
  trained_file_name.append("-");
  trained_file_name.append( + "NCycles="); 
  trained_file_name.append(NCycles[id]);
  trained_file_name.append("-");
  trained_file_name.append( + "HiddenLayers=");
  trained_file_name.append(HiddenLayers[0]);
  trained_file_name.append(".root");
  return trained_file_name;
}

std::string MVAAnalysis::layer_namer(std::string trained_file_path, int id)
{
  std::string trained_file_name;
  trained_file_name = trained_file_path;
  trained_file_name.append("NeuronType=");
  trained_file_name.append(NeuronType[0]);
  //std::cout<<"neuron type: "<<NeuronType[neuron_type_id]<<"\n";
  trained_file_name.append("-");
  trained_file_name.append( + "NCycles="); 
  trained_file_name.append(NCycles[0]);
  trained_file_name.append("-");
  trained_file_name.append( + "HiddenLayers=");
  trained_file_name.append(HiddenLayers[id]);
  trained_file_name.append(".root");
  
  return trained_file_name;
}

/*
std::vector<const char*> MVAAnalysis::get_file_vector_for_roc_curves(const char* bg_chain_label,
std::string mva_type, std::string varying_parameter,const char* preprocessing_transform)
{
  std::cout<<"in get file vector, varying paramter: "<<varying_parameter<<"\n";
  std::string trained_file_path; 
  std::string trained_file_name;
  if (mva_type == "MLP")
  {
  const char* current_NeuronType = NeuronType[0];
  const char* current_NCycles = NCycles[0];
  const char* current_HiddenLayers = HiddenLayers[0];
  if (varying_parameter == "NeuronType")
    	{ 
          const char* files_arr[NeuronType.size()];
          for (int i = 0; i < NeuronType.size(); i++)
      	    {
              current_NeuronType= NeuronType[i];
              trained_file_name = MLPAnalysis::MLP_output_name_str(current_NeuronType, current_NCycles, 
                                           current_HiddenLayers,bg_chain_label, preprocessing_transform);
              const char* file_name = trained_file_name.c_str();
              files_arr[i] = file_name;
            }
           std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
           return files;
         }
  if (varying_parameter == "NCycles")
    	{ 
          const char* files_arr[NCycles.size()];
          for (int i = 0; i < NCycles.size(); i++)
      	    {
              current_NCycles= NCycles[i];
              trained_file_name = MLPAnalysis::MLP_output_name_str(current_NeuronType, current_NCycles, 
                                           current_HiddenLayers,bg_chain_label, preprocessing_transform);
              const char* file_name = trained_file_name.c_str();
              files_arr[i] = file_name;
            }
           std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
           return files;
         }

  trained_file_path =  "MLP-";
  trained_file_path.append(bg_chain_label);
  trained_file_path.append("-");

        if (varying_parameter == "NeuronType")
    	{
          const char* files_arr[NeuronType.size()];
          for (int i = 0; i < NeuronType.size(); i++)
      	    {
              trained_file_name = neuron_namer(trained_file_path, i);
              files_arr[i] = trained_file_name.c_str();
      	    }
           std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
           return files;
         }

        if (varying_parameter == "NCycles")
    	{
          const char* files_arr[NCycles.size()];
          for (int i = 0; i < NCycles.size(); i++)
      	    {
              trained_file_name = cycle_namer(trained_file_path, i);
              std::cout<<"file name in loop: "<<trained_file_name<<"\n";
              files_arr[i] =  trained_file_name.c_str();
      	    }
           std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
           return files;
         }

        if (varying_parameter == "HiddenLayers")
    	{
          const char* files_arr[HiddenLayers.size()];
          for (int i = 0; i < NCycles.size(); i++)
      	    {
              trained_file_name = layer_namer(trained_file_path, i);
              std::cout<<"file name in loop: "<<trained_file_name<<"\n";
              files_arr[i] =  trained_file_name.c_str();
      	    }
           std::vector<const char*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
           return files;
         }
   }
}
*/
/*
void MVAAnalysis::multiplot(DataChain* training_bg_chain, DataChain* signal_chain, SuperVars* super_vars, std::string mva_type, std::string varying_parameter)
{
//STEP 1 create a vector of files of the trained root files
//////////////////////////////////////////////////////////////////////////////

  std::vector<const char*> file_paths = get_file_vector_for_roc_curves(training_bg_chain->label, 
mva_type,varying_parameter);
  

//STEP 2 turn file vector in Tfile vector and get folder name
//////////////////////////////////////////////////////////////////////////////

  std::vector<TFile*> t_files = get_files_from_paths(file_paths);
  std::string folder_name = mva_type;
  folder_name.append("_varying_"); 
  folder_name.append(varying_parameter);
  std::cout << "=> Set Folder Name: " << folder_name << std::endl;

//STEP 3 initialise variables
////////////////////////////////////////////////////////////////////////////

  std::vector<Variable*> variables = super_vars->get_signal_cut_vars();

//STEP 4 plot overtraining check i.e. classifier outputs
////////////////////////////////////////////////////////////////////////////

  //ClassifierOutputs::plot_classifiers_for_all_files(files, method_name, folder_name, training_bg_chain->label);
  
//STEP 5 plots roc cruves
////////////////////////////////////////////////////////////////////////////

 // RocCurves::get_rocs(files, signal_chain, training_bg_chain, super_vars, mva_type, folder_name);

}*/
//END
////////////////////////////////////////////////////////////////////////////

