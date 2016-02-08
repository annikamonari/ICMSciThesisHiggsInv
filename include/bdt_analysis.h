#ifndef Bdt_Analysis_h
#define Bdt_Analysis_h

#include "../include/histo_plot.h"
#include "../include/mc_weights.h"

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

class BDTAnalysis
{
 public:
	 

	 static DataChain* get_BDT_results(DataChain* bg_chain, std::vector<Variable*>* variables,std::string var_cut_str);


	static std::string BDT_options_str(const char* NTrees,const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char*nCuts);

	static std::string BDT_output_name_str(const char* NTrees,const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char*nCuts);

 static TFile* create_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables,std::string var_cut_str,const char* NTrees,
                        const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char* nCuts);

	 static TTree* evaluate_BDT(DataChain* bg_chain, std::vector<Variable*>* variables);

};








#endif
