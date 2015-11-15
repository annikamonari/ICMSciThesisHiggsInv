#ifndef Analysis_h
#define Analysis_h

#include <vector>
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      //////////////////////
/////////////////////////////////////////////////////////////////////////////////

//Backgrounds:
// QCD
const char* qcd_arr[] = {"MC_QCD-Pt-1000to1400-pythia6.root","MC_QCD-Pt-120to170-pythia6.root","MC_QCD-Pt-120to170_VBF-MET40.root","MC_QCD-Pt-1400to1800-pythia6.root","MC_QCD-Pt-170to300-pythia6.root","MC_QCD-Pt-170to300_VBF-MET40.root","MC_QCD-Pt-1800-pythia6.root","MC_QCD-Pt-300to470-pythia6.root","MC_QCD-Pt-300to470_VBF-MET40.root","MC_QCD-Pt-30to50-pythia6.root","MC_QCD-Pt-470to600-pythia6.root","MC_QCD-Pt-470to600_VBF-MET40.root","MC_QCD-Pt-50to80-pythia6.root","MC_QCD-Pt-600to800-pythia6.root","MC_QCD-Pt-800to1000-pythia6.root","MC_QCD-Pt-80to120-pythia6.root","MC_QCD-Pt-80to120_VBF-MET40.root"};
std::vector<const char*> qcd (qcd_arr, qcd_arr+ sizeof(qcd_arr)/sizeof(const char*));						

const char* qcd_label = "QCD";
const char* qcd_legend = "QCD";


//(DY) Z -> ll

const char* z_ll_arr[] = {"~/mproject/Data/background/MC_DY1JetsToLL.root",
						"~/mproject/Data/background/MC_DY2JetsToLL.root",
						"~/mproject/Data/background/MC_DY3JetsToLL.root",
						"~/mproject/Data/background/MC_DY4JetsToLL.root",
						"~/mproject/Data/background/MC_DYJetsToLL_PtZ-100-madgraph.root",
						"~/mproject/Data/background/MC_DYJetsToLL.root"};
std::vector<const char*> z_ll (z_ll_arr, z_ll_arr+ sizeof(z_ll_arr)/sizeof(const char*));						

const char* z_ll_label = "Z_rightarrow_ell_ell";
const char* z_ll_legend = "Z #rightarrow ll";

//W+jets->ev
const char* wjets_ev_arr[] = {"~/mproject/Data/background/MC_EWK-W2jminus_enu.root",
                                "~/mproject/Data/background/MC_EWK-W2jplus_enu.root",
                                "~/mproject/Data/background/MC_W1JetsToLNu_enu.root",
                                "~/mproject/Data/background/MC_W2JetsToLNu_enu.root",
                                "~/mproject/Data/background/MC_W3JetsToLNu_enu.root",
                                "~/mproject/Data/background/MC_W4JetsToLNu_enu.root",
                                "~/mproject/Data/background/MC_WJetsToLNu-v1_enu.root",
                                "~/mproject/Data/background/MC_WJetsToLNu-v2_enu.root"};
std::vector<const char*> wjets_ev (wjets_ev_arr, wjets_ev_arr+ sizeof(wjets_ev_arr)/sizeof(const char*));						
const char* wjets_ev_label = "W_jets_rightarrowe_nu";
const char* wjets_ev_legend = "W+jets #rightarrow e#nu";
//W+jets->muv
const char* wjets_muv_arr[] = {"~/mproject/Data/background/MC_EWK-W2jminus_munu.root",
                                "~/mproject/Data/background/MC_EWK-W2jplus_munu.root",
                                "~/mproject/Data/background/MC_W1JetsToLNu_munu.root",
                                "~/mproject/Data/background/MC_W2JetsToLNu_munu.root",
                                "~/mproject/Data/background/MC_W3JetsToLNu_munu.root",
                                "~/mproject/Data/background/MC_W4JetsToLNu_munu.root",
                                "~/mproject/Data/background/MC_WJetsToLNu-v1_munu.root",
                                "~/mproject/Data/background/MC_WJetsToLNu-v2_munu.root"};
