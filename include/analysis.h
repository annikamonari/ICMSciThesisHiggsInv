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

///////////////////////////          Signal:          //////////////////////////////////////

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

/////////////////           DATACHAIN STRUCT              /////////////////////////////////

struct Chains
{
		DataChain* bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend);
		DataChain* bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
		DataChain* bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
		DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
		DataChain* bg_top        = new DataChain(top, top_label, top_legend);
		DataChain* bg_vv         = new DataChain(vv, vv_label, vv_legend);
		DataChain* bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
		DataChain* bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
		DataChain* signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
		DataChain* data_chain    = new DataChain(data, data_label, data_legend);
};


////////////////////////////////////////////////////////////////////////////////////////////
/////////////////            PLOTTING VARIABLES            /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// weight = total_weight_lepveto


///////////////////////////            Variables              //////////////////////////////

struct Variables
{
		Variable* jet1_pt = new Variable("jet1_pt","Jet 1 pT", "0.0", "600.0", "40.0", "500.0",
																																			"50","100");
		Variable* jet2_eta = new Variable("jet2_eta","Jet 2 Eta", "-5.0", "5.0", "0.2", "5.0",
																																				"60","20");
		Variable* forward_tag_eta = new Variable("forward_tag_eta","Forward Tag Eta", "-5.0", "5.0",
																																											"1.8", "5.0","60","50");
		Variable* central_tag_eta = new Variable("central_tag_eta","Central Tag Eta", "-5.0", "5.0",
																																											"0.0", "5.0","50","50");
		Variable* dijet_deta = new Variable("dijet_deta","Dijet Deta", "3.5", "8.0", "4.2", "8.0",
																																						"25","100");
		Variable* dijet_dphi = new Variable("dijet_dphi","Dijet dphi", "0.0", "3.2", "0.0", "2.2",
																																						"35","40");
		Variable* metnomu_x = new Variable("metnomu_x","MET-X Excluding Muons", "-400.0", "400.0",
																																					"0.0", "400.0","60","70");
		Variable* metnomu_y = new Variable("metnomu_y","MET-Y Excluding Muons", "-400.0", "400.0",
																																					"0.0", "300.0","70","70");
		Variable* metnomu_significance = new Variable("metnomu_significance",
																																																"MET Excluding Muons Significance", "3.0", "12.0",
																																																"3.5", "12.0","50","70");
		Variable* ht = new Variable("ht", "HCAL Scalar Sum of Energy","0.0", "1200.0","50", "600",
																														"60","50");
		Variable* ht30 = new Variable("ht30","HCAL Scalar Sum of Energy over 30GeV", "0.0", "1200.0",
																																"50.0", "1100.0","75","30");
		Variable* sqrt_ht = new Variable("sqrt_ht","Square Root HCAL Scalar Sum of Energy", "0.0",
																																			"35.0","9.0", "18.0","75","50");
		Variable* unclustered_et = new Variable("unclustered_et","Unclustered Transverse Energy",
																																										"0.0", "2000.0","0.0", "1000.0","75","0");
		Variable* jet1metnomu_dphi = new Variable("jet1metnomu_dphi","Jet-1,MET dphi Excluding Muons",
																																												"0.0", "3.5","1.5", "2.5","60","100");
		Variable* jet1metnomu_scalarprod = new Variable("jet1metnomu_scalarprod",
																																																		"(Jet-1,MET) Scalar Product Excluding Muons",
																																																		"-2000.0", "2000.0","0.0", "1000.0","90","60");
		Variable* jet2metnomu_dphi = new Variable("jet2metnomu_dphi","Jet-2,MET dphi Excluding Muons",
																																												"0.0", "3.5","0.5", "3.2","60","100");
		Variable* jetmetnomu_mindphi = new Variable("jetmetnomu_mindphi","Two leading jets, MET min dphi",
																																														"0.0", "3.5","0.5", "3.2","40","70");
		Variable* alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi",
																																																		"All jets, MET min dphi excluding muons",
																																																		"0.0", "3.5","0.5", "3.0","40","50");
		Variable* dijet_M = new Variable("dijet_M","Dijet Mass", "0.0", "2000.0","800.0", "2000.0",
																																			"50","100");
		Variable* jet2met_scalarprod = new Variable("jet2met_scalarprod","Jet-2 Scalar Product with MET",
																																														"-400.0", "400.0","0.0", "100.0","100","100");
		Variable* l1met = new Variable("l1met","Level 1 trigger MET", "0.0", "400.0","0.0", "250.0",
																																	"50","40");
		Variable* metnomuons = new Variable("metnomuons","MET Excluding Muons", "0.0", "400.0","120.0",
																																						"400.0","50","80");
};
                              
#endif

                                                                              
																			  


