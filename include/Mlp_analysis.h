#ifndef Mlp_Analysis_h
#define Mlp_Analysis_h

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

class MLPAnalysis
{
 public:
	 

	 static void create_MLP(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables, std::string var_cut_str,const char* NeuronType, const char* NCycles, const char* HiddenLayers);

	static TTree* evaluate_MLP(DataChain* bg_chain,std::vector<Variable*>* variables);


	static DataChain* get_MLP_results(DataChain* bg_chain, std::vector<Variable*>* variables, std::string var_cut_str, const char* NeuronType, const char* NCycles, const char* HiddenLayers);

        static std::string MLP_options_str(const char* NeuronType, const char* NCycles, const char* HiddenLayers);
	
	static std::string MLP_output_name_str(const char* NeuronType, const char* NCycles, const char* HiddenLayers);

};








#endif
