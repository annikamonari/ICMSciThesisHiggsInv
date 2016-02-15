#ifndef data_card_h
#define data_card_h

#include "mva_analysis.h"

#include <fstream>

class DataCard
{
 public:
  static double get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string mva_cut_str);

  static std::vector<double> get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
                               Variable* var, bool with_cut, std::vector<Variable*>* variables, std::vector<double> bg_mc_weights, std::string mva_cut_str);

  static std::vector<double> get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
  							                              Variable* var, bool with_cut, std::vector<Variable*>* variables, std::vector<double> bg_mc_weights,std::string mva_cut_str);

  static std::vector<int> process_line_2(int size);

  static int test();

  static std::vector<int> bin_line(std::vector<DataChain*> bg_chains);

  static std::string double_to_str(double sint);

  static std::string jmax_string(int jmax);

  static std::string imax_string();

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

  static std::string get_single_uncertainty_str(std::vector<double> single_uncertainty_vector);

  static std::string get_uncertainties_string(std::vector<std::vector<double> > uncertainty_vectors);

  static void create_datacard(DataChain* data_chain, DataChain* signal_chain, std::vector<DataChain*> bg_chains,

																														Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string mva_cut_str="",

																														TFile* training_output = NULL);

  static double get_total_nevents(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut, 
std::vector<Variable*>* variables,
																																		std::vector<double> bg_mc_weights, std::string mva_cut_str);

  static std::string get_systematic_string(DataChain* data, std::vector<DataChain*> bg_chains,
																																											DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables,
																																											std::vector<double> bg_mc_weights, std::string mva_cut_str);

  static std::string no_shape_line();

  static const char* get_data_card_name(TFile* training_output);
};

#endif

