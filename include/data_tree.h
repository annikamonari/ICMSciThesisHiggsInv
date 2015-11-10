#ifndef Data_Tree_h
#define Data_Tree_h

#include "standard_headers.h"
#include <TCanvas.h>
#include <TFile.h>
#include <TApplication.h>
#include <TChain.h>
#include <TCut.h>

class LeafVariables {
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

  void set_branch_addresses(TTree* tree) {
    tree->SetBranchAddress("run", &run);
    tree->SetBranchAddress("lumi", &lumi);
    tree->SetBranchAddress("event", &event);
    tree->SetBranchAddress("weight_nolep", &weight_nolep);
    tree->SetBranchAddress("total_weight_lepveto", &total_weight_lepveto);
    tree->SetBranchAddress("total_weight_leptight", &total_weight_leptight);
    tree->SetBranchAddress("puweight_up_scale", &puweight_up_scale);
    tree->SetBranchAddress("puweight_down_scale", &puweight_down_scale);
    tree->SetBranchAddress("topweight_up_scale", &topweight_up_scale);
    tree->SetBranchAddress("topweight_down_scale", &topweight_down_scale);
    tree->SetBranchAddress("jet1_pt", &jet1_pt);
    tree->SetBranchAddress("jet2_pt", &jet2_pt);
    tree->SetBranchAddress("jet3_pt", &jet3_pt);
    tree->SetBranchAddress("jet1_E", &jet1_E);
    tree->SetBranchAddress("jet2_E", &jet2_E);
    tree->SetBranchAddress("jet3_E", &jet3_E);
    tree->SetBranchAddress("jet1_eta", &jet1_eta);
    tree->SetBranchAddress("jet2_eta", &jet2_eta);
    tree->SetBranchAddress("jet3_eta", &jet3_eta);
    tree->SetBranchAddress("forward_tag_eta", &forward_tag_eta);
    tree->SetBranchAddress("central_tag_eta", &central_tag_eta);
    tree->SetBranchAddress("jet1_phi", &jet1_phi);
    tree->SetBranchAddress("jet2_phi", &jet2_phi);
    tree->SetBranchAddress("jet3_phi", &jet3_phi);
    tree->SetBranchAddress("jet_csv1", &jet_csv1); //combined secondary vertex = csv - check if b quark
    tree->SetBranchAddress("jet_csv2", &jet_csv2);
    tree->SetBranchAddress("jet_csv3", &jet_csv3);
    tree->SetBranchAddress("dijet_M", &dijet_M);
    tree->SetBranchAddress("dijet_deta", &dijet_deta);
    tree->SetBranchAddress("dijet_sumeta", &dijet_sumeta);
    tree->SetBranchAddress("dijet_dphi", &dijet_dphi);
    tree->SetBranchAddress("met", &met); //missing transverse energy
    tree->SetBranchAddress("met_x", &met_x);
    tree->SetBranchAddress("met_y", &met_y);
    tree->SetBranchAddress("metnomu_x", &metnomu_x);
    tree->SetBranchAddress("metnomu_y", &metnomu_y);
    tree->SetBranchAddress("met_significance", &met_significance);
    tree->SetBranchAddress("metnomu_significance", &metnomu_significance);
    tree->SetBranchAddress("sumet", &sumet);
    tree->SetBranchAddress("ht", &ht); //hadron transverse energy - scalar sum of transverse energy of all - uses only callorimeter info other than muons and that
    tree->SetBranchAddress("ht30", &ht30);
    tree->SetBranchAddress("mht", &mht);
    tree->SetBranchAddress("sqrt_ht", &sqrt_ht);
    tree->SetBranchAddress("unclustered_et", &unclustered_et);
    tree->SetBranchAddress("jet1met_dphi", &jet1met_dphi);
    tree->SetBranchAddress("jet2met_dphi", &jet2met_dphi);
    tree->SetBranchAddress("jet1metnomu_dphi", &jet1metnomu_dphi);
    tree->SetBranchAddress("jet2metnomu_dphi", &jet2metnomu_dphi);
    tree->SetBranchAddress("jetmet_mindphi", &jetmet_mindphi); //minimum of delta phi between jet one and jet two and the MET - just leading two jets
    tree->SetBranchAddress("jetmetnomu_mindphi", &jetmetnomu_mindphi);
    tree->SetBranchAddress("alljetsmet_mindphi", &alljetsmet_mindphi); //minimum dphi between all jets and missing transverse energy
    tree->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
    tree->SetBranchAddress("jetunclet_mindphi", &jetunclet_mindphi);
    tree->SetBranchAddress("metunclet_dphi", &metunclet_dphi);
    tree->SetBranchAddress("metnomuunclet_dphi", &metnomuunclet_dphi);
    tree->SetBranchAddress("dijetmet_scalarSum_pt", &dijetmet_scalarSum_pt);
    tree->SetBranchAddress("dijetmet_vectorialSum_pt", &dijetmet_vectorialSum_pt);
    tree->SetBranchAddress("dijetmet_ptfraction", &dijetmet_ptfraction);
    tree->SetBranchAddress("jet1met_scalarprod", &jet1met_scalarprod);
    tree->SetBranchAddress("jet2met_scalarprod", &jet2met_scalarprod);
    tree->SetBranchAddress("dijetmetnomu_scalarSum_pt", &dijetmetnomu_scalarSum_pt);
    tree->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt);
    tree->SetBranchAddress("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction);
    tree->SetBranchAddress("jet1metnomu_scalarprod", &jet1metnomu_scalarprod);
    tree->SetBranchAddress("jet2metnomu_scalarprod", &jet2metnomu_scalarprod);
    tree->SetBranchAddress("n_jets_cjv_30", &n_jets_cjv_30);
    tree->SetBranchAddress("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE);
    tree->SetBranchAddress("n_jets_15", &n_jets_15);
    tree->SetBranchAddress("n_jets_30", &n_jets_30);
    tree->SetBranchAddress("cjvjetpt", &cjvjetpt);
    tree->SetBranchAddress("passtrigger", &passtrigger);
    tree->SetBranchAddress("passparkedtrigger1", &passparkedtrigger1);
    tree->SetBranchAddress("passparkedtrigger2", &passparkedtrigger2);
    tree->SetBranchAddress("l1met", &l1met);
    tree->SetBranchAddress("metnomuons", &metnomuons);
    tree->SetBranchAddress("nvetomuons", &nvetomuons);
    tree->SetBranchAddress("nselmuons", &nselmuons);
    tree->SetBranchAddress("nvetoelectrons", &nvetoelectrons);
    tree->SetBranchAddress("nselelectrons", &nselelectrons);
    tree->SetBranchAddress("ntaus", &ntaus);
    tree->SetBranchAddress("m_mumu", &m_mumu);
    tree->SetBranchAddress("m_ee", &m_ee);
    tree->SetBranchAddress("m_mumu_gen", &m_mumu_gen);
    tree->SetBranchAddress("genlep1_pt", &genlep1_pt);
    tree->SetBranchAddress("genlep1_eta", &genlep1_eta);
    tree->SetBranchAddress("genlep1_phi", &genlep1_phi);
    tree->SetBranchAddress("genlep1_id", &genlep1_id);
    tree->SetBranchAddress("genlep2_pt", &genlep2_pt);
    tree->SetBranchAddress("genlep2_eta", &genlep2_eta);
    tree->SetBranchAddress("genlep2_phi", &genlep2_phi);
    tree->SetBranchAddress("genlep2_id", &genlep2_id);
    tree->SetBranchAddress("mu1_pt", &mu1_pt);
    tree->SetBranchAddress("mu1_eta", &mu1_eta);
    tree->SetBranchAddress("mu1_phi", &mu1_phi);
    tree->SetBranchAddress("mu2_pt", &mu2_pt);
    tree->SetBranchAddress("mu2_eta", &mu2_eta);
    tree->SetBranchAddress("mu2_phi", &mu2_phi);
    tree->SetBranchAddress("ele1_pt", &ele1_pt);
    tree->SetBranchAddress("ele1_eta", &ele1_eta);
    tree->SetBranchAddress("ele1_phi", &ele1_phi);
    tree->SetBranchAddress("tau1_pt", &tau1_pt);
    tree->SetBranchAddress("tau1_eta", &tau1_eta);
    tree->SetBranchAddress("tau1_phi", &tau1_phi);
    tree->SetBranchAddress("lep_mt", &lep_mt);
    tree->SetBranchAddress("n_vertices", &n_vertices);
  }
};

class DataTree {
public:
  TFile* file;
  char* label;
  TTree* tree;
  LeafVariables* vars;

  DataTree(TFile* data_file, char* tree_name);
  void get_data();
  TH1F* create_histo_for_stack(int fill_color, char* variable_name, char* selection);
  void create_1d_plot(Double_t* var_name, int bins, int x_min, int x_max);
};

#endif