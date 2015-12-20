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
    factory->AddVariable((*variables)[i]->name, (*variables)[i]->name_styled, (*variables)[i]->units,
																									'F', atof((*variables)[i]->x_min_cut), atof((*variables)[i]->x_max_cut));
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

  delete factory;
}
