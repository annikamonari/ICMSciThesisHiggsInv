#ifndef super_chains_h
#define super_chains_h

#include "../include/super_vars.h"

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

  SuperChains();

  std::vector<DataChain*> get_bg_chains();

};



#endif
