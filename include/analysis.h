#ifndef Analysis_h
#define Analysis_h

#include <vector>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////
/////////////////      DATA, BACKGROUND, SIGNAL INPUT      /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////     BACKGROUNDS   ///////////////////////////////////////////


/////////////////////////////      QCD       ///////////////////////////////////////////

const char* qcd_arr[] = {"data/background/MC_QCD-Pt-1000to1400-pythia6.root",
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
			"data/background/MC_QCD-Pt-80to120_VBF-MET40.root"};

std::vector<const char*> qcd (qcd_arr, qcd_arr+ sizeof(qcd_arr)/sizeof(const char*));						

const char* qcd_label = "QCD";
const char* qcd_legend = "QCD";


//////////////////////////     (DY) Z -> ll     /////////////////////////////////////////

const char* z_ll_arr[] = {"data/background/MC_DY1JetsToLL.root",
						"data/background/MC_DY2JetsToLL.root",
						"data/background/MC_DY3JetsToLL.root",
						"data/background/MC_DY4JetsToLL.root",
						"data/background/MC_DYJetsToLL_PtZ-100-madgraph.root",
						"data/background/MC_DYJetsToLL.root"};

std::vector<const char*> z_ll (z_ll_arr, z_ll_arr+ sizeof(z_ll_arr)/sizeof(const char*));						

const char* z_ll_label = "Z_rightarrow_ell_ell";
const char* z_ll_legend = "Z #rightarrow ll";


///////////////////////////      W+jets->ev      ////////////////////////////////////////

const char* wjets_ev_arr[] = {"data/background/MC_EWK-W2jminus_enu.root",
                                "data/background/MC_EWK-W2jplus_enu.root",
                                "data/background/MC_W1JetsToLNu_enu.root",
                                "data/background/MC_W2JetsToLNu_enu.root",
                                "data/background/MC_W3JetsToLNu_enu.root",
                                "data/background/MC_W4JetsToLNu_enu.root",
                                "data/background/MC_WJetsToLNu-v1_enu.root",
                                "data/background/MC_WJetsToLNu-v2_enu.root"};

std::vector<const char*> wjets_ev (wjets_ev_arr, wjets_ev_arr + 
                            sizeof(wjets_ev_arr)/sizeof(const char*));		

const char* wjets_ev_label = "W_jets_rightarrowe_nu";
const char* wjets_ev_legend = "W+jets #rightarrow e#nu";


////////////////////////////      W+jets->muv      ///////////////////////////////////////

const char* wjets_muv_arr[] = {"data/background/MC_EWK-W2jminus_munu.root",
                                "data/background/MC_EWK-W2jplus_munu.root",
                                "data/background/MC_W1JetsToLNu_munu.root",
                                "data/background/MC_W2JetsToLNu_munu.root",
                                "data/background/MC_W3JetsToLNu_munu.root",
                                "data/background/MC_W4JetsToLNu_munu.root",
                                "data/background/MC_WJetsToLNu-v1_munu.root",
                                "data/background/MC_WJetsToLNu-v2_munu.root"};

std::vector<const char*> wjets_muv (wjets_muv_arr, wjets_muv_arr + 
                          sizeof(wjets_muv_arr)/sizeof(const char*));	

const char* wjets_muv_label = "W_jets_rightarrow_mu_nu";
const char* wjets_muv_legend = "W+jets #rightarrow #mu#nu";


///////////////////////////      /W+jets->tauv       //////////////////////////////////////

const char* wjets_tauv_arr[] = {"data/background/MC_EWK-W2jminus_taunu.root",
                                "data/background/MC_EWK-W2jplus_taunu.root",
                                "data/background/MC_W1JetsToLNu_taunu.root",
                                "data/background/MC_W2JetsToLNu_taunu.root",
                                "data/background/MC_W3JetsToLNu_taunu.root",
                                "data/background/MC_W4JetsToLNu_taunu.root",
                                "data/background/MC_WJetsToLNu-v1_taunu.root",
                                "data/background/MC_WJetsToLNu-v2_taunu.root"};

