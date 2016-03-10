#include "../include/bdt_analysis.h"

TFile* BDTAnalysis::create_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables,
																															std::string folder_name, const char* NTrees,const char* BoostType,
																															const char* AdaBoostBeta,const char* SeparationType,const char* nCuts, const char* console_number)
{
	  if (!opendir(folder_name.c_str()))
	  {
	    mkdir(folder_name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	  }

	  std::string output_path(folder_name);
	  output_path.append("/");
	  output_path.append(BDT_output_name_str(NTrees,BoostType,AdaBoostBeta,SeparationType,nCuts, bg_chain->label));
	  TFile* output_tmva = TFile::Open(output_path.c_str(),"RECREATE");

          std::string cn = console_number;
          std::string TMVAClassification_str = "TMVAClassification" + cn;
          const char* TMVAClassification_id = TMVAClassification_str.c_str();
          TMVA::Factory* factory = new TMVA::Factory(TMVAClassification_id, output_tmva,
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
	    TCut signal_cuts = "alljetsmetnomu_mindphi>2.0 && alljetsmetnomu_mindphi<3.0 && jet1_pt>50.0 && jet2_pt>45.0 && metnomu_significance>3.5 && dijet_deta>4.2 && dijet_deta<8.0 && nvetomuons==0 && nvetoelectrons==0"; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
	    TCut bg_cuts = signal_cuts; // for example: TCut mycutb = "abs(var1)<0.5";

	    factory->PrepareTrainingAndTestTree(signal_cuts, bg_cuts,
	    				       "SplitMode=Random:NormMode=NumEvents:!V" );
 
    factory->BookMethod(TMVA::Types::kBDT, "BDT", BDT_options_str(NTrees,BoostType,AdaBoostBeta,SeparationType,nCuts));

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

TTree* BDTAnalysis::evaluate_BDT(DataChain* bg_chain, std::vector<Variable*>* variables, const char* training_output_name,const char* console_number)
{
	   TMVA::Reader* reader = new TMVA::Reader( "!Color:!Silent" );

	   Float_t dijet_deta;
	   Float_t forward_tag_eta;
	   Float_t metnomu_significance;
	   Float_t sqrt_ht;
	   Float_t alljetsmetnomu_mindphi;
	   Float_t dijet_M;
	   Float_t metnomuons;

           Float_t jet1_pt;
           Float_t jet2_pt;

           Float_t jet1_E;
           Float_t jet2_E;   
           Float_t jet1_eta;
           Float_t jet2_eta;
           Float_t jet1_phi;
           Float_t jet2_phi;
           Float_t jet_csv1;
           Float_t jet_csv2;
           Float_t dijet_dphi;
           Float_t metnomu_x;
           Float_t metnomu_y;
           Float_t sumet;
           Float_t mht;
           Float_t unclustered_et;
           Float_t jetmet_mindphi;
           Float_t jetmetnomu_mindphi;
           Float_t jetunclet_mindphi;
           Float_t metnomuunclet_dphi;
           Float_t dijetmetnomu_vectorialSum_pt;
           Float_t dijetmetnomu_ptfraction;
           Float_t jet1metnomu_scalarprod;
           Float_t jet2metnomu_scalarprod;
           Float_t n_jets_cjv_30;
           Float_t n_jets_cjv_20EB_30EE;
           Float_t n_jets_15;
           Float_t n_jets_30;
           Float_t cjvjetpt;
           Float_t l1met;
           Float_t n_vertices;

	   reader->AddVariable("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
	   reader->AddVariable("forward_tag_eta", &forward_tag_eta);
	   reader->AddVariable("dijet_deta", &dijet_deta);
	   reader->AddVariable("metnomu_significance", &metnomu_significance);
	   reader->AddVariable("sqrt_ht", &sqrt_ht);
	   reader->AddVariable("dijet_M", &dijet_M);
	   reader->AddVariable("metnomuons", &metnomuons);

           reader->AddVariable("jet1_pt", &jet1_pt);
           reader->AddVariable("jet2_pt", &jet2_pt);

           reader->AddVariable("jet1_E", &jet1_E);
           reader->AddVariable("jet2_E", &jet2_E);
           reader->AddVariable("jet1_eta", &jet1_eta);
           reader->AddVariable("jet2_eta", &jet2_eta);
           reader->AddVariable("jet1_phi", &jet1_phi);
           reader->AddVariable("jet2_phi", &jet2_phi);
           reader->AddVariable("jet_csv1", &jet_csv1);
           reader->AddVariable("jet_csv2", &jet_csv2);
           reader->AddVariable("dijet_dphi", &dijet_dphi);
           reader->AddVariable("metnomu_x", &metnomu_x);
           reader->AddVariable("metnomu_y", &metnomu_y);
           reader->AddVariable("sumet", &sumet);
           reader->AddVariable("mht", &mht);
           reader->AddVariable("unclustered_et", &unclustered_et);
           reader->AddVariable("jetmet_mindphi", &jetmet_mindphi);
           reader->AddVariable("jetmetnomu_mindphi", &jetmetnomu_mindphi);
           reader->AddVariable("jetunclet_mindphi", &jetunclet_mindphi);
           reader->AddVariable("metnomuunclet_dphi", &metnomuunclet_dphi);
           reader->AddVariable("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt);
           reader->AddVariable("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction);
           reader->AddVariable("jet1metnomu_scalarprod", &jet1metnomu_scalarprod);
           reader->AddVariable("jet2metnomu_scalarprod", &jet2metnomu_scalarprod);
           reader->AddVariable("n_jets_cjv_30", &n_jets_cjv_30);
           reader->AddVariable("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE);
           reader->AddVariable("n_jets_15", &n_jets_15);
           reader->AddVariable("n_jets_30", &n_jets_30);
           reader->AddVariable("cjvjetpt", &cjvjetpt);
           reader->AddVariable("l1met", &l1met);
           reader->AddVariable("n_vertices", &n_vertices);
	   // Book method(s)
	   std::string cn = console_number;
           std::string weight_path_str = "weights/TMVAClassification" + cn + "_BDT.weights.xml";
           const char* weight_path = weight_path_str.c_str();

	   reader->BookMVA( "BDT method", weight_path );

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

           data->SetBranchAddress("jet1_pt", &jet1_pt);
           data->SetBranchAddress("jet2_pt", &jet2_pt);

           data->SetBranchAddress("jet1_E", &jet1_E);
           data->SetBranchAddress("jet2_E", &jet2_E);
           data->SetBranchAddress("jet1_eta", &jet1_eta);
           data->SetBranchAddress("jet2_eta", &jet2_eta);
           data->SetBranchAddress("jet1_phi", &jet1_phi);
           data->SetBranchAddress("jet2_phi", &jet2_phi);
           data->SetBranchAddress("jet_csv1", &jet_csv1);
           data->SetBranchAddress("jet_csv2", &jet_csv2);
           data->SetBranchAddress("dijet_dphi", &dijet_dphi);
           data->SetBranchAddress("metnomu_x", &metnomu_x);
           data->SetBranchAddress("metnomu_y", &metnomu_y);
           data->SetBranchAddress("sumet", &sumet);
           data->SetBranchAddress("mht", &mht);
           data->SetBranchAddress("unclustered_et", &unclustered_et);
           data->SetBranchAddress("jetmet_mindphi", &jetmet_mindphi);
           data->SetBranchAddress("jetmetnomu_mindphi", &jetmetnomu_mindphi);
           data->SetBranchAddress("jetunclet_mindphi", &jetunclet_mindphi);
           data->SetBranchAddress("metnomuunclet_dphi", &metnomuunclet_dphi);
           data->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt);
           data->SetBranchAddress("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction);
           data->SetBranchAddress("jet1metnomu_scalarprod", &jet1metnomu_scalarprod);
           data->SetBranchAddress("jet2metnomu_scalarprod", &jet2metnomu_scalarprod);
           data->SetBranchAddress("n_jets_cjv_30", &n_jets_cjv_30);
           data->SetBranchAddress("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE);
           data->SetBranchAddress("n_jets_15", &n_jets_15);
           data->SetBranchAddress("n_jets_30", &n_jets_30);
           data->SetBranchAddress("cjvjetpt", &cjvjetpt);
           data->SetBranchAddress("l1met", &l1met);
           data->SetBranchAddress("n_vertices", &n_vertices);

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
    std::string target_name = training_output_name;
    std::string bg_chain_name = bg_chain->label;
    std::string target_file = target_name.insert(target_name.find("/") + 1, bg_chain_name + "App_");


    const char* tar_fil = target_file.c_str();	   

	   TFile* target  = new TFile(/*"TMVApp1.root"*/target_file.c_str(),"RECREATE" );	   target->cd();
	   data->CloneTree()->Write();
	   histBdt->Write();

	   target->Close();

	   std::cout << "--- Created root file: "<<"TMVApp1.root"<< "containing the MVA output histograms" << std::endl;

	   delete reader;

	   std::cout << "==> TMVAClassificationApplication is done!" << std::endl;

	   return output_tree;
}

//note before calling this method you must call create_bdt to update the xml weight file:
DataChain* BDTAnalysis::get_BDT_results(DataChain* bg_chain, std::vector<Variable*>* variables, const char* training_output_name, const char* console_number)
{
         TTree* output_weight = BDTAnalysis::evaluate_BDT(bg_chain, variables, training_output_name, console_number);

	 TTree* output_weight_clone = (TTree*) output_weight->Clone();
	 TChain* bg_clone     = (TChain*) bg_chain->chain->Clone();

	 bg_clone->AddFriend(output_weight_clone);

	 std::string label(bg_chain->label);
	 label += "_w_mva_output";

  DataChain* output_data = new DataChain(z_ll, bg_chain->label, bg_chain->legend, bg_chain->lep_sel, label, bg_clone);

	 return output_data;
}

std::string BDTAnalysis::BDT_options_str(const char* NTrees, const char* BoostType,
																																									const char* AdaBoostBeta, const char* SeparationType, const char* nCuts)
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

std::string BDTAnalysis::BDT_output_name_str(const char* NTrees, const char* BoostType,const char* AdaBoostBeta,
																																													const char* SeparationType, const char* nCuts, const char* bg_chain_label)
{
 std::string bg = bg_chain_label;
	std::string out_nam = "BDT-" + bg + "-NTrees=";
	out_nam.append(NTrees);
	out_nam += "-BoostType=";
	out_nam.append(BoostType);
	out_nam += "-AdaBoostBeta=";
	out_nam.append(AdaBoostBeta);
	out_nam += "-SeparationType=";
	out_nam.append(SeparationType);
	out_nam += "-nCuts=";
	out_nam.append(nCuts);
	out_nam += ".root";

	return out_nam;
}


