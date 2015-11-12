#ifndef Analysis_h
#define Analysis_h

#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      //////////////////////
/////////////////////////////////////////////////////////////////////////////////

//Backgrounds:

//(DY) Z -> ll
std::vector<const char*> z_ll = {"data/background/MC_DY1JetsToLL.root", 
                            "data/background/MC_DY2JetsToLL.root", 
                            "data/background/MC_DY3JetsToLL.root", 
                            "data/background/MC_DY4JetsToLL.root", 
                            "data/background/MC_DYJetsToLL_PtZ-100-madgraph.root", 
                            "data/background/MC_DYJetsToLL.root"};

const char* z_ll_label = "Z_rightarrow_ell_ell";
const char* z_ll_legend = "Z #rightarrow ll";

//W+jets->ev
std::vector<const char*> wjets_ev = {"data/background/MC_EWK-W2jminus_enu.root",
                                "data/background/MC_EWK-W2jplus_enu.root",
                                "data/background/MC_W1JetsToLNu_enu.root",
                                "data/background/MC_W2JetsToLNu_enu.root",
                                "data/background/MC_W3JetsToLNu_enu.root", 
                                "data/background/MC_W4JetsToLNu_enu.root",
                                "data/background/MC_WJetsToLNu-v1_enu.root",
                                "data/background/MC_WJetsToLNu-v2_enu.root"}; 
const char* wjets_ev_label = "W_jets_rightarrowe_nu";
const char* wjets_ev_legend = "W+jets #rightarrow e#nu";

//W+jets->muv
std::vector<const char*> wjets_muv = {"data/background/MC_EWK-W2jminus_munu.root", 
                                "data/background/MC_EWK-W2jplus_munu.root", 
                                "data/background/MC_W1JetsToLNu_munu.root", 
                                "data/background/MC_W2JetsToLNu_munu.root", 
                                "data/background/MC_W3JetsToLNu_munu.root", 
                                "data/background/MC_W4JetsToLNu_munu.root",
                                "data/background/MC_WJetsToLNu-v1_munu.root",
                                "data/background/MC_WJetsToLNu-v2_munu.root"};
const char* wjets_muv_label = "W_jets_rightarrow_mu_nu";
const char* wjets_muv_legend = "W+jets #rightarrow #mu#nu";
//W+jets->tauv
std::vector<const char*> wjets_tauv = {"data/background/MC_EWK-W2jminus_taunu.root", 
                    "data/background/MC_EWK-W2jplus_taunu.root", 
                    "data/background/MC_W1JetsToLNu_taunu.root", 
                    "data/background/MC_W2JetsToLNu_taunu.root", 
                    "data/background/MC_W3JetsToLNu_taunu.root", 
                    "data/background/MC_W4JetsToLNu_taunu.root",
                    "data/background/MC_WJetsToLNu-v1_taunu.root",
                    "data/background/MC_WJetsToLNu-v2_taunu.root"};
const char* wjets_tauv_label = "W_jets_rightarrow_tau_nu";
const char* wjets_tauv_legend = "W+jets #rightarrow #tau#nu";

//Top
std::vector<const char*> top = {"data/background/MC_T-tW.root", "data/background/MC_Tbar-tW.root"};
const char* top_label = "TT";
const char* top_legend = "TT";

//VV
std::vector<const char*> vv = {"data/background/MC_WGamma.root", 
                          "data/background/MC_WW-pythia6-tauola.root", 
                          "data/background/MC_WZ-pythia6-tauola.root", 
                          "data/background/MC_ZZ-pythia6-tauola.root"}; 
const char* vv_label = "VV";
const char* vv_legend = "VV";

//Z+jets
//"data/background/MC_EWK-Z2j.root"

//Z+jets->vv
//"data/background/MC_VBF_HToZZTo4Nu_M-200.root" - don't know if this is z+jets
std::vector<const char*> zjets_vv = {"data/background/MC_ZJetsToNuNu_50_HT_100.root", 
                          "data/background/MC_ZJetsToNuNu_100_HT_200.root", 
                          "data/background/MC_ZJetsToNuNu_200_HT_400.root", 
                          "data/background/MC_ZJetsToNuNu_400_HT_inf.root"};
const char* zjets_vv_label = "Z_jets_rightarrow_nu_nu";
const char* zjets_vv_legend = "Z+jets #rightarrow #nu#nu";
//Signal:

std::vector<const char*> mc_signal_data = {"data/signal/MC_Powheg-ggHtoinv-mH125.root", "data/signal/MC_Powheg-Htoinv-mH125.root"};
const char* mc_signal_label = "signal";
const char* mc_signal_legend = "signal";
//Data:
std::vector<const char*> data = {"data/data/MET_MET-2012A-22Jan2013-v1.root", 
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
                            "data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-8.root"};
const char* data_label = "data";
const char* data_legend = "data";

/////////////////////////////////////////////////////////////////////////////////
/////////////////            PLOTTING VARIABLES            //////////////////////
/////////////////////////////////////////////////////////////////////////////////

//total_weight_lepveto

//dijet_deta -- 0 - 8.5
//ht 0 400
//met -200 200
//alljetsmet_mindphi 0 - 3.5
//dijet_M 0 - 3000

#endif