std::vector<const char*> wjets_tauv (wjets_tauv_arr, wjets_tauv_arr + 
                          sizeof(wjets_tauv_arr)/sizeof(const char*));

const char* wjets_tauv_label = "W_jets_rightarrow_tau_nu";
const char* wjets_tauv_legend = "W+jets #rightarrow #tau#nu";

///////////////////////////          Top            ///////////////////////////////////////

const char* top_arr[] = {"data/background/MC_T-tW.root", 
                         "data/background/MC_Tbar-tW.root"};

std::vector<const char*> top (top_arr, top_arr + 
                          sizeof(top_arr)/sizeof(const char*));

const char* top_label = "TT";
const char* top_legend = "TT";


///////////////////////////           VV            ///////////////////////////////////////

const char* vv_arr[] = {"data/background/MC_WGamma.root",
                        "data/background/MC_WW-pythia6-tauola.root",
                        "data/background/MC_WZ-pythia6-tauola.root",
                        "data/background/MC_ZZ-pythia6-tauola.root"};

std::vector<const char*> vv (vv_arr, vv_arr+ sizeof(vv_arr)/sizeof(const char*));

const char* vv_label = "VV";
const char* vv_legend = "VV";

///////////////////////////         Z+jets          ///////////////////////////////////////

//"~/mproject/data/background/MC_EWK-Z2j.root"


///////////////////////////       Z+jets->vv        ///////////////////////////////////////

//"~/mproject/data/background/MC_VBF_HToZZTo4Nu_M-200.root" 
// - don't know if this is z+jets

const char* zjets_vv_arr[] = {"data/background/MC_ZJetsToNuNu_50_HT_100.root",
                              "data/background/MC_ZJetsToNuNu_100_HT_200.root",
                              "data/background/MC_ZJetsToNuNu_200_HT_400.root",
                              "data/background/MC_ZJetsToNuNu_400_HT_inf.root"};

std::vector<const char*> zjets_vv (zjets_vv_arr, zjets_vv_arr + 
                          sizeof(zjets_vv_arr)/sizeof(const char*));

const char* zjets_vv_label = "Z_jets_rightarrow_nu_nu";
const char* zjets_vv_legend = "Z+jets #rightarrow #nu#nu";


///////////////////////////          Signal:         //////////////////////////////////////

const char* mc_signal_data_arr[] = {"data/signal/MC_Powheg-ggHtoinv-mH125.root", 
                                    "data/signal/MC_Powheg-Htoinv-mH125.root"};

std::vector<const char*> mc_signal_data (mc_signal_data_arr, mc_signal_data_arr + 
                          sizeof(mc_signal_data_arr)/sizeof(const char*));

const char* mc_signal_label = "signal";
const char* mc_signal_legend = "signal";


///////////////////////////           Data:          //////////////////////////////////////

