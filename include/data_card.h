#ifndef data_card_h
#define data_card_h

#include "mva_analysis.h"
#include <fstream>

class DataCard
{
 public:
  static double get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static double* get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains,
                               Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static double get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                          Variable* var, bool with_cut, std::vector<Variable*>* variables);

  static int test();
};

#endif
