#ifndef Super_Chains_h
#define Super_Chains_h

#include "../include/super_vars.h"
#include "../include/mc_weights.h"

class SuperChains {
public:
		DataChain* bg_zll;
		DataChain* bg_wjets_ev;
		DataChain* bg_wjets_muv;
		DataChain* bg_wjets_tauv;
		DataChain* bg_top;
		DataChain* bg_vv;
		DataChain* bg_zjets_vv;
		DataChain* bg_qcd;
		DataChain* signal_chain;
		DataChain* data_chain;
		std::map<const char*, std::map<const char*, double> > mc_weights;

  SuperChains(std::vector<Variable*>* discriminating_vars,
														std::vector<Variable*>* cut_vars,
														bool with_cut);

  std::vector<DataChain*> get_bg_chains();


  std::map<const char*, std::map<const char*, double> > build_mc_weight_map(std::vector<Variable*>* discriminating_vars,
		  																																																																							std::vector<Variable*>* cut_vars,
				  																																																																					bool with_cut);

  std::map<const char*, double> get_var_mc_weights(DataChain* bg_chain, std::vector<Variable*>* vars,
						  																																											std::vector<Variable*>* cut_vars, bool with_cut);

  std::map<const char*, std::map<const char*, double> > set_bg_zjets_vv_weights(std::map<const char*, std::map<const char*,
  																																																																														double> > mc_weights,
  																																																																														std::vector<Variable*>* vars);

  void set_chain_mc_weights();

};

#endif
