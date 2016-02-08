#ifndef Mva_Analysis_h
#define Mva_Analysis_h

#include "../include/roc_curves.h"

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

  static void plot_bdt_results(std::vector<DataChain*> bg_chains, DataChain* signal_chain, DataChain* data_chain, SuperVars* super_vars);

  static std::vector<DataChain*> get_output_bg_chains(std::vector<DataChain*> bg_chains, std::vector<Variable*> vars, std::string var_cut_str_tmva);

  static DataChain* get_output_signal_chain(DataChain* signal_chain, std::vector<Variable*> vars, std::string var_cut_str_tmva);
};








#endif