const char* data_arr[] = {"data/data/MET_MET-2012A-22Jan2013-v1.root",
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

std::vector<const char*> data (data_arr, data_arr+ sizeof(data_arr)/sizeof(const char*));

const char* data_label = "data";
const char* data_legend = "data";


////////////////////////////////////////////////////////////////////////////////////////////
/////////////////            PLOTTING VARIABLES            /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// weight = total_weight_lepveto


///////////////////////////      Variables w/ cuts       ///////////////////////////////////

const char* vars[][8] = {
                              //{"jet1_pt", "Jet 1 pT", "10" "0.0", "600.0", "420.0", "440.0", "10"},
			      {"jet1_pt","Jet 1 pT", "0.0", "600.0", 
                               "420.0", "440.0","10","100"},
                              {"jet2_E","Jet 2 Energy", "0.0", "5000.0", 
                               "2400.0", "2700.0","50","30"},
                              {"jet1_eta","Jet 1 Eta", "-5.0", "5.0", 
                               "0.6", "1.0","50","50"},
                              {"forward_tag_eta","Forward Tag Eta", "-5.0", "5.0", 
                               "4.1", "4.3","25","30"},
                              {"dijet_deta","Dijet Delta", "3.0", "8.0", 
                               "6.4", "6.7","25","10"},
                              {"dijet_sumeta","Dijet Sum of Eta", "-6.0", "6.0", 
                               "3.5", "4.0","50","1"},
                              {"met","MET", "0.0", "400.0", 
                               "270.0", "320.0","25","1"},
                              {"metnomu_x","MET-X Excluding Muons", "-400.0", "400.0",
                                "340.0", "400.0","25","10"},
                              {"metnomu_y","MET-Y Excluding Muons", "-400.0", "400.0", 
                               "200.0", "400.0","50","10"},
                              {"met_significance","MET Significance", "0.0", "12.0", 
                               "7.2", "10.0","25","10"},
                              {"metnomu_significance","MET Excluding Muons Significance", "2.0", "12.0", 
                               "6.8", "10.2","10","20"},
                              {"sumet","Sum of Transverse Energy", "0.0", "2400.0", 
                               "1900.0", "2400.0","50","100"},
                              {"ht", "HCAL Scalar Sum of Energy","0.0", "1200.0", 
                               "125.0", "175.0","100","10"},
                              {"ht30","HCAL Scalar Sum of Energy over 30GeV", "0.0", "1200.0", 
                               "100.0", "150.0","100","100"},
                              {"sqrt_ht","Square Root HCAL Scalar Sum of Energy", "0.0", "35.0", 
                               "10.0", "13.0","50","30"},
                              {"unclustered_et","Unclustered Transverse Energy", "0.0", "2000.0", 
                               "1400.0", "1600.0","50","50"},
                              {"jet1met_dphi","(Jet-1,MET) dphi", "0.0", "3.5", 
                               "2.1", "2.4","50","50"},
                              {"jet2met_dphi","(Jet-2,MET) dphi", "0.0", "3.5", 
                               "1.4", "1.7","30","30"},
                              {"jet1metnomu_dphi","(Jet-1,MET) dphi Excluding Muons", "0.0", "3.5", 
                               "2.1", "2.5","50","50"},
                              {"jet2metnomu_dphi","(Jet-2,MET) dphi Excluding Muons", "0.0", "3.5", 
                               "1.4", "1.7","30","30"},
                              {"jetmetnomu_mindphi","(Two leading jets, MET) min dphi", "0.0", "3.5", 
                               "2.9", "3.1","25","10"},
                              {"alljetsmet_mindphi","(All jets, MET) min dphi", "0", "3.2", 
                               "2.2", "3.0","25","10"},
                              {"alljetsmetnomu_mindphi","(All jets, MET) min dphi excluding muons", "0.0", "3.5", 
                               "2.2", "3.0","25","10"},
                              {"jetunclet_mindphi","(Two Leading Jets, Unclustered Transverse Energy) min dphi", "0.0", "3.5", 
                               "2.8", "2.9","25","10"},
			      {"dijetmet_scalarSum_pt","Scalar Sum of Transverse Momentum of Two Leading Jets and MET", "0.0", "1200.0", 
                               "800.0", "900.0","25","30"},
                              {"dijetmet_vectorialSum_pt","Vectorial Sum of Transverse Momentum of Two Leading Jets and MET", "0.0", "400.0", 
                               "240.0", "250.0","100","100"},
                              {"jet2met_scalarprod","Jet-2 Scalar Product with MET", "-400.0", "400.0", 
                               "20.0", "50.0","100","100"},
                              {"dijetmetnomu_scalarSum_pt","The Scalar Sum of MET and Two Leading Jets Excluding Muons", "0.0", "1200.0", 
                               "800.0", "950.0","20","30"},
                              {"l1met","Level 1 trigger MET", "0.0", "400.0", 
                               "250.0", "400.0","10","40"},
                              {"metnomuons","MET Excluding Muons", "0.0", "400.0", 
                               "320.0", "400.0","25","15"},
                              {"mht","Missing HCAL Scalar Sum of Energy", "0.0", "3000.0", 
                               "2400.0", "2800.0","25","1"},
                              {"met_x","MET-X", "-400.0", "400.0", 
                               "370.0", "400.0","25","1"},
                              {"met_y","MET-Y", "-400.0", "400.0", 
                               "180.0", "400.0","25","10"}};
                              
#endif

                                                                              
																			  


