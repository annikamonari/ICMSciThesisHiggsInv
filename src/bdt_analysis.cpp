#include "../include/bdt_analysis.h"

TFile* BDTAnalysis::create_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables, std::string var_cut_str,const char* NTrees,const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char* nCuts)
{
  std::string output_folder(bg_chain->label);
  output_folder.append("/");
  std::string output_file;

  output_file = BDT_output_name_str(NTrees,BoostType,AdaBoostBeta,SeparationType,nCuts);
  output_file.append(".root");
  output_folder.append(output_file);
  const char* name = output_folder.c_str();
  TFile* output_tmva = TFile::Open(name,"RECREATE");

 // TFile* output_tmva = TFile::Open((output_folder + "/TMVA_signalSel2.root").c_str(),"RECREATE");

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

  std::cout<<"bdt options"<<BDT_options_str(NTrees,BoostType,AdaBoostBeta,SeparationType,nCuts)<<"\n";
 
 factory->BookMethod(TMVA::Types::kBDT, BDT_options_str(NTrees,BoostType,AdaBoostBeta,SeparationType,nCuts));/*"BDT","!H:!V:NTrees=800:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.2:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");*/

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

  delete factory;

  return output_tmva;
}

TTree* BDTAnalysis::evaluate_BDT(DataChain* bg_chain, std::vector<Variable*>* variables)
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
	   reader->BookMVA( "BDT method", "weights/TMVAClassification_BDT.weights.xml" );

	   // Book output histograms
	   TH1F* histBdt     = new TH1F( "MVA_BDT", "MVA_BDT", 100, -0.8, 0.8 );

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

	      output = reader->EvaluateMVA( "BDT method" );
	      output_tree->Fill();
	      histBdt->Fill(output);
	   }

	   // Get elapsed time
	   sw.Stop();
	   std::cout << "--- End of event loop: "; sw.Print();

	   // --- Write histograms
    data->AddFriend(output_tree);
	   TFile* target  = new TFile( "TMVApp.root","RECREATE" );
	   target->cd();
	   data->CloneTree()->Write();
	   histBdt->Write();

	   target->Close();

	   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;

	   delete reader;

	   std::cout << "==> TMVAClassificationApplication is done!" << std::endl;

	   return output_tree;
}

//note before calling this method you must call create_bdt to update the xml weight file:
DataChain* BDTAnalysis::get_BDT_results(DataChain* bg_chain, std::vector<Variable*>* variables, std::string var_cut_str)
{
	 TTree* output_weight = BDTAnalysis::evaluate_BDT(bg_chain, variables);
	 TChain* bg_clone     = (TChain*) bg_chain->chain->Clone();

	 bg_clone->AddFriend(output_weight);

	 std::string label(bg_chain->label);
	 label += "_w_mva_output";
	 std::vector<const char*> file_path;

         if(!strcmp(bg_chain->label,"bg_zll")){file_path = z_ll;}
         else if(!strcmp(bg_chain->label,"bg_wjets_ev")){file_path = wjets_ev;}
         else if(!strcmp(bg_chain->label,"bg_wjets_muv")){file_path = wjets_muv;}
         else if(!strcmp(bg_chain->label,"bg_wjets_tauv")){file_path = wjets_tauv;}
         else if(!strcmp(bg_chain->label,"bg_top")){file_path = top;}
         else if(!strcmp(bg_chain->label,"bg_vv")){file_path = vv;}
         else if(!strcmp(bg_chain->label,"bg_zjets_vv")){file_path = zjets_vv;}
         else if(!strcmp(bg_chain->label,"bg_qcd")){file_path = qcd;}
	 else{std::cout<<"error background label not found in get_BDT_results"<<"\n";}

         DataChain* output_data = new DataChain(file_path, bg_chain->label, bg_chain->legend, bg_chain->lep_sel, label, bg_clone);

	 return output_data;
}

std::string BDTAnalysis::BDT_options_str(const char* NTrees,const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char*nCuts)
{
	std::string BDT_options = "!H:!V:NTrees=";
	BDT_options.append(NTrees);
	BDT_options += ":MinNodeSize=2.5%:MaxDepth=3:BoostType=";
	BDT_options.append(BoostType);
	BDT_options += ":AdaBoostBeta=";
	BDT_options.append(AdaBoostBeta);
	BDT_options += ":UseBaggedBoost:BaggedSampleFraction=";
	BDT_options.append(AdaBoostBeta);
	BDT_options += ":SeparationType=";
	BDT_options.append(SeparationType);
	BDT_options += ":nCuts=";
	BDT_options.append(nCuts);

        return BDT_options;
}

std::string BDTAnalysis::BDT_output_name_str(const char* NTrees,const char* BoostType,const char* AdaBoostBeta,const char* SeparationType, const char* nCuts)
{

	std::string out_nam = "BDT-NTrees=";
	out_nam.append(NTrees);
	out_nam += "-BoostType=";
	out_nam.append(BoostType);
	out_nam += "-AdaBoostBeta=";
	out_nam.append(AdaBoostBeta);
	out_nam += "-SeparationType=";
	out_nam.append(SeparationType);
	out_nam += "-nCuts=";
	out_nam.append(nCuts);
	return out_nam;
}
