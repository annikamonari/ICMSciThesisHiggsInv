#include "../include/analysis.h"

////////////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////     BACKGROUNDS   ///////////////////////////////////////////


/////////////////////////////      QCD       ///////////////////////////////////////////

const char* qcd_arr[] = {
                         "data/background/MC_QCD-Pt-1000to1400-pythia6.root",
                         "data/background/MC_QCD-Pt-120to170-pythia6.root",
                         "data/background/MC_QCD-Pt-120to170_VBF-MET40.root",
                         "data/background/MC_QCD-Pt-1400to1800-pythia6.root",
                         "data/background/MC_QCD-Pt-170to300-pythia6.root",
                         "data/background/MC_QCD-Pt-170to300_VBF-MET40.root",
                         "data/background/MC_QCD-Pt-1800-pythia6.root",
                         "data/background/MC_QCD-Pt-300to470-pythia6.root",
                         "data/background/MC_QCD-Pt-300to470_VBF-MET40.root",
                         "data/background/MC_QCD-Pt-30to50-pythia6.root",
                         "data/background/MC_QCD-Pt-470to600-pythia6.root",
                         "data/background/MC_QCD-Pt-470to600_VBF-MET40.root",
                         "data/background/MC_QCD-Pt-50to80-pythia6.root",
                         "data/background/MC_QCD-Pt-600to800-pythia6.root",
                         "data/background/MC_QCD-Pt-800to1000-pythia6.root",
                         "data/background/MC_QCD-Pt-80to120-pythia6.root",
                         "data/background/MC_QCD-Pt-80to120_VBF-MET40.root"
                        };

std::vector<const char*> qcd (qcd_arr, qcd_arr+ sizeof(qcd_arr)/sizeof(const char*));

const char* qcd_label  = "bg_qcd";
const char* qcd_legend = "QCD";


//////////////////////////     (DY) Z -> ll     /////////////////////////////////////////

const char* z_ll_arr[] = {
                          "data/background/MC_DY1JetsToLL.root",
                          "data/background/MC_DY2JetsToLL.root",
                          "data/background/MC_DY3JetsToLL.root",
                          "data/background/MC_DY4JetsToLL.root",
                          "data/background/MC_DYJetsToLL_PtZ-100-madgraph.root",
                          "data/background/MC_DYJetsToLL.root"
                         };

std::vector<const char*> z_ll (z_ll_arr, z_ll_arr + 
                         sizeof(z_ll_arr)/sizeof(const char*));

const char* z_ll_label  = "bg_zll";
const char* z_ll_legend = "Z #rightarrow ll";


///////////////////////////      W+jets->ev      ////////////////////////////////////////

const char* wjets_ev_arr[] = {
                              "data/background/MC_EWK-W2jminus_enu.root",
                              "data/background/MC_EWK-W2jplus_enu.root",
                              "data/background/MC_W1JetsToLNu_enu.root",
                              "data/background/MC_W2JetsToLNu_enu.root",
                              "data/background/MC_W3JetsToLNu_enu.root",
                              "data/background/MC_W4JetsToLNu_enu.root",
                              "data/background/MC_WJetsToLNu-v1_enu.root",
                              "data/background/MC_WJetsToLNu-v2_enu.root"
                             };

std::vector<const char*> wjets_ev (wjets_ev_arr, wjets_ev_arr +
                         sizeof(wjets_ev_arr)/sizeof(const char*));

const char* wjets_ev_label  = "bg_wjets_ev";
const char* wjets_ev_legend = "W+jets #rightarrow e#nu";


////////////////////////////      W+jets->muv      ///////////////////////////////////////

const char* wjets_muv_arr[] = {
                               "data/background/MC_EWK-W2jminus_munu.root",
                               "data/background/MC_EWK-W2jplus_munu.root",
                               "data/background/MC_W1JetsToLNu_munu.root",
                               "data/background/MC_W2JetsToLNu_munu.root",
                               "data/background/MC_W3JetsToLNu_munu.root",
                               "data/background/MC_W4JetsToLNu_munu.root",
                               "data/background/MC_WJetsToLNu-v1_munu.root",
                               "data/background/MC_WJetsToLNu-v2_munu.root"
                              };

std::vector<const char*> wjets_muv (wjets_muv_arr, wjets_muv_arr +
                         sizeof(wjets_muv_arr)/sizeof(const char*));

const char* wjets_muv_label  = "bg_wjets_muv";
const char* wjets_muv_legend = "W+jets #rightarrow #mu#nu";


///////////////////////////      /W+jets->tauv       //////////////////////////////////////

const char* wjets_tauv_arr[] = {
                                "data/background/MC_EWK-W2jminus_taunu.root",
                                "data/background/MC_EWK-W2jplus_taunu.root",
                                "data/background/MC_W1JetsToLNu_taunu.root",
                                "data/background/MC_W2JetsToLNu_taunu.root",
                                "data/background/MC_W3JetsToLNu_taunu.root",
                                "data/background/MC_W4JetsToLNu_taunu.root",
                                "data/background/MC_WJetsToLNu-v1_taunu.root",
                                "data/background/MC_WJetsToLNu-v2_taunu.root"
                               };

std::vector<const char*> wjets_tauv (wjets_tauv_arr, wjets_tauv_arr +
                         sizeof(wjets_tauv_arr)/sizeof(const char*));

const char* wjets_tauv_label  = "bg_wjets_tauv";
const char* wjets_tauv_legend = "W+jets #rightarrow #tau#nu";

///////////////////////////          Top            ///////////////////////////////////////

