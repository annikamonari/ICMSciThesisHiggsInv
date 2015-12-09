#ifndef Mc_Weights_h
#define Mc_Weights_h

#include "histo_plot.h"

class MCWeights
{
 public:
	 static std::string get_mc_selection_str(DataChain* bg_chain, Variable* variable, std::vector<Variable*>* variables);

	 static double get_nevents(DataChain* chain_of_data, Variable* var, bool with_cut,
				                        std::vector<Variable*>* variables, std::string selection);

	 static double get_all_bg_in_ctrl(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
							                            std::vector<Variable*>* variables, std::string selection);

	 static double calc_mc_weight(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
	Variable* var,	bool with_cut, std::vector<Variable*>* variables);

	static TH1F* build_histo(DataChain* data_chain, Variable* variable,std::vector<Variable*>* variables, bool with_cut, bool is_signal,const char* option,std::string selection);

	static std::string get_selection(Variable* variable, std::vector<Variable*>* variables,bool with_cut, bool is_signal, DataChain* bg_chain);

static std::string lep_sel_default()
  {
    return "(nvetomuons == 0)&&(nvetoelectrons == 0)";
  }



};



#endif
