#ifndef Mva_Analysis_h
#define Mva_Analysis_h

#include "../include/bdt_analysis.h"

class MVAAnalysis
{
 public:
	 static TH1F* plot_output(DataChain* combined_data);

  static std::vector<double> get_categories(TH1F* output_histo);


  static std::vector<std::string> get_category_strs(std::vector<double> categories);

  static TH1F* build_histo(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable);

  static TH1F* draw_signal(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable);

  static TH1F* draw_background(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable);

  static void draw_histo(DataChain* combined_output, std::string final_cuts, Variable* variable);

  static void plot_bdt_results(DataChain* bg_chain, DataChain* signal_chain, SuperVars* super_vars);
};








#endif