const char* top_arr[] = {
                         "data/background/MC_T-tW.root",
                         "data/background/MC_Tbar-tW.root"
                        };

std::vector<const char*> top (top_arr, top_arr +
                         sizeof(top_arr)/sizeof(const char*));

const char* top_label  = "bg_top";
const char* top_legend = "TT";


///////////////////////////           VV            ///////////////////////////////////////

const char* vv_arr[] = {
                        "data/background/MC_WGamma.root",
                        "data/background/MC_WW-pythia6-tauola.root",
                        "data/background/MC_WZ-pythia6-tauola.root",
                        "data/background/MC_ZZ-pythia6-tauola.root"
                       };

std::vector<const char*> vv (vv_arr, vv_arr + 
                         sizeof(vv_arr)/sizeof(const char*));

const char* vv_label  = "bg_vv";
const char* vv_legend = "VV";


///////////////////////////         Z+jets          ///////////////////////////////////////

//"~/mproject/data/background/MC_EWK-Z2j.root"


///////////////////////////       Z+jets->vv        ///////////////////////////////////////

//"~/mproject/data/background/MC_VBF_HToZZTo4Nu_M-200.root"
// - don't know if this is z+jets

const char* zjets_vv_arr[] = {
                              "data/background/MC_ZJetsToNuNu_50_HT_100.root",
                              "data/background/MC_ZJetsToNuNu_100_HT_200.root",
                              "data/background/MC_ZJetsToNuNu_200_HT_400.root",
                              "data/background/MC_ZJetsToNuNu_400_HT_inf.root"
                             };

std::vector<const char*> zjets_vv (zjets_vv_arr, zjets_vv_arr +
                         sizeof(zjets_vv_arr)/sizeof(const char*));

const char* zjets_vv_label  = "bg_zjets_vv";
const char* zjets_vv_legend = "Z+jets #rightarrow #nu#nu";

///////////////////////////  background file paths  ///////////////////////////////////////
/*
std::vector<const char*>* fp_array[] = {z_ll,wjets_ev,wjets_muv,wjets_tauv, top,vv,zjets_vv,qcd};

std::vector< const char*> file_paths (fp_array, fp_array+sizeof(vv_arr)/sizeof(const char*));
*/

///////////////////////////          Signal:          //////////////////////////////////////

const char* mc_signal_data_arr[] = {
                                    "data/signal/MC_Powheg-ggHtoinv-mH125.root",
                                    "data/signal/MC_Powheg-Htoinv-mH125.root"
                                   };

std::vector<const char*> mc_signal_data (mc_signal_data_arr, mc_signal_data_arr +
                         sizeof(mc_signal_data_arr)/sizeof(const char*));

const char* mc_signal_label  = "signal_chain";
const char* mc_signal_legend = "signal";


///////////////////////////           Data:          //////////////////////////////////////

const char* data_arr[] = {
                          "data/data/MET_MET-2012A-22Jan2013-v1.root",
                          "data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root",
                          "data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-1.root",
                          "data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-2.root",
                          "data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-3.root",
                          "data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-4.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-0.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-1.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-2.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-3.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-4.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-5.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-6.root",
                          "data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-7.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-0.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-1.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-2.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-3.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-4.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-5.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-6.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-7.root",
                          "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-8.root"
                         };

std::vector<const char*> data (data_arr, data_arr + 
                         sizeof(data_arr)/sizeof(const char*));

const char* data_label  = "data_chain";
const char* data_legend = "data";

/////////////////////// MVA parameters /////////////////////////
  const char* NTrees_arr[] = {"10", "100", "500", "800", "1000"};
  std::vector<const char*> NTrees (NTrees_arr, NTrees_arr +
                           sizeof(NTrees_arr)/sizeof(const char*));

  const char* BoostType_arr[] = {"AdaBoost"};
  std::vector<const char*> BoostType (BoostType_arr, BoostType_arr +
                             sizeof(BoostType_arr)/sizeof(const char*));

  const char* AdaBoostBeta_arr[] ={"0.1", "0.2", "0.5", "0.8"};
  std::vector<const char*> AdaBoostBeta (AdaBoostBeta_arr, AdaBoostBeta_arr +
                               sizeof(AdaBoostBeta_arr)/sizeof(const char*));

  const char* SeparationType_arr[] = {"GiniIndex", "CrossEntropy", "MisClassificationError", "SDivSqrtSPlusB"};
  std::vector<const char*> SeparationType (SeparationType_arr, SeparationType_arr +
                                 sizeof(SeparationType_arr)/sizeof(const char*));

  const char* nCuts_arr[] = {"5", "10", "20", "30"};
  std::vector<const char*> nCuts (nCuts_arr, nCuts_arr +
                                   sizeof(nCuts_arr)/sizeof(const char*));
  
  const char* NeuronType_arr[] = {"sigmoid","tanh"};
  std::vector<const char*> NeuronType (NeuronType_arr, NeuronType_arr +
                                     sizeof(NeuronType_arr)/sizeof(const char*));

  const char* NCycles_arr[] = {"10","100","500","1000","5000"};
  std::vector<const char*> NCycles (NCycles_arr, NCycles_arr +
                                       sizeof(NCycles_arr)/sizeof(const char*));

  const char* HiddenLayers_arr[] = {"1","2","4","5","8","10","20","3,3","3,3,3","3,3,3,3","3,3,3,3,3","3,3,3,3,3,3","3,3,3,3,3,3,3"} ;//number of neurons in each hidden layer
  std::vector<const char*> HiddenLayers (HiddenLayers_arr, HiddenLayers_arr +
                                         sizeof(HiddenLayers_arr)/sizeof(const char*));


