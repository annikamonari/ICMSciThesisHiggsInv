#ifndef Analysis_h
#define Analysis_h

#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      //////////////////////
/////////////////////////////////////////////////////////////////////////////////

//Backgrounds:

//(DY) Z -> ll
std::vector<const char*> z_ll = {"Data/background/MC_DY1JetsToLL.root", 
                            "Data/background/MC_DY2JetsToLL.root", 
                            "Data/background/MC_DY3JetsToLL.root", 
                            "Data/background/MC_DY4JetsToLL.root", 
                            "Data/background/MC_DYJetsToLL_PtZ-100-madgraph.root", 
                            "Data/background/MC_DYJetsToLL.root"};

const char* z_ll_label = "Z_rightarrow_ell_ell";
const char* z_ll_legend = "Z #rightarrow ll";

//W+jets->ev
std::vector<const char*> wjets_ev = {"Data/background/MC_EWK-W2jminus_enu.root",
                                "Data/background/MC_EWK-W2jplus_enu.root",
                                "Data/background/MC_W1JetsToLNu_enu.root",
                                "Data/background/MC_W2JetsToLNu_enu.root",
                                "Data/background/MC_W3JetsToLNu_enu.root", 
                                "Data/background/MC_W4JetsToLNu_enu.root",
                                "Data/background/MC_WJetsToLNu-v1_enu.root",
                                "Data/background/MC_WJetsToLNu-v2_enu.root"}; 
const char* wjets_ev_label = "W_jets_rightarrowe_nu";
const char* wjets_ev_legend = "W+jets #rightarrow e#nu";

//W+jets->muv
std::vector<const char*> wjets_muv = {"Data/background/MC_EWK-W2jminus_munu.root", 
                                "Data/background/MC_EWK-W2jplus_munu.root", 
                                "Data/background/MC_W1JetsToLNu_munu.root", 
                                "Data/background/MC_W2JetsToLNu_munu.root", 
                                "Data/background/MC_W3JetsToLNu_munu.root", 
                                "Data/background/MC_W4JetsToLNu_munu.root",
                                "Data/background/MC_WJetsToLNu-v1_munu.root",
                                "Data/background/MC_WJetsToLNu-v2_munu.root"};
const char* wjets_muv_label = "W_jets_rightarrow_mu_nu";
const char* wjets_muv_legend = "W+jets #rightarrow #mu#nu";
//W+jets->tauv
std::vector<const char*> wjets_tauv = {"Data/background/MC_EWK-W2jminus_taunu.root", 
                    "Data/background/MC_EWK-W2jplus_taunu.root", 
                    "Data/background/MC_W1JetsToLNu_taunu.root", 
                    "Data/background/MC_W2JetsToLNu_taunu.root", 
                    "Data/background/MC_W3JetsToLNu_taunu.root", 
                    "Data/background/MC_W4JetsToLNu_taunu.root",
                    "Data/background/MC_WJetsToLNu-v1_taunu.root",
                    "Data/background/MC_WJetsToLNu-v2_taunu.root"};
const char* wjets_tauv_label = "W_jets_rightarrow_tau_nu";
const char* wjets_tauv_legend = "W+jets #rightarrow #tau#nu";

//Top
std::vector<const char*> top = {"Data/background/MC_T-tW.root", "Data/background/MC_Tbar-tW.root"};
const char* top_label = "TT";
const char* top_legend = "TT";

//VV
std::vector<const char*> vv = {"Data/background/MC_WGamma.root", 
                          "Data/background/MC_WW-pythia6-tauola.root", 
                          "Data/background/MC_WZ-pythia6-tauola.root", 
                          "Data/background/MC_ZZ-pythia6-tauola.root"}; 
const char* vv_label = "VV";
const char* vv_legend = "VV";

//Z+jets
//"Data/background/MC_EWK-Z2j.root"

//Z+jets->vv
//"Data/background/MC_VBF_HToZZTo4Nu_M-200.root" - don't know if this is z+jets
std::vector<const char*> zjets_vv = {"Data/background/MC_ZJetsToNuNu_50_HT_100.root", 
                          "Data/background/MC_ZJetsToNuNu_100_HT_200.root", 
                          "Data/background/MC_ZJetsToNuNu_200_HT_400.root", 
                          "Data/background/MC_ZJetsToNuNu_400_HT_inf.root"};
const char* zjets_vv_label = "Z_jets_rightarrow_nu_nu";
const char* zjets_vv_legend = "Z+jets #rightarrow #nu#nu";
//Signal:

std::vector<const char*> mc_signal_data = {"Data/signal/MC_Powheg-ggHtoinv-mH125.root", "Data/signal/MC_Powheg-Htoinv-mH125.root".""};
const char* mc_signal_label = "signal";
const char* mc_signal_legend = "signal";
//Data:
std::vector<const char*> data = {"Data/data/MET_MET-2012A-22Jan2013-v1.root", 
                            "Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root", 
                            "Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-1.root", 
                            "Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-2.root", 
                            "Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-3.root", 
                            "Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-4.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-0.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-1.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-2.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-3.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-4.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-5.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-6.root", 
                            "Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-7.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-0.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-1.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-2.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-3.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-4.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-5.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-6.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-7.root", 
                            "Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-8.root"};
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
