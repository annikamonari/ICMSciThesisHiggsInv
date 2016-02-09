#ifndef Analysis_h
#define Analysis_h

#include <vector>
#include <stdlib.h>
#include "../include/data_chain.h"

////////////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////     BACKGROUNDS   ///////////////////////////////////////////

/////////////////////////////      QCD       ///////////////////////////////////////////

extern const char* qcd_arr[];
extern std::vector<const char*> qcd;
extern const char* qcd_label;
extern const char* qcd_legend;


///////////////////////////         Z->ll        ////////////////////////////////////////

extern const char* z_ll_arr[];
extern std::vector<const char*> z_ll;
extern const char* z_ll_label;
extern const char* z_ll_legend;


///////////////////////////      W+jets->ev      ////////////////////////////////////////

extern const char* wjets_ev_arr[];
extern std::vector<const char*> wjets_ev;
extern const char* wjets_ev_label;
extern const char* wjets_ev_legend;


////////////////////////////      W+jets->muv      ///////////////////////////////////////

extern const char* wjets_muv_arr[];
extern std::vector<const char*> wjets_muv;
extern const char* wjets_muv_label;
extern const char* wjets_muv_legend;


///////////////////////////      /W+jets->tauv       //////////////////////////////////////

extern const char* wjets_tauv_arr[];
extern std::vector<const char*> wjets_tauv;
extern const char* wjets_tauv_label;
extern const char* wjets_tauv_legend;


///////////////////////////          Top            ///////////////////////////////////////

extern const char* top_arr[];
extern std::vector<const char*> top;
extern const char* top_label;
extern const char* top_legend;


///////////////////////////           VV            ///////////////////////////////////////

extern const char* vv_arr[];
extern std::vector<const char*> vv;
extern const char* vv_label;
extern const char* vv_legend;
extern const char* zjets_vv_arr[];


///////////////////////////         Z->nunu          ///////////////////////////////////////

extern std::vector<const char*> zjets_vv;
extern const char* zjets_vv_label;
extern const char* zjets_vv_legend;

///////////////////////////  background file paths  ///////////////////////////////////////

//extern std::vector< const char*> file_paths;

///////////////////////////          Signal:          //////////////////////////////////////

extern const char* mc_signal_data_arr[];
extern std::vector<const char*> mc_signal_data;
extern const char* mc_signal_label;
extern const char* mc_signal_legend;


///////////////////////////           Data:          ///////////////////////////////////////

extern const char* data_arr[];
extern std::vector<const char*> data;
extern const char* data_label;
extern const char* data_legend;

/////////////////////// MVA parameters /////////////////////////
extern const char* NTrees[];
extern const char* BoostType[];
extern const char* AdaBoostBeta[];
extern const char* SeparationType[];
extern const char* nCuts[];
  
extern const char* NeuronType[];
extern const char* NCycles[];
extern const char* HiddenLayers[];//number of neurons in each hidden layer

#endif
