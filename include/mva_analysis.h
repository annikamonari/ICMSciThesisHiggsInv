#ifndef Mva_Analysis_h
#define Mva_Analysis_h

#include "../include/bdt_analysis.h"

class MVAAnalysis
{
 public:
  static std::vector<double> get_categories(std::vector<double> x_range);

  static std::vector<double> get_x_range(TH1F* output_histo);

  static std::vector<std::string> get_category_strs(std::vector<double> categories);

  static TH1F* build_histo(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																											std::vector<Variable*>* variables, DataChain* bg_chain);

  static TH1F* draw_signal(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																																								std::vector<Variable*>* variables, DataChain* bg_chain);

  static TH1F* draw_background(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																																												std::vector<Variable*>* variables, DataChain* bg_chain);

  static void draw_histo(Variable* variable, TChain* data, std::vector<Variable*>* variables, DataChain* bg_chain);
};








#endif
