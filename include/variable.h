#ifndef Variable_h
#define Variable_h

#include "../include/analysis.h"

class Variable {
public:
  const char* name;
  const char* name_styled;
  const char* signal_multiplier;
  const char* bins_nocut;
  const char* x_min_nocut;
  const char* x_max_nocut;
  bool abs_for_cut;
  std::string bins_cut;
  const char* x_min_cut;
  const char* x_max_cut;
  

  Variable(const char* var_name, const char* var_name_styled, const char* x_min,
											const char* x_max, const char* x_min_c, const char* x_max_c,
											const char* nbins, const char* xsignal, bool abs_val_for_cuts = false);
  
  std::string scale_bins_for_cut();

  std::string build_var_string(const char* label, bool with_cut);

  std::string build_multicut_selection(bool is_signal, std::vector<Variable*>* variables, std::string control_sel);

  std::string build_selection_string(bool with_cut, bool is_signal, std::string control_sel);

  std::string build_selection(const char* var_name, const char* x_min_cut,
																														const char* x_max_cut, bool abs_for_cut);

  std::string build_single_selection(const char* var_name, const char* op, const char* val,
																																					bool abs_for_cut)

  double get_graph_dx(bool with_cut);

  double get_x_min(bool with_cut);

  double get_x_max(bool with_cut);

  double get_bins(bool with_cut);
};


#endif
