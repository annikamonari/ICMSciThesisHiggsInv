#ifndef Super_Chains_h
#define Super_Chains_h

#include "../include/super_vars.h"
#include "../include/mc_weights.h"

class SuperChains 
{
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
  //DataChain* all_bg;

  SuperChains();

  std::vector<DataChain*> get_bg_chains();
  std::vector<DataChain*> get_all_bg_chains();
};

#endif
