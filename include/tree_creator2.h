#ifndef tree_creator2_h
#define tree_creator2_h


#include <TChain.h>
#include <TFile.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TH2.h>
#include <TStyle.h>
#include <iostream>

class tree_creator2{
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   
   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   UInt_t          event;
   Double_t        weight_nolep;
   Double_t        total_weight_lepveto;
   Double_t        total_weight_leptight;
   Double_t        puweight_up_scale;
   Double_t        puweight_down_scale;
   Double_t        topweight_up_scale;
   Double_t        topweight_down_scale;
   Double_t        jet1_pt;
   Double_t        jet2_pt;
   Double_t        jet3_pt;
   Double_t        jet1_E;
   Double_t        jet2_E;
   Double_t        jet3_E;
   Double_t        jet1_eta;
   Double_t        jet2_eta;
   Double_t        jet3_eta;
   Double_t        forward_tag_eta;
   Double_t        central_tag_eta;
   Double_t        jet1_phi;
   Double_t        jet2_phi;
   Double_t        jet3_phi;
   Double_t        jet_csv1;
   Double_t        jet_csv2;
   Double_t        jet_csv3;
   Double_t        dijet_M;
   Double_t        dijet_deta;
   Double_t        dijet_sumeta;
   Double_t        dijet_dphi;
   Double_t        met;
   Double_t        met_x;
   Double_t        met_y;
   Double_t        metnomu_x;
   Double_t        metnomu_y;
   Double_t        met_significance;
   Double_t        metnomu_significance;
   Double_t        sumet;
   Double_t        ht;
   Double_t        ht30;
   Double_t        mht;
   Double_t        sqrt_ht;
   Double_t        unclustered_et;
   Double_t        jet1met_dphi;
   Double_t        jet2met_dphi;
   Double_t        jet1metnomu_dphi;
   Double_t        jet2metnomu_dphi;
   Double_t        jetmet_mindphi;
   Double_t        jetmetnomu_mindphi;
   Double_t        alljetsmet_mindphi;
   Double_t        alljetsmetnomu_mindphi;
   Double_t        jetunclet_mindphi;
   Double_t        metunclet_dphi;
   Double_t        metnomuunclet_dphi;
   Double_t        dijetmet_scalarSum_pt;
   Double_t        dijetmet_vectorialSum_pt;
   Double_t        dijetmet_ptfraction;
   Double_t        jet1met_scalarprod;
   Double_t        jet2met_scalarprod;
   Double_t        dijetmetnomu_scalarSum_pt;
   Double_t        dijetmetnomu_vectorialSum_pt;
   Double_t        dijetmetnomu_ptfraction;
   Double_t        jet1metnomu_scalarprod;
   Double_t        jet2metnomu_scalarprod;
   UInt_t          n_jets_cjv_30;
   UInt_t          n_jets_cjv_20EB_30EE;
   UInt_t          n_jets_15;
   UInt_t          n_jets_30;
   Double_t        cjvjetpt;
   Double_t        passtrigger;
   Double_t        passparkedtrigger1;
   Double_t        passparkedtrigger2;
   Double_t        l1met;
   Double_t        metnomuons;
   Int_t           nvetomuons;
   Int_t           nselmuons;
   Int_t           nvetoelectrons;
   Int_t           nselelectrons;
   Int_t           ntaus;
   Double_t        m_mumu;
   Double_t        m_ee;
   Double_t        m_mumu_gen;
   Double_t        genlep1_pt;
   Double_t        genlep1_eta;
   Double_t        genlep1_phi;
   Double_t        genlep1_id;
   Double_t        genlep2_pt;
   Double_t        genlep2_eta;
   Double_t        genlep2_phi;
   Double_t        genlep2_id;
   Double_t        mu1_pt;
   Double_t        mu1_eta;
   Double_t        mu1_phi;
   Double_t        mu2_pt;
   Double_t        mu2_eta;
   Double_t        mu2_phi;
   Double_t        ele1_pt;
   Double_t        ele1_eta;
   Double_t        ele1_phi;
   Double_t        tau1_pt;
   Double_t        tau1_eta;
   Double_t        tau1_phi;
   Double_t        lep_mt;
   Int_t           n_vertices;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_weight_nolep;   //!
   TBranch        *b_total_weight_lepveto;   //!
   TBranch        *b_total_weight_leptight;   //!
   TBranch        *b_puweight_up_scale;   //!
   TBranch        *b_puweight_down_scale;   //!
   TBranch        *b_topweight_up_scale;   //!
   TBranch        *b_topweight_down_scale;   //!
   TBranch        *b_jet1_pt;   //!
   TBranch        *b_jet2_pt;   //!
   TBranch        *b_jet3_pt;   //!
   TBranch        *b_jet1_E;   //!
   TBranch        *b_jet2_E;   //!
   TBranch        *b_jet3_E;   //!
   TBranch        *b_jet1_eta;   //!
   TBranch        *b_jet2_eta;   //!
   TBranch        *b_jet3_eta;   //!
   TBranch        *b_forward_tag_eta;   //!
   TBranch        *b_central_tag_eta;   //!
   TBranch        *b_jet1_phi;   //!
   TBranch        *b_jet2_phi;   //!
   TBranch        *b_jet3_phi;   //!
   TBranch        *b_jet_csv1;   //!
   TBranch        *b_jet_csv2;   //!
   TBranch        *b_jet_csv3;   //!
   TBranch        *b_dijet_M;   //!
   TBranch        *b_dijet_deta;   //!
   TBranch        *b_dijet_sumeta;   //!
   TBranch        *b_dijet_dphi;   //!
   TBranch        *b_met;   //!
   TBranch        *b_met_x;   //!
   TBranch        *b_met_y;   //!
   TBranch        *b_metnomu_x;   //!
   TBranch        *b_metnomu_y;   //!
   TBranch        *b_met_significance;   //!
   TBranch        *b_metnomu_significance;   //!
   TBranch        *b_sumet;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_ht30;   //!
   TBranch        *b_mht;   //!
   TBranch        *b_sqrt_ht;   //!
   TBranch        *b_unclustered_et;   //!
   TBranch        *b_jet1met_dphi;   //!
   TBranch        *b_jet2met_dphi;   //!
   TBranch        *b_jet1metnomu_dphi;   //!
   TBranch        *b_jet2metnomu_dphi;   //!
   TBranch        *b_jetmet_mindphi;   //!
   TBranch        *b_jetmetnomu_mindphi;   //!
   TBranch        *b_alljetsmet_mindphi;   //!
   TBranch        *b_alljetsmetnomu_mindphi;   //!
   TBranch        *b_jetunclet_mindphi;   //!
   TBranch        *b_metunclet_dphi;   //!
   TBranch        *b_metnomuunclet_dphi;   //!
   TBranch        *b_dijetmet_scalarSum_pt;   //!
   TBranch        *b_dijetmet_vectorialSum_pt;   //!
   TBranch        *b_dijetmet_ptfraction;   //!
   TBranch        *b_jet1met_scalarprod;   //!
   TBranch        *b_jet2met_scalarprod;   //!
   TBranch        *b_dijetmetnomu_scalarSum_pt;   //!
   TBranch        *b_dijetmetnomu_vectorialSum_pt;   //!
   TBranch        *b_dijetmetnomu_ptfraction;   //!
   TBranch        *b_jet1metnomu_scalarprod;   //!
   TBranch        *b_jet2metnomu_scalarprod;   //!
   TBranch        *b_n_jets_cjv_30;   //!
   TBranch        *b_n_jets_cjv_20EB_30EE;   //!
   TBranch        *b_n_jets_15;   //!
   TBranch        *b_n_jets_30;   //!
   TBranch        *b_cjvjetpt;   //!
   TBranch        *b_passtrigger;   //!
   TBranch        *b_passparkedtrigger1;   //!
   TBranch        *b_passparkedtrigger2;   //!
   TBranch        *b_l1met;   //!
   TBranch        *b_metnomuons;   //!
   TBranch        *b_nvetomuons;   //!
   TBranch        *b_nselmuons;   //!
   TBranch        *b_nvetoelectrons;   //!
   TBranch        *b_nselelectrons;   //!
   TBranch        *b_ntaus;   //!
   TBranch        *b_m_mumu;   //!
   TBranch        *b_m_ee;   //!
   TBranch        *b_m_mumu_gen;   //!
   TBranch        *b_genlep1_pt;   //!
   TBranch        *b_genlep1_eta;   //!
   TBranch        *b_genlep1_phi;   //!
   TBranch        *b_genlep1_id;   //!
   TBranch        *b_genlep2_pt;   //!
   TBranch        *b_genlep2_eta;   //!
   TBranch        *b_genlep2_phi;   //!
   TBranch        *b_genlep2_id;   //!
   TBranch        *b_mu1_pt;   //!
   TBranch        *b_mu1_eta;   //!
   TBranch        *b_mu1_phi;   //!
   TBranch        *b_mu2_pt;   //!
   TBranch        *b_mu2_eta;   //!
   TBranch        *b_mu2_phi;   //!
   TBranch        *b_ele1_pt;   //!
   TBranch        *b_ele1_eta;   //!
   TBranch        *b_ele1_phi;   //!
   TBranch        *b_tau1_pt;   //!
   TBranch        *b_tau1_eta;   //!
   TBranch        *b_tau1_phi;   //!
   TBranch        *b_lep_mt;   //!
   TBranch        *b_n_vertices;   //!
   
