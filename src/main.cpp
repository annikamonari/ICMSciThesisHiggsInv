#include <initializer_list>
#include <cmath>
#include "../include/data_card.h"
#include "../include/Mlp_analysis.h"

void produce_graphs(bool with_cut) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();
  const char* mva_type = "MLP";
  const char* NTrees = "10";
  const char* BoostType = "AdaBoost";
  const char* AdaBoostBeta ="0.5";
  const char* SeparationType = "GiniIndex";
  const char* nCuts = "30";
  
  const char* const NeuronType[2] = {"sigmoid","tanh"};
  const char* NCycles[5] = {"10","100","500","1000","5000"};
  const char* HiddenLayers[8] = {"2","5","10","50","5,5","5,5,5","5,5,5,5","5,5,5,5,5"} ;//number of neurons in each hidden layer

  const int file_no = 15;
  const char* file_names[file_no];
  int counter =0;

  SuperChains* super_chains         = new SuperChains();
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;
  
  /*double signal_error = DataCard::get_signal_error(signal_chain, cut_vars[0],true, &cut_vars); 
  std::cout<<"signal error: "<<signal_error<<"\n";
  //std::vector<double> bg_errors = DataCard::get_bg_errors(data_chain,bg_chains,signal_chain, cut_vars[0], true, &cut_vars);
  //std::cout<<"bg errors: "<<bg_errors[0]<<"\n";

  //std::vector<std::vector<double> > error_matrix = DataCard::get_uncertainty_vectors(signal_error, bg_errors);
  /*for (int i=0;i<7;i++){
   std::cout<<"error matrix: "<<"\n"<<error_matrix[i][i]<<"\n";
  }*/

  /*BDTAnalysis::create_BDT(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva());
  TFile* file1 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=10-HiddenLayers=5,5,5.root");
  TFile* file2 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=100-HiddenLayers=5,5,5.root");
  TFile* file3 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=1000-HiddenLayers=5,5,5.root");
  TFile* file4 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=500-HiddenLayers=10.root");
  TFile* file5 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=500-HiddenLayers=2.root");
  TFile* file6 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=500-HiddenLayers=5,5,5,5,5.root");
  TFile* files[] = {file1, file2, file3};
  std::vector<TFile*> tfiles (files, files+ sizeof(files)/sizeof(TFile*));
  //RocCurves::get_presel_effy(bg_chains[0], super_vars->get_final_cuts_str(), vars[0], &vars);
  RocCurves::get_rocs(tfiles, signal_chain, bg_chains[0], super_vars);*/

  //MVAAnalysis::plot_bdt_results(bg_chains, signal_chain, data_chain, super_vars,NeuronType, NCycles, HiddenLayers,NTrees, BoostType, AdaBoostBeta, SeparationType,nCuts,  mva_type);
  for (int j=0; j < 1; j++)
  {
    if (!strcmp(mva_type, "BDT")){
        BDTAnalysis::create_BDT(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva(),NTrees,BoostType,AdaBoostBeta,
	SeparationType, nCuts);
	//file_names[counter] = BDTAnalysis::BDT_output_name_str(NTrees,BoostType,AdaBoostBeta,SeparationType, nCuts).c_str();
    };
    if (!strcmp(mva_type, "MLP")){
        MLPAnalysis::create_MLP(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva(),NeuronType[0],NCycles[j],HiddenLayers[5]);
	file_names[counter] = MLPAnalysis::MLP_output_name_str(NeuronType[0],NCycles[j],HiddenLayers[5]).c_str();
    };
    std::cout<< "file_name :"<< file_names[counter] <<"\n";
    counter++;
  }
  //BDTAnalysis::get_BDT_results(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva(), NTrees,BoostType,AdaBoostBeta,SeparationType, nCuts);
  //MLPAnalysis::get_MLP_results(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva(),NeuronType[0],NCycles[j],HiddenLayers[5]);

  DataCard::create_datacard(data_chain,signal_chain,bg_chains, cut_vars[0], with_cut, &cut_vars);
  /*std::string test = "";
  double MC_N_S = HistoPlot::get_histo_integral(HistoPlot::build_1d_histo(bg_chains[0], vars[0], with_cut, false, "goff", &cut_vars,test), with_cut, vars[0]);
  double error;  
  error = HistoPlot::single_bg_error(data_chain, bg_chains, bg_chains[0], vars[0], true, &cut_vars);
  std::cout<<"variable: "<<vars[0]->name<<", background: "<<bg_chains[0]->legend<<", total events: "<<MC_N_S<<"\n"<<"error = "<<error<<"\n";*/
  for (int i = 0; i < 1; i++)
  {
     //HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &cut_vars, false);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true);
  theApp.Run();
  return 0;
}

// need N signal and N background in signal region +/- sigma MC (Stat) -> from unweighted number of MC events that pass
// for background you have that as well, because you get Nsbg = Ncdata - Nc other * NsMC / Nc MC
// error = squareroot(number of background events) -  poisson
// need to plot the bdt outputs superimposed for all backgrounds and signal and then optimise the cut on this

// train a bdt on one bg and signal, but then test the bdt on all of the backgrounds and signal separately and choose where to make the cut.
