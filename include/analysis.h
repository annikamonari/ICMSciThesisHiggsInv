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
                              class TreeLeaves {
public:
  UInt_t run;
  UInt_t lumi;
  UInt_t event;
  UInt_t weight_nolep;
  UInt_t total_weight_lepveto;
  UInt_t total_weight_leptight;
  UInt_t puweight_up_scale;
  UInt_t puweight_down_scale;
  UInt_t topweight_up_scale;
  UInt_t topweight_down_scale;
  Double_t jet1_pt;
  Double_t jet2_pt;
  Double_t jet3_pt;
  Double_t jet1_E;
  Double_t jet2_E;
  Double_t jet3_E;
  Double_t jet1_eta;
  Double_t jet2_eta;
  Double_t jet3_eta;
  Double_t forward_tag_eta;
  Double_t central_tag_eta;
  Double_t jet1_phi;
  Double_t jet2_phi;
  Double_t jet3_phi;
  Double_t jet_csv1;
  Double_t jet_csv2;
  Double_t jet_csv3;
  Double_t dijet_M;
  Double_t dijet_deta;
  Double_t dijet_sumeta;
  Double_t dijet_dphi;
  Double_t met;
  Double_t met_x;
  Double_t met_y;
  Double_t metnomu_x;
  Double_t metnomu_y;
  Double_t met_significance;
  Double_t metnomu_significance;
  Double_t sumet;
  Double_t ht;
  Double_t ht30;
  Double_t mht;
  Double_t sqrt_ht;
  Double_t unclustered_et;
  Double_t jet1met_dphi;
  Double_t jet2met_dphi;
  Double_t jet1metnomu_dphi;
  Double_t jet2metnomu_dphi;
  Double_t jetmet_mindphi;
  Double_t jetmetnomu_mindphi;
  Double_t alljetsmet_mindphi;
  Double_t alljetsmetnomu_mindphi;
  Double_t jetunclet_mindphi;
  Double_t metunclet_dphi;
  Double_t metnomuunclet_dphi;
  Double_t dijetmet_scalarSum_pt;
  Double_t dijetmet_vectorialSum_pt;
  Double_t dijetmet_ptfraction;
  Double_t jet1met_scalarprod;
  Double_t jet2met_scalarprod;
  Double_t dijetmetnomu_scalarSum_pt;
  Double_t dijetmetnomu_vectorialSum_pt;
  Double_t dijetmetnomu_ptfraction;
  Double_t jet1metnomu_scalarprod;
  Double_t jet2metnomu_scalarprod;
  UInt_t n_jets_cjv_30;
  UInt_t n_jets_cjv_20EB_30EE;
  UInt_t n_jets_15;
  Double_t n_jets_30;
  Double_t cjvjetpt;
  UInt_t passtrigger;
  UInt_t passparkedtrigger1;
  UInt_t passparkedtrigger2;
  UInt_t l1met;
  Double_t metnomuons;  
  UInt_t nvetomuons;
  UInt_t nselmuons;
  UInt_t nvetoelectrons;
  UInt_t nselelectrons;
  UInt_t ntaus;
  UInt_t m_mumu;
  UInt_t m_ee;
  UInt_t m_mumu_gen;
  UInt_t genlep1_pt;
  UInt_t genlep1_eta;
  UInt_t genlep1_phi;
  UInt_t genlep1_id;
  UInt_t genlep2_pt;
  UInt_t genlep2_eta;
  UInt_t genlep2_phi;
  UInt_t genlep2_id;
  UInt_t mu1_pt;
  Double_t mu1_eta;
  Double_t mu1_phi;
  Double_t mu2_pt;
  Double_t mu2_eta;
  Double_t mu2_phi;
  Double_t ele1_pt;
  Double_t ele1_eta;
  Double_t ele1_phi;
  Double_t tau1_pt;
  Double_t tau1_eta;
  Double_t tau1_phi;
  Double_t lep_mt;
  UInt_t n_vertices;

  void set_branch_addresses(TChain* chain) {
    chain->SetBranchAddress("run", &run);
    chain->SetBranchAddress("lumi", &lumi);
    chain->SetBranchAddress("event", &event);
    chain->SetBranchAddress("weight_nolep", &weight_nolep);
    chain->SetBranchAddress("total_weight_lepveto", &total_weight_lepveto);
    chain->SetBranchAddress("total_weight_leptight", &total_weight_leptight);
    chain->SetBranchAddress("puweight_up_scale", &puweight_up_scale);
    chain->SetBranchAddress("puweight_down_scale", &puweight_down_scale);
    chain->SetBranchAddress("topweight_up_scale", &topweight_up_scale);
    chain->SetBranchAddress("topweight_down_scale", &topweight_down_scale);
    chain->SetBranchAddress("jet1_pt", &jet1_pt);
    chain->SetBranchAddress("jet2_pt", &jet2_pt);
    chain->SetBranchAddress("jet3_pt", &jet3_pt);
    chain->SetBranchAddress("jet1_E", &jet1_E);
    chain->SetBranchAddress("jet2_E", &jet2_E);
    chain->SetBranchAddress("jet3_E", &jet3_E);
    chain->SetBranchAddress("jet1_eta", &jet1_eta);
    chain->SetBranchAddress("jet2_eta", &jet2_eta);
    chain->SetBranchAddress("jet3_eta", &jet3_eta);
    chain->SetBranchAddress("forward_tag_eta", &forward_tag_eta);
    chain->SetBranchAddress("central_tag_eta", &central_tag_eta);
    chain->SetBranchAddress("jet1_phi", &jet1_phi);
    chain->SetBranchAddress("jet2_phi", &jet2_phi);
    chain->SetBranchAddress("jet3_phi", &jet3_phi);
    chain->SetBranchAddress("jet_csv1", &jet_csv1); //combined secondary vertex = csv - check if b quark
    chain->SetBranchAddress("jet_csv2", &jet_csv2);
    chain->SetBranchAddress("jet_csv3", &jet_csv3);
    chain->SetBranchAddress("dijet_M", &dijet_M);
    chain->SetBranchAddress("dijet_deta", &dijet_deta);
    chain->SetBranchAddress("dijet_sumeta", &dijet_sumeta);
    chain->SetBranchAddress("dijet_dphi", &dijet_dphi);
    chain->SetBranchAddress("met", &met); //missing transverse energy
    chain->SetBranchAddress("met_x", &met_x);
    chain->SetBranchAddress("met_y", &met_y);
    chain->SetBranchAddress("metnomu_x", &metnomu_x);
    chain->SetBranchAddress("metnomu_y", &metnomu_y);
    chain->SetBranchAddress("met_significance", &met_significance);
    chain->SetBranchAddress("metnomu_significance", &metnomu_significance);
    chain->SetBranchAddress("sumet", &sumet);
    chain->SetBranchAddress("ht", &ht); //hadron transverse energy - scalar sum of transverse energy of all - uses only callorimeter info other than muons and that
    chain->SetBranchAddress("ht30", &ht30);
    chain->SetBranchAddress("mht", &mht);
    chain->SetBranchAddress("sqrt_ht", &sqrt_ht);
    chain->SetBranchAddress("unclustered_et", &unclustered_et);
    chain->SetBranchAddress("jet1met_dphi", &jet1met_dphi);
    chain->SetBranchAddress("jet2met_dphi", &jet2met_dphi);
    chain->SetBranchAddress("jet1metnomu_dphi", &jet1metnomu_dphi);
    chain->SetBranchAddress("jet2metnomu_dphi", &jet2metnomu_dphi);
    chain->SetBranchAddress("jetmet_mindphi", &jetmet_mindphi); //minimum of delta phi between jet one and jet two and the MET - just leading two jets
    chain->SetBranchAddress("jetmetnomu_mindphi", &jetmetnomu_mindphi);
    chain->SetBranchAddress("alljetsmet_mindphi", &alljetsmet_mindphi); //minimum dphi between all jets and missing transverse energy
    chain->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
    chain->SetBranchAddress("jetunclet_mindphi", &jetunclet_mindphi);
    chain->SetBranchAddress("metunclet_dphi", &metunclet_dphi);
    chain->SetBranchAddress("metnomuunclet_dphi", &metnomuunclet_dphi);
    chain->SetBranchAddress("dijetmet_scalarSum_pt", &dijetmet_scalarSum_pt);
    chain->SetBranchAddress("dijetmet_vectorialSum_pt", &dijetmet_vectorialSum_pt);
    chain->SetBranchAddress("dijetmet_ptfraction", &dijetmet_ptfraction);
    chain->SetBranchAddress("jet1met_scalarprod", &jet1met_scalarprod);
    chain->SetBranchAddress("jet2met_scalarprod", &jet2met_scalarprod);
    chain->SetBranchAddress("dijetmetnomu_scalarSum_pt", &dijetmetnomu_scalarSum_pt);
    chain->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt);
    chain->SetBranchAddress("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction);
    chain->SetBranchAddress("jet1metnomu_scalarprod", &jet1metnomu_scalarprod);
    chain->SetBranchAddress("jet2metnomu_scalarprod", &jet2metnomu_scalarprod);
    chain->SetBranchAddress("n_jets_cjv_30", &n_jets_cjv_30);
    chain->SetBranchAddress("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE);
    chain->SetBranchAddress("n_jets_15", &n_jets_15);
    chain->SetBranchAddress("n_jets_30", &n_jets_30);
    chain->SetBranchAddress("cjvjetpt", &cjvjetpt);
    chain->SetBranchAddress("passtrigger", &passtrigger);
    chain->SetBranchAddress("passparkedtrigger1", &passparkedtrigger1);
    chain->SetBranchAddress("passparkedtrigger2", &passparkedtrigger2);
    chain->SetBranchAddress("l1met", &l1met);
    chain->SetBranchAddress("metnomuons", &metnomuons);
    chain->SetBranchAddress("nvetomuons", &nvetomuons);
    chain->SetBranchAddress("nselmuons", &nselmuons);
    chain->SetBranchAddress("nvetoelectrons", &nvetoelectrons);
    chain->SetBranchAddress("nselelectrons", &nselelectrons);
    chain->SetBranchAddress("ntaus", &ntaus);
    chain->SetBranchAddress("m_mumu", &m_mumu);
    chain->SetBranchAddress("m_ee", &m_ee);
    chain->SetBranchAddress("m_mumu_gen", &m_mumu_gen);
    chain->SetBranchAddress("genlep1_pt", &genlep1_pt);
    chain->SetBranchAddress("genlep1_eta", &genlep1_eta);
    chain->SetBranchAddress("genlep1_phi", &genlep1_phi);
    chain->SetBranchAddress("genlep1_id", &genlep1_id);
    chain->SetBranchAddress("genlep2_pt", &genlep2_pt);
    chain->SetBranchAddress("genlep2_eta", &genlep2_eta);
    chain->SetBranchAddress("genlep2_phi", &genlep2_phi);
    chain->SetBranchAddress("genlep2_id", &genlep2_id);
    chain->SetBranchAddress("mu1_pt", &mu1_pt);
    chain->SetBranchAddress("mu1_eta", &mu1_eta);
    chain->SetBranchAddress("mu1_phi", &mu1_phi);
    chain->SetBranchAddress("mu2_pt", &mu2_pt);
    chain->SetBranchAddress("mu2_eta", &mu2_eta);
    chain->SetBranchAddress("mu2_phi", &mu2_phi);
    chain->SetBranchAddress("ele1_pt", &ele1_pt);
    chain->SetBranchAddress("ele1_eta", &ele1_eta);
    chain->SetBranchAddress("ele1_phi", &ele1_phi);
    chain->SetBranchAddress("tau1_pt", &tau1_pt);
    chain->SetBranchAddress("tau1_eta", &tau1_eta);
    chain->SetBranchAddress("tau1_phi", &tau1_phi);
    chain->SetBranchAddress("lep_mt", &lep_mt);
    chain->SetBranchAddress("n_vertices", &n_vertices);
  }
};
std::vector<const char*> data (data_arr, data_arr+ sizeof(data_arr)/sizeof(const char*));

const char* data_label = "data";
const char* data_legend = "data";


////////////////////////////////////////////////////////////////////////////////////////////
/////////////////            PLOTTING VARIABLES            /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// weight = total_weight_lepveto


///////////////////////////      Variables w/ cuts       ///////////////////////////////////

const char* vars[][5] = {
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
                               "180.0", "400.0","25","10"}
                              
#endif

                                                                              
																			  