   tree_creator2(TTree *tree=0);
   virtual ~tree_creator2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Show(Long64_t entry = -1);
};

tree_creator2::tree_creator2(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      tree = (TTree*)gDirectory->Get("LightTree");
   }
   Init(tree);
}

tree_creator2::~tree_creator2() //dtor
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tree_creator2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree_creator2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void tree_creator2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("weight_nolep", &weight_nolep, &b_weight_nolep);
   fChain->SetBranchAddress("total_weight_lepveto", &total_weight_lepveto, &b_total_weight_lepveto);
   fChain->SetBranchAddress("total_weight_leptight", &total_weight_leptight, &b_total_weight_leptight);
   fChain->SetBranchAddress("puweight_up_scale", &puweight_up_scale, &b_puweight_up_scale);
   fChain->SetBranchAddress("puweight_down_scale", &puweight_down_scale, &b_puweight_down_scale);
   fChain->SetBranchAddress("topweight_up_scale", &topweight_up_scale, &b_topweight_up_scale);
   fChain->SetBranchAddress("topweight_down_scale", &topweight_down_scale, &b_topweight_down_scale);
   fChain->SetBranchAddress("jet1_pt", &jet1_pt, &b_jet1_pt);
   fChain->SetBranchAddress("jet2_pt", &jet2_pt, &b_jet2_pt);
   fChain->SetBranchAddress("jet3_pt", &jet3_pt, &b_jet3_pt);
   fChain->SetBranchAddress("jet1_E", &jet1_E, &b_jet1_E);
   fChain->SetBranchAddress("jet2_E", &jet2_E, &b_jet2_E);
   fChain->SetBranchAddress("jet3_E", &jet3_E, &b_jet3_E);
   fChain->SetBranchAddress("jet1_eta", &jet1_eta, &b_jet1_eta);
   fChain->SetBranchAddress("jet2_eta", &jet2_eta, &b_jet2_eta);
   fChain->SetBranchAddress("jet3_eta", &jet3_eta, &b_jet3_eta);
   fChain->SetBranchAddress("forward_tag_eta", &forward_tag_eta, &b_forward_tag_eta);
   fChain->SetBranchAddress("central_tag_eta", &central_tag_eta, &b_central_tag_eta);
   fChain->SetBranchAddress("jet1_phi", &jet1_phi, &b_jet1_phi);
   fChain->SetBranchAddress("jet2_phi", &jet2_phi, &b_jet2_phi);
   fChain->SetBranchAddress("jet3_phi", &jet3_phi, &b_jet3_phi);
   fChain->SetBranchAddress("jet_csv1", &jet_csv1, &b_jet_csv1);
   fChain->SetBranchAddress("jet_csv2", &jet_csv2, &b_jet_csv2);
   fChain->SetBranchAddress("jet_csv3", &jet_csv3, &b_jet_csv3);
   fChain->SetBranchAddress("dijet_M", &dijet_M, &b_dijet_M);
   fChain->SetBranchAddress("dijet_deta", &dijet_deta, &b_dijet_deta);
   fChain->SetBranchAddress("dijet_sumeta", &dijet_sumeta, &b_dijet_sumeta);
   fChain->SetBranchAddress("dijet_dphi", &dijet_dphi, &b_dijet_dphi);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("met_x", &met_x, &b_met_x);
   fChain->SetBranchAddress("met_y", &met_y, &b_met_y);
   fChain->SetBranchAddress("metnomu_x", &metnomu_x, &b_metnomu_x);
   fChain->SetBranchAddress("metnomu_y", &metnomu_y, &b_metnomu_y);
   fChain->SetBranchAddress("met_significance", &met_significance, &b_met_significance);
   fChain->SetBranchAddress("metnomu_significance", &metnomu_significance, &b_metnomu_significance);
   fChain->SetBranchAddress("sumet", &sumet, &b_sumet);
   fChain->SetBranchAddress("ht", &ht, &b_ht);
   fChain->SetBranchAddress("ht30", &ht30, &b_ht30);
   fChain->SetBranchAddress("mht", &mht, &b_mht);
   fChain->SetBranchAddress("sqrt_ht", &sqrt_ht, &b_sqrt_ht);
   fChain->SetBranchAddress("unclustered_et", &unclustered_et, &b_unclustered_et);
   fChain->SetBranchAddress("jet1met_dphi", &jet1met_dphi, &b_jet1met_dphi);
   fChain->SetBranchAddress("jet2met_dphi", &jet2met_dphi, &b_jet2met_dphi);
   fChain->SetBranchAddress("jet1metnomu_dphi", &jet1metnomu_dphi, &b_jet1metnomu_dphi);
   fChain->SetBranchAddress("jet2metnomu_dphi", &jet2metnomu_dphi, &b_jet2metnomu_dphi);
   fChain->SetBranchAddress("jetmet_mindphi", &jetmet_mindphi, &b_jetmet_mindphi);
   fChain->SetBranchAddress("jetmetnomu_mindphi", &jetmetnomu_mindphi, &b_jetmetnomu_mindphi);
   fChain->SetBranchAddress("alljetsmet_mindphi", &alljetsmet_mindphi, &b_alljetsmet_mindphi);
   fChain->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi, &b_alljetsmetnomu_mindphi);
   fChain->SetBranchAddress("jetunclet_mindphi", &jetunclet_mindphi, &b_jetunclet_mindphi);
   fChain->SetBranchAddress("metunclet_dphi", &metunclet_dphi, &b_metunclet_dphi);
   fChain->SetBranchAddress("metnomuunclet_dphi", &metnomuunclet_dphi, &b_metnomuunclet_dphi);
   fChain->SetBranchAddress("dijetmet_scalarSum_pt", &dijetmet_scalarSum_pt, &b_dijetmet_scalarSum_pt);
   fChain->SetBranchAddress("dijetmet_vectorialSum_pt", &dijetmet_vectorialSum_pt, &b_dijetmet_vectorialSum_pt);
   fChain->SetBranchAddress("dijetmet_ptfraction", &dijetmet_ptfraction, &b_dijetmet_ptfraction);
   fChain->SetBranchAddress("jet1met_scalarprod", &jet1met_scalarprod, &b_jet1met_scalarprod);
   fChain->SetBranchAddress("jet2met_scalarprod", &jet2met_scalarprod, &b_jet2met_scalarprod);
   fChain->SetBranchAddress("dijetmetnomu_scalarSum_pt", &dijetmetnomu_scalarSum_pt, &b_dijetmetnomu_scalarSum_pt);
   fChain->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt, &b_dijetmetnomu_vectorialSum_pt);
   fChain->SetBranchAddress("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction, &b_dijetmetnomu_ptfraction);
   fChain->SetBranchAddress("jet1metnomu_scalarprod", &jet1metnomu_scalarprod, &b_jet1metnomu_scalarprod);
   fChain->SetBranchAddress("jet2metnomu_scalarprod", &jet2metnomu_scalarprod, &b_jet2metnomu_scalarprod);
   fChain->SetBranchAddress("n_jets_cjv_30", &n_jets_cjv_30, &b_n_jets_cjv_30);
   fChain->SetBranchAddress("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE, &b_n_jets_cjv_20EB_30EE);
   fChain->SetBranchAddress("n_jets_15", &n_jets_15, &b_n_jets_15);
   fChain->SetBranchAddress("n_jets_30", &n_jets_30, &b_n_jets_30);
   fChain->SetBranchAddress("cjvjetpt", &cjvjetpt, &b_cjvjetpt);
   fChain->SetBranchAddress("passtrigger", &passtrigger, &b_passtrigger);
   fChain->SetBranchAddress("passparkedtrigger1", &passparkedtrigger1, &b_passparkedtrigger1);
   fChain->SetBranchAddress("passparkedtrigger2", &passparkedtrigger2, &b_passparkedtrigger2);
   fChain->SetBranchAddress("l1met", &l1met, &b_l1met);
   fChain->SetBranchAddress("metnomuons", &metnomuons, &b_metnomuons);
   fChain->SetBranchAddress("nvetomuons", &nvetomuons, &b_nvetomuons);
   fChain->SetBranchAddress("nselmuons", &nselmuons, &b_nselmuons);
   fChain->SetBranchAddress("nvetoelectrons", &nvetoelectrons, &b_nvetoelectrons);
   fChain->SetBranchAddress("nselelectrons", &nselelectrons, &b_nselelectrons);
   fChain->SetBranchAddress("ntaus", &ntaus, &b_ntaus);
   fChain->SetBranchAddress("m_mumu", &m_mumu, &b_m_mumu);
   fChain->SetBranchAddress("m_ee", &m_ee, &b_m_ee);
   fChain->SetBranchAddress("m_mumu_gen", &m_mumu_gen, &b_m_mumu_gen);
   fChain->SetBranchAddress("genlep1_pt", &genlep1_pt, &b_genlep1_pt);
   fChain->SetBranchAddress("genlep1_eta", &genlep1_eta, &b_genlep1_eta);
   fChain->SetBranchAddress("genlep1_phi", &genlep1_phi, &b_genlep1_phi);
   fChain->SetBranchAddress("genlep1_id", &genlep1_id, &b_genlep1_id);
   fChain->SetBranchAddress("genlep2_pt", &genlep2_pt, &b_genlep2_pt);
   fChain->SetBranchAddress("genlep2_eta", &genlep2_eta, &b_genlep2_eta);
   fChain->SetBranchAddress("genlep2_phi", &genlep2_phi, &b_genlep2_phi);
   fChain->SetBranchAddress("genlep2_id", &genlep2_id, &b_genlep2_id);
   fChain->SetBranchAddress("mu1_pt", &mu1_pt, &b_mu1_pt);
   fChain->SetBranchAddress("mu1_eta", &mu1_eta, &b_mu1_eta);
   fChain->SetBranchAddress("mu1_phi", &mu1_phi, &b_mu1_phi);
   fChain->SetBranchAddress("mu2_pt", &mu2_pt, &b_mu2_pt);
   fChain->SetBranchAddress("mu2_eta", &mu2_eta, &b_mu2_eta);
   fChain->SetBranchAddress("mu2_phi", &mu2_phi, &b_mu2_phi);
   fChain->SetBranchAddress("ele1_pt", &ele1_pt, &b_ele1_pt);
   fChain->SetBranchAddress("ele1_eta", &ele1_eta, &b_ele1_eta);
   fChain->SetBranchAddress("ele1_phi", &ele1_phi, &b_ele1_phi);
   fChain->SetBranchAddress("tau1_pt", &tau1_pt, &b_tau1_pt);
   fChain->SetBranchAddress("tau1_eta", &tau1_eta, &b_tau1_eta);
   fChain->SetBranchAddress("tau1_phi", &tau1_phi, &b_tau1_phi);
   fChain->SetBranchAddress("lep_mt", &lep_mt, &b_lep_mt);
   fChain->SetBranchAddress("n_vertices", &n_vertices, &b_n_vertices);
}


void tree_creator2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree_creator2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_creator2_cxx
