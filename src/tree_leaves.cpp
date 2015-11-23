#include "../include/tree_leaves.h"

void TreeLeaves::set_branch_addresses(TChain* chain) {
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

