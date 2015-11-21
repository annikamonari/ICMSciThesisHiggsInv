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

const char* vars_w_cuts[][8] = {
                              {"jet1_pt", "0.0", "600.0", "right",
                               "420.0", "440.0","10","100"},
                              {"jet2_E", "0.0", "5000.0", "right",
                               "2400.0", "2700.0","50","30"},
                              {"jet1_eta", "-5.0", "5.0", "left",
                               "0.6", "1.0","50","50"},
                              {"forward_tag_eta", "-5.0", "5.0", "left",
                               "4.1", "4.3","25","30"},
                              {"dijet_deta", "3.0", "8.0", "right",
                               "6.4", "6.7","25","10"},
                              {"dijet_sumeta", "-6.0", "6.0", "left",
                               "3.5", "4.0","50","1"},
                              {"met", "0.0", "400.0", "right",
                               "270.0", "320.0","25","1"},
                              {"metnomu_x", "-400.0", "400.0",
                               "left", "340.0", "400.0","25","10"},
                              {"metnomu_y", "-400.0", "400.0", "left",
                               "200.0", "400.0","50","10"},
                              {"met_significance", "0.0", "12.0", "right",
                               "7.2", "10.0","25","10"},
                              {"metnomu_significance", "2.0", "12.0", "right",
                               "6.8", "10.2","10","20"},
                              {"sumet", "0.0", "2400.0", "right",
                               "1900.0", "2400.0","50","100"},
                              {"ht", "0.0", "1200.0", "right",
                               "125.0", "175.0","100","10"},
                              {"ht30", "0.0", "1200.0", "right",
                               "100.0", "150.0","100","100"},
                              {"sqrt_ht", "0.0", "35.0", "right",
                               "10.0", "13.0","50","30"},
                              {"unclustered_et", "0.0", "2000.0", "right",
                               "1400.0", "1600.0","50","50"},
                              {"jet1met_dphi", "0.0", "3.5", "left",
                               "2.1", "2.4","50","50"},
                              {"jet2met_dphi", "0.0", "3.5", "right",
                               "1.4", "1.7","30","30"},
                              {"jet1metnomu_dphi", "0.0", "3.5", "left",
                               "2.1", "2.5","50","50"},
                              {"jet2metnomu_dphi", "0.0", "3.5", "right",
                               "1.4", "1.7","30","30"},
                              {"jetmetnomu_mindphi", "0.0", "3.5", "right",
                               "2.9", "3.1","25","10"},
                              {"alljetsmet_mindphi", "0", "3.2", "left",
                               "2.2", "3.0","25","10"},
                              {"alljetsmetnomu_mindphi", "0.0", "3.5", "left",
                               "2.2", "3.0","25","10"},
                              {"jetunclet_mindphi", "0.0", "3.5", "right",
                               "2.8", "2.9","25","10"},
			      {"dijetmet_scalarSum_pt", "0.0", "1200.0", "right",
                               "800.0", "900.0","25","30"},
                              {"dijetmet_vectorialSum_pt", "0.0", "400.0", "right",
                               "240.0", "250.0","100","100"},
                              {"jet2met_scalarprod", "-400.0", "400.0", "left",
                               "20.0", "50.0","100","100"},
                              {"dijetmetnomu_scalarSum_pt", "0.0", "1200.0", "right",
                               "800.0", "950.0","20","30"},
                              {"l1met", "0.0", "400.0", "right",
                               "250.0", "400.0","10","40"},
                              {"metnomuons", "0.0", "400.0", "right",
                               "320.0", "400.0","25","15"},
                              {"mht", "0.0", "3000.0", "right",
                               "2400.0", "2800.0","25","1"},
                              {"met_x", "-400.0", "400.0", "left",
                               "370.0", "400.0","25","1"},
                              {"met_y", "-400.0", "400.0", "left",
                               "180.0", "400.0","25","10"}
			    };

///////////////////////////      Variables w/ no cuts       ////////////////////////////////

