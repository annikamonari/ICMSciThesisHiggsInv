#include "../include/mlp_analysis.h"
//#include "TInterpretor.h"
void MLPAnalysis::create_MLP(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables, std::string var_cut_str, const char* NeuronType, const char* NCycles, const char* HiddenLayers)
{

  // This loads the library
  //TMVA::Tools::Instance();


  // to get access to the GUI and all tmva macros

  /* TString thisdir = gSystem->DirName(gInterpreter->GetCurrentMacroName());

   gROOT->SetMacroPath(thisdir + ":" + gROOT->GetMacroPath());
   gROOT->ProcessLine(".L TMVAGui.C");*/


  // --- Here the preparation phase begins
  // Create a ROOT output file where TMVA will store ntuples, histograms, etc.

    std::string output_folder(bg_chain->label);
    output_folder.append("/");
    std::string output_file;
 
    output_file = MLP_output_name_str(NeuronType,NCycles,HiddenLayers);
  
  output_folder.append(output_file);
  const char* name = output_folder.c_str();
  TFile* output_tmva = TFile::Open(name,"RECREATE");

  TMVA::Factory* factory = new TMVA::Factory("TMVAClassification", output_tmva,
                                             "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");

  for (int i = 0; i < variables->size(); i++)
  {
    factory->AddVariable((*variables)[i]->name, (*variables)[i]->name_styled, (*variables)[i]->units, 'F');
  }

  // Background
  double background_weight = 1.0;
  factory->AddBackgroundTree(bg_chain->chain,background_weight);
  factory->SetBackgroundWeightExpression("total_weight_lepveto");

  // Signal
  double signal_weight = 1.0;
  factory->AddSignalTree(signal_chain->chain, signal_weight);
  factory->SetSignalWeightExpression("total_weight_lepveto");

  // Apply additional cuts on the signal and background samples (can be different)
  TCut signal_cuts = "alljetsmetnomu_mindphi>2.0 && alljetsmetnomu_mindphi<3.0 && jet1_E>50.0 && jet2_E>45.0 && metnomu_significance>3.5 && dijet_deta>4.2 && dijet_deta<8.0 && nvetomuons==0 && nvetoelectrons==0"; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
  TCut bg_cuts = signal_cuts; // for example: TCut mycutb = "abs(var1)<0.5";

  factory->PrepareTrainingAndTestTree(signal_cuts, bg_cuts,
  				       "SplitMode=Random:NormMode=NumEvents:!V" );
  std::cout<<"mlp option str: "<<MLP_options_str(NeuronType, NCycles, HiddenLayers)<<"\n";
  
  factory->BookMethod(TMVA::Types::kMLP, "MLP", MLP_options_str(NeuronType, NCycles, HiddenLayers) );


  // Train MVAs using the set of training events
  factory->TrainAllMethods();

  // ---- Evaluate all MVAs using the set of test events
  factory->TestAllMethods();

  // ----- Evaluate and compare performance of all configured MVAs
  factory->EvaluateAllMethods();

  // --------------------------------------------------------------

  // Save the output
  output_tmva->Close();

  std::cout << "==> Wrote root file: " << output_tmva->GetName() << std::endl;
  std::cout << "==> TMVAClassification is done!" << std::endl;
  std::cout << std::endl;
  std::cout << "==> To view the results, launch the GUI: \"root -l ./TMVAGui.C\"" << std::endl;
  std::cout << std::endl;

  //gROOT->ProcessLine(".L TMVAGui.C");

  delete factory;
}

