#include "../include/bdt_analysis.h"

void BDTAnalysis::create_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables, std::string var_cut_str)
{
  // --- Here the preparation phase begins
  // Create a ROOT output file where TMVA will store ntuples, histograms, etc.

	 std::string output_folder(bg_chain->label);
  TFile* output_tmva = TFile::Open((output_folder + "/TMVA_signalSel.root").c_str(),"RECREATE");

  // Create the factory object. Later you can choose the methods
  // whose performance you'd like to investigate. The factory is
  // the only TMVA object you have to interact with
  //
  // The first argument is the base of the name of all the
  // weight files in the directory weight/
  //
  // The second argument is the output file for the training results
  // All TMVA output can be suppressed by removing the "!" (not) in
  // front of the "Silent" argument in the option string

  TMVA::Factory* factory = new TMVA::Factory("TMVAClassification", output_tmva,
                                             "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
  // Adding Variables
  // If you wish to modify default settings
  // (please check "src/Config.h" to see all available global options)
  //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
  //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

  // Define the input variables that shall be used for the MVA training
  // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
  // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
  // factory->AddVariable( "myvar1 := var1+var2", 'F' );
  // factory->AddVariable( "myvar2 := var1-var2", "Expression 2", "", 'F' );

  // You can add so-called "Spectator variables", which are not used in the MVA training,
  // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
  // input variables, the response values of all trained MVAs, and the spectator variables
  // factory->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
  // factory->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );

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
  TCut signal_cuts = var_cut_str.c_str(); // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
  TCut bg_cuts = signal_cuts; // for example: TCut mycutb = "abs(var1)<0.5";

  factory->PrepareTrainingAndTestTree(signal_cuts, bg_cuts,
  				       "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );
  // ---- Book MVA methods
  //
  // Please lookup the various method configuration options in the corresponding cxx files, eg:
  // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
  // it is possible to preset ranges in the option string in which the cut optimisation should be done:
  // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable
  // FOR BDTS:

  factory->BookMethod(TMVA::Types::kBDT, "BDT",
                      "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");

  // If you wish to modify default settings
  // (please check "src/Config.h" to see all available global options)
  //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
  //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

  // Define the input variables that shall be used for the MVA training
  // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
  // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]


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

  gROOT->ProcessLine(".L TMVAGui.C");

  delete factory;
}

void BDTAnalysis::evaluate_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables)
{
	// --- Create the Reader object

	   TMVA::Reader* reader = new TMVA::Reader( "!Color:!Silent" );

	   // Create a set of variables and declare them to the reader
	   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used

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

	   // Spectator variables declared in the training have to be added to the reader, too
	   /*Float_t spec1,spec2;
	   reader->AddSpectator( "spec1 := var1*2",   &spec1 );
	   reader->AddSpectator( "spec2 := var1*3",   &spec2 );*/

	   /*Float_t Category_cat1, Category_cat2, Category_cat3;
	   if (Use["Category"]){
	      // Add artificial spectators for distinguishing categories
	      reader->AddSpectator( "Category_cat1 := var3<=0",             &Category_cat1 );
	      reader->AddSpectator( "Category_cat2 := (var3>0)&&(var4<0)",  &Category_cat2 );
	      reader->AddSpectator( "Category_cat3 := (var3>0)&&(var4>=0)", &Category_cat3 );
	   }*/

	   // --- Book the MVA methods

	   // Book method(s)
	   reader->BookMVA( "BDT method", "weights/TMVAClassification_BDT.weights.xml" );

	   // Book output histograms
	   TH1F* histBdt     = new TH1F( "MVA_BDT", "MVA_BDT", 100, -1.0, 1.0 );

	   // Prepare input tree (this must be replaced by your data source)


	   // --- Event loop

	   // Prepare the event tree
	   // - here the variable names have to corresponds to your tree
	   // - you can use the same variables as above which is slightly faster,
	   //   but of course you can use different ones and copy the values inside the event loop
	   //
	   /*std::cout << "--- Select signal sample" << std::endl;
	   TTree* theTree = (TTree*)input->Get("TreeS");
	   Float_t userVar1, userVar2;
	   theTree->SetBranchAddress( "var1", &userVar1 );
	   theTree->SetBranchAddress( "var2", &userVar2 );
	   theTree->SetBranchAddress( "var3", &var3 );
	   theTree->SetBranchAddress( "var4", &var4 );*/

	   Float_t output;
	   TTree* output_tree = new TTree("MVAtree","Tree with classifier outputs");
	   output_tree -> Branch("output", &output, "output");

	   TChain* data = signal_chain->chain;
	   data->Add(bg_chain->chain);

	   data->SetBranchAddress("dijet_deta", &dijet_deta);
	   data->SetBranchAddress("forward_tag_eta", &forward_tag_eta);
	   data->SetBranchAddress("metnomu_significance", &metnomu_significance);
	   data->SetBranchAddress("sqrt_ht", &sqrt_ht);
	   data->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
	   data->SetBranchAddress("dijet_M", &dijet_M);
	   data->SetBranchAddress("metnomuons", &metnomuons);

	   std::vector<Float_t> vecVar(9); // vector for EvaluateMVA tests

	   std::cout << "--- Processing: " << data->GetEntries() << " events" << std::endl;
	   TStopwatch sw;
	   sw.Start();
	   for (Long64_t ievt=0; ievt<data->GetEntries(); ievt++) {

	      if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;

	      data->GetEntry(ievt);

	      //var1 = userVar1 + userVar2;
	      //var2 = userVar1 - userVar2;

	      // --- Return the MVA outputs and fill into histograms

	      output = reader->EvaluateMVA( "BDT method" );
	      output_tree->Fill();
	      histBdt->Fill(output);
	   }

	   // Get elapsed time
	   sw.Stop();
	   std::cout << "--- End of event loop: "; sw.Print();

	   // --- Write histograms

	   TFile *target  = new TFile( "TMVApp.root","RECREATE" );
	   target->cd();
	   output_tree->Write();
	   histBdt->Write();

	   target->Close();

	   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;

	   delete reader;

	   std::cout << "==> TMVAClassificationApplication is done!" << std::endl;
}