const char* vars_no_cuts[][4] = {
                              {"jet1_pt", "0.0", "600.0", "right"},
                              {"jet2_pt", "0.0", "600.0", "right"},
                              {"jet3_pt", "0.0", "600.0", "right"},
                              {"jet1_E", "0.0", "5000.0", "right"},
                              {"jet2_E", "0.0", "5000.0", "right"},
                              {"jet3_E", "0.0", "5000.0", "right"},
                              {"jet1_eta", "-5.0", "5.0", "left"},
                              {"jet2_eta", "-5.0", "5.0", "left"},
                              {"jet3_eta", "-5.0", "5.0", "left"},
                              {"forward_tag_eta", "-5.0", "5.0", "left"},
                              {"central_tag_eta", "-5.0", "5.0", "left"},
                              {"jet1_phi", "-4.0", "4.0", "left"},
                              {"jet2_phi", "-4.0", "4.0", "left"},
                              {"jet3_phi", "-4.0", "4.0", "left"},
                              {"jet_csv1", "-1.5", "1.5", "left"},
                              {"jet_csv2", "-1.5", "1.5", "left"},
                              {"jet_csv3", "-1.5", "1.5", "left"},
                              {"dijet_M", "0.0", "4000.0", "right"},
                              {"dijet_deta", "3.0", "8.0", "right"},
                              {"dijet_sumeta", "-6.0", "6.0", "left"},
                              {"dijet_dphi", "0.0", "4.0", "left"},
                              {"met", "0.0", "400.0", "right"},
                              {"met_x", "-400.0", "400.0", "left"},
                              {"met_y", "-400.0", "400.0", "left"},
                              {"metnomu_x", "-400.0", "400.0", "left"},
                              {"metnomu_y", "-400.0", "400.0", "left"},
                              {"met_significance", "0.0", "12.0", "right"},
                              {"metnomu_significance", "2.0", "12.0", "right"},
                              {"sumet", "0.0", "2400.0", "right"},
                              {"ht", "0.0", "1200.0", "right"},
                              {"ht30", "0.0", "1200.0", "right"},
                              {"mht", "0.0", "3000.0", "right"},
                              {"sqrt_ht", "0.0", "35.0", "right"},
                              {"unclustered_et", "0.0", "2000.0", "right"},
                              {"jet1met_dphi", "0.0", "3.5", "left"},
                              {"jet2met_dphi", "0.0", "3.5", "right"},
                              {"jet1metnomu_dphi", "0.0", "3.5", "left"},
                              {"jet2metnomu_dphi", "0.0", "3.5", "right"},
                              {"jetmet_mindphi", "0.0", "3.5", "right"},
                              {"jetmetnomu_mindphi", "0.0", "3.5", "right"},
                              {"alljetsmet_mindphi", "0", "3.2", "left"},
                              {"alljetsmetnomu_mindphi", "0.0", "3.5", "left"},
                              {"jetunclet_mindphi", "0.0", "3.5", "right"},
                              {"metunclet_dphi", "0.0", "3.5", "right"},
                              {"metnomuunclet_dphi", "0.0", "3.5", "right"},
                              {"dijetmet_scalarSum_pt", "0.0", "1200.0", "right"},
                              {"dijetmet_vectorialSum_pt", "0.0", "400.0", "right"},
                              {"dijetmet_ptfraction", "0.0", "1.0", "right"},
                              {"jet1met_scalarprod", "-600.0", "600.0", "right"},
                              {"jet2met_scalarprod", "-400.0", "400.0", "left"},
                              {"dijetmetnomu_scalarSum_pt", "0.0", "1200.0", "right"},
                              {"dijetmetnomu_vectorialSum_pt", "0.0", "400.0", "right"},
                              {"dijetmetnomu_ptfraction", "0.0", "1.0", "right"},
                              {"jet1metnomu_scalarprod", "-2000.0", "2000.0", "left"},
                              {"jet2metnomu_scalarprod", "-2000.0", "2000.0", "left"},
                              {"n_jets_cjv_30", "0.0", "6.0", "right"},
                              {"n_jets_cjv_20EB_30EE", "0.0", "8.0", "right"},
                              {"n_jets_15", "0.0", "14.0", "right"},
                              {"n_jets_30", "1.0", "10.0", "right"},
                              {"cjvjetpt", "-10.0", "200.0", "right"},
                              {"l1met", "0.0", "400.0", "right"},
                              {"metnomuons", "0.0", "400.0", "right"},  
                              {"nvetomuons", "0.0", "3.0", "right"},
                              {"nselmuons", "0.0", "3.0", "right"},
                              {"nvetoelectrons", "0.0", "3.0", "right"},
                              {"nselelectrons", "0.0", "3.0", "right"},
                              {"ntaus", "0.0", "3.0", "right"},
                              {"m_mumu", "-20.0", "20.0", "right"},
                              {"m_ee", "-20.0", "20.0", "right"},
                              {"m_mumu_gen", "-20.0", "20.0", "right"},
                              {"n_vertices", "0.0", "30.0", "right"}
                             };

#endif

                                                                              
																			  