TTree* MLPAnalysis::evaluate_MLP(DataChain* bg_chain,std::vector<Variable*>* variables, const char* NeuronType, const char* NCycles, const char* HiddenLayers)
{
	   TMVA::Reader* reader = new TMVA::Reader( "!Color:!Silent" );

	   Float_t dijet_deta;
	   Float_t forward_tag_eta;
	   Float_t metnomu_significance;
	   Float_t sqrt_ht;
	   Float_t alljetsmetnomu_mindphi;
	   Float_t dijet_M;
	   Float_t metnomuons;

	   reader->AddVariable("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
	   reader->AddVariable("forward_tag_eta", &forward_tag_eta);
	   reader->AddVariable("dijet_deta", &dijet_deta);
	   reader->AddVariable("metnomu_significance", &metnomu_significance);
	   reader->AddVariable("sqrt_ht", &sqrt_ht);
	   reader->AddVariable("dijet_M", &dijet_M);
	   reader->AddVariable("metnomuons", &metnomuons);

	   // Book method(s)
 	   reader->BookMVA( "MLP method", "weights/TMVAClassification_MLP.weights.xml" );
	   // Book output histograms
	   TH1F* histNn     = new TH1F( "MVA_MLP", "MVA_MLP", 100, -1.25, 1.5 );
	   // --- Event loop

	   TChain* data = bg_chain->chain;

	   data->SetBranchAddress("dijet_deta", &dijet_deta);
	   data->SetBranchAddress("forward_tag_eta", &forward_tag_eta);
	   data->SetBranchAddress("metnomu_significance", &metnomu_significance);
	   data->SetBranchAddress("sqrt_ht", &sqrt_ht);
	   data->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
	   data->SetBranchAddress("dijet_M", &dijet_M);
	   data->SetBranchAddress("metnomuons", &metnomuons);

	   // Efficiency calculator for cut method
	   Int_t    nSelCutsGA = 0;
	   Double_t effS       = 0.7;
	   std::vector<Float_t> vecVar(9); // vector for EvaluateMVA tests

	   Float_t output;
	   TTree* output_tree = new TTree("MVAtree","Tree with classifier outputs");
	   output_tree -> Branch("output", &output, "output");

	   std::cout << "--- Processing: " << data->GetEntries() << " events" << std::endl;
	   TStopwatch sw;
	   sw.Start();
	   for (Long64_t ievt=0; ievt<data->GetEntries(); ievt++) {

	      if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

	      data->GetEntry(ievt);
	      output = reader->EvaluateMVA( "MLP method");

	      output_tree->Fill();
	      histNn->Fill(output);
	   }

	   // Get elapsed time
	   sw.Stop();
	   std::cout << "--- End of event loop: "; sw.Print();

	   // --- Write histograms
    data->AddFriend(output_tree);
	   TFile* target  = new TFile( "TMVApp.root","RECREATE" );
	   target->cd();
	   data->CloneTree()->Write();
	   histNn->Write();

	   target->Close();

	   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;

	   delete reader;

	   std::cout << "==> TMVAClassificationApplication is done!" << std::endl;

	   return output_tree;
}

//note before calling this method you must call create_MLP to update the xml weight file:
//
DataChain* MLPAnalysis::get_MLP_results(DataChain* bg_chain, std::vector<Variable*>* variables, std::string var_cut_str, const char* NeuronType, const char* NCycles, const char* HiddenLayers)
{
	 TTree* output_weight = MLPAnalysis::evaluate_MLP(bg_chain, variables, NeuronType,  NCycles, HiddenLayers);
	 TChain* bg_clone     = (TChain*) bg_chain->chain->Clone();

	 bg_clone->AddFriend(output_weight);

	 std::string label(bg_chain->label);
	 label += "_w_mva_output";
	 DataChain* output_data = new DataChain(z_ll, bg_chain->label, bg_chain->legend, bg_chain->lep_sel, label, bg_clone);

	 return output_data;
}

std::string MLPAnalysis::MLP_options_str(const char* NeuronType, const char* NCycles, const char* HiddenLayers)
{
	std::string MLP_options = "H:!V:NeuronType=";
	std::string nt = NeuronType;
	std::string nc = NCycles;
	std::string hl = HiddenLayers;
	MLP_options.append(nt);
	MLP_options += ":VarTransform=N:NCycles=";
	MLP_options.append(nc);
	MLP_options += ":HiddenLayers=";
	MLP_options.append(hl);
	MLP_options += ":TestRate=5:!UseRegulator";
        return MLP_options;
}

std::string MLPAnalysis::MLP_output_name_str(const char* NeuronType, const char* NCycles, const char* HiddenLayers)
{
	std::string nt = NeuronType;
	std::string nc = NCycles;
	std::string hl = HiddenLayers;

	std::string out_nam = "MLP-NeuronType=";
	out_nam.append(nt);
	out_nam += "-NCycles=";
	out_nam.append(nc);
	out_nam += "-HiddenLayers=";
	out_nam.append(hl);
	out_nam += ".root";

	return out_nam;
}

