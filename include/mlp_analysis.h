#ifndef Mlp_Analysis_h
#define Mlp_Analysis_h

#include "../include/histo_plot.h"
#include "../include/mc_weights.h"

#include <cstdlib>
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
	 

	 static TFile* create_MLP(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables, std::string folder_name,
																									const char* NeuronType, const char* NCycles, const char* HiddenLayers, const char* preprocessing_transform="N", const char* LearningRate="0.02", const char* console_number="1");

	 static TTree* evaluate_MLP(DataChain* bg_chain,std::vector<Variable*>* variables, const char* training_output_name, const char* console_number);

	 static DataChain* get_MLP_results(DataChain* bg_chain, std::vector<Variable*>* variables, const char* training_output_name, const char* console_number);

  static std::string MLP_options_str(const char* NeuronType, const char* NCycles, const char* HiddenLayers, const char* preprocessing_transform="N", const char* LearningRate="0.02");
	
	 static std::string MLP_output_name_str(const char* NeuronType, const char* NCycles,
																																									const char* HiddenLayers, const char* bg_chain_label, const char* preprocessing_transform, const char* LearningRate="0.02");

};








#endif