std::vector<const char*> wjets_muv (wjets_muv_arr, wjets_muv_arr+ sizeof(wjets_muv_arr)/sizeof(const char*));	
const char* wjets_muv_label = "W_jets_rightarrow_mu_nu";
const char* wjets_muv_legend = "W+jets #rightarrow #mu#nu";
//W+jets->tauv
const char* wjets_tauv_arr[] = {"~/mproject/Data/background/MC_EWK-W2jminus_taunu.root",
                    "~/mproject/Data/background/MC_EWK-W2jplus_taunu.root",
                    "~/mproject/Data/background/MC_W1JetsToLNu_taunu.root",
                    "~/mproject/Data/background/MC_W2JetsToLNu_taunu.root",
                    "~/mproject/Data/background/MC_W3JetsToLNu_taunu.root",
                    "~/mproject/Data/background/MC_W4JetsToLNu_taunu.root",
                    "~/mproject/Data/background/MC_WJetsToLNu-v1_taunu.root",
                    "~/mproject/Data/background/MC_WJetsToLNu-v2_taunu.root"};
std::vector<const char*> wjets_tauv (wjets_tauv_arr, wjets_tauv_arr+ sizeof(wjets_tauv_arr)/sizeof(const char*));
const char* wjets_tauv_label = "W_jets_rightarrow_tau_nu";
const char* wjets_tauv_legend = "W+jets #rightarrow #tau#nu";

//Top
const char* top_arr[] = {"~/mproject/Data/background/MC_T-tW.root", "~/mproject/Data/background/MC_Tbar-tW.root"};
std::vector<const char*> top (top_arr, top_arr+ sizeof(top_arr)/sizeof(const char*));
const char* top_label = "TT";
const char* top_legend = "TT";

//VV
const char* vv_arr[] = {"~/mproject/Data/background/MC_WGamma.root",
                          "~/mproject/Data/background/MC_WW-pythia6-tauola.root",
                          "~/mproject/Data/background/MC_WZ-pythia6-tauola.root",
                          "~/mproject/Data/background/MC_ZZ-pythia6-tauola.root"};
std::vector<const char*> vv (vv_arr, vv_arr+ sizeof(vv_arr)/sizeof(const char*));
const char* vv_label = "VV";
const char* vv_legend = "VV";

//Z+jets
//"~/mproject/~/mproject/Data/background/MC_EWK-Z2j.root"

//Z+jets->vv
//"~/mproject/~/mproject/Data/background/MC_VBF_HToZZTo4Nu_M-200.root" - don't know if this is z+jets
const char* zjets_vv_arr[] = {"~/mproject/Data/background/MC_ZJetsToNuNu_50_HT_100.root",
                          "~/mproject/Data/background/MC_ZJetsToNuNu_100_HT_200.root",
                          "~/mproject/Data/background/MC_ZJetsToNuNu_200_HT_400.root",
                          "~/mproject/Data/background/MC_ZJetsToNuNu_400_HT_inf.root"};
std::vector<const char*> zjets_vv (zjets_vv_arr, zjets_vv_arr+ sizeof(zjets_vv_arr)/sizeof(const char*));
const char* zjets_vv_label = "Z_jets_rightarrow_nu_nu";
const char* zjets_vv_legend = "Z+jets #rightarrow #nu#nu";
//Signal:

const char* mc_signal_data_arr[] = {"~/mproject/Data/signal/MC_Powheg-ggHtoinv-mH125.root", "~/mproject/Data/signal/MC_Powheg-Htoinv-mH125.root"};
std::vector<const char*> mc_signal_data (mc_signal_data_arr, mc_signal_data_arr+ sizeof(mc_signal_data_arr)/sizeof(const char*));
const char* mc_signal_label = "signal";
const char* mc_signal_legend = "signal";

//Data:
const char* data_arr[] = {"~/mproject/Data/data/MET_MET-2012A-22Jan2013-v1.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-1.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-2.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-3.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012B-22Jan2013-v1-4.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-0.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-1.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-2.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-3.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-4.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-5.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-6.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012C-22Jan2013-v1-7.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-0.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-1.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-2.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-3.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-4.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-5.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-6.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-7.root",
                            "~/mproject/Data/data/PARKED_VBF-Parked-2012D-22Jan2013-v1-8.root"};
std::vector<const char*> data (data_arr, data_arr+ sizeof(data_arr)/sizeof(const char*));
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

                                                                              
																			  


