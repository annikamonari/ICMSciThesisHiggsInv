#ifndef data_card_h
#define data_card_h

#include "mva_analysis.h"
#include <fstream>

class DataCard
{
 public:
  static double get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<double> get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
                               Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<double> get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
  							                                 Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<int> process_line_2(std::vector<DataChain*> bg_chains);

  static int test();

  static std::vector<int> bin_line(std::vector<DataChain*> bg_chains);

  static std::string int_to_str(int sint);

  static std::string jmax_string(int jmax);

  static std::string imax_string(int imax);

  static std::string kmax_string(int kmax);

  static std::string bin_header_string();

  static std::string bin_observation_string(int nbins);

  static std::string bin_grid_line(int cols);

  static std::string process_labels(std::vector<DataChain*> bg_chains, DataChain* signal_chain);

  static std::string dashed_line();

  static std::string process_2_string(std::vector<int> line_2_vals);

  static std::string rate_string(std::vector<double> rates);

  static std::vector<double> get_zeros(int size);

  static std::vector<std::vector<double> > get_uncertainty_vectors(double signal_error, std::vector<double> bg_errors);
};

#endif
