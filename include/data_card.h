#ifndef data_card_h
#define data_card_h

class data_card
{
  static double get_signal_error(DataChain* signal_chain,ariable* var, bool with_cut, std::vector<Variable*>* variables);
};

#endif
