#ifndef data_card_h
#define data_card_h

#include "mva_analysis.h"

class DataCard
{

  static double get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<double> get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains,
                               Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<double> get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                          Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static std::vector<int> bin_line(std::vector<DataChain*> bg_chains);
};

#endif
