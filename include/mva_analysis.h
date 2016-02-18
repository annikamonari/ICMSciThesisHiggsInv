#ifndef Mva_Analysis_h
#define Mva_Analysis_h

#include "roc_curves.h"
#include "classifier_outputs.h"

class MVAAnalysis
{
 public:
	 static TH1F* plot_output(DataChain* combined_data);

  static std::vector<double> get_categories(TH1F* output_histo);

  static std::vector<std::string> get_category_strs(std::vector<double> categories);

  static TH1F* build_histo(DataChain* combined_output, std::string selection_str, Variable* variable, std::string histo_label);

  static std::string build_output_sel_str(std::string category, std::string final_cuts);

  static TH1F* draw_signal(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable);

  static TH1F* draw_background(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable);

  static void style_histo(TH1F* histo);

  static void draw_histo(DataChain* combined_output, std::string final_cuts, Variable* variable);
//----------------------------------------------------------------------------------------------------
  static std::vector<const char*> vary_parameters(std::vector<DataChain*> bg_chains, int bg_to_train, 
                              DataChain* signal_chain, DataChain* data_chain, SuperVars* super_vars,
																														std::string method_name, std::string dir_name, std::vector<const char*> NTrees, 
                              std::vector<const char*> BoostType,	std::vector<const char*> AdaBoostBeta, 
                              std::vector<const char*> SeparationType, std::vector<const char*> nCuts,
																														std::vector<const char*> NeuronType, std::vector<const char*> NCycles, 
                              std::vector<const char*> HiddenLayers, std::string mva_cut_str="");
//----------------------------------------------------------------------------------------------------

  static void get_plots_varying_params(std::vector<DataChain*> bg_chains, int bg_to_train,
                             DataChain* signal_chain, DataChain* data_chain, SuperVars* super_vars,
																													std::string method_name, std::string dir_name, std::vector<const char*> NTrees,
                             std::vector<const char*> BoostType,	std::vector<const char*> AdaBoostBeta, 
                             std::vector<const char*> SeparationType, std::vector<const char*> nCuts,
																													std::vector<const char*> NeuronType, std::vector<const char*> NCycles, 
                             std::vector<const char*> HiddenLayers,std::string mva_cut_str);
//----------------------------------------------------------------------------------------------------

  static std::vector<TFile*> get_files_from_paths(std::vector<const char*> file_paths);
//----------------------------------------------------------------------------------------------------

  static TFile* get_mva_results(std::vector<DataChain*> bg_chains, int bg_to_train, DataChain* signal_chain, 
                              DataChain* data_chain,	SuperVars* super_vars, std::string folder_name, 
                              std::string method_name, const char* NTrees = "800",
                              const char* BoostType = "AdaBoost", const char* AdaBoostBeta = "0.2", 
                              const char* SeparationType = "GiniIndex",const char* nCuts = "30",  
                              const char* NeuronType = "sigmoid", const char* NCycles = "500",
																														const char* HiddenLayers = "5,5,5,5", std::string mva_cut_str="");

  static std::vector<DataChain*> get_output_bg_chains(std::vector<DataChain*> bg_chains, std::vector<Variable*> vars, std::string method_name,
																																																						TFile* training_output);

  static DataChain* get_output_signal_chain(DataChain* signal_chain, std::vector<Variable*> vars, std::string method_name, TFile* training_output);

  static std::string build_output_graph_name(TFile* trained_output);

};








#endif
