#include "data_tree.h"

class DataTree {
public:
  TFile* file;
  char* label;
  TTree* tree;
  LeafVariables* vars;

  void set_branch_addresses() {
    tree->SetBranchAddress("run", &vars->run);
    tree->SetBranchAddress("lumi", &vars->lumi);
    tree->SetBranchAddress("event", &vars->event);
    tree->SetBranchAddress("weight_nolep", &vars->weight_nolep);
    tree->SetBranchAddress("total_weight_lepveto", &vars->total_weight_lepveto);
    tree->SetBranchAddress("total_weight_leptight", &vars->total_weight_leptight);
    tree->SetBranchAddress("puweight_up_scale", &vars->puweight_up_scale);
    tree->SetBranchAddress("puweight_down_scale", &vars->puweight_down_scale);
    tree->SetBranchAddress("topweight_up_scale", &vars->topweight_up_scale);
    tree->SetBranchAddress("topweight_down_scale", &vars->topweight_down_scale);
    tree->SetBranchAddress("jet1_pt", &vars->jet1_pt);
    tree->SetBranchAddress("jet2_pt", &vars->jet2_pt);
    tree->SetBranchAddress("jet3_pt", &vars->jet3_pt);
    tree->SetBranchAddress("jet1_E", &vars->jet1_E);
    tree->SetBranchAddress("jet2_E", &vars->jet2_E);
    tree->SetBranchAddress("jet3_E", &vars->jet3_E);
    tree->SetBranchAddress("jet1_eta", &vars->jet1_eta);
    tree->SetBranchAddress("jet2_eta", &vars->jet2_eta);
    tree->SetBranchAddress("jet3_eta", &vars->jet3_eta);
    tree->SetBranchAddress("forward_tag_eta", &vars->forward_tag_eta);
    tree->SetBranchAddress("central_tag_eta", &vars->central_tag_eta);
    tree->SetBranchAddress("jet1_phi", &vars->jet1_phi);
    tree->SetBranchAddress("jet2_phi", &vars->jet2_phi);
    tree->SetBranchAddress("jet3_phi", &vars->jet3_phi);
    tree->SetBranchAddress("jet_csv1", &vars->jet_csv1);
    tree->SetBranchAddress("jet_csv2", &vars->jet_csv2);
    tree->SetBranchAddress("jet_csv3", &vars->jet_csv3);
    tree->SetBranchAddress("dijet_M", &vars->dijet_M);
    tree->SetBranchAddress("dijet_deta", &vars->dijet_deta);
    tree->SetBranchAddress("dijet_sumeta", &vars->dijet_sumeta);
    tree->SetBranchAddress("dijet_dphi", &vars->dijet_dphi);
    tree->SetBranchAddress("met", &vars->met);
    tree->SetBranchAddress("met_x", &vars->met_x);
    tree->SetBranchAddress("met_y", &vars->met_y);
    tree->SetBranchAddress("metnomu_x", &vars->metnomu_x);
    tree->SetBranchAddress("metnomu_y", &vars->metnomu_y);
    tree->SetBranchAddress("met_significance", &vars->met_significance);
    tree->SetBranchAddress("metnomu_significance", &vars->metnomu_significance);
    tree->SetBranchAddress("sumet", &vars->sumet);
    tree->SetBranchAddress("ht", &vars->ht);
    tree->SetBranchAddress("ht30", &vars->ht30);
    tree->SetBranchAddress("mht", &vars->mht);
    tree->SetBranchAddress("sqrt_ht", &vars->sqrt_ht);
    tree->SetBranchAddress("unclustered_et", &vars->unclustered_et);
    tree->SetBranchAddress("jet1met_dphi", &vars->jet1met_dphi);
    tree->SetBranchAddress("jet2met_dphi", &vars->jet2met_dphi);
    tree->SetBranchAddress("jet1metnomu_dphi", &vars->jet1metnomu_dphi);
    tree->SetBranchAddress("jet2metnomu_dphi", &vars->jet2metnomu_dphi);
    tree->SetBranchAddress("jetmet_mindphi", &vars->jetmet_mindphi);
    tree->SetBranchAddress("jetmetnomu_mindphi", &vars->jetmetnomu_mindphi);
    tree->SetBranchAddress("alljetsmet_mindphi", &vars->alljetsmet_mindphi);
    tree->SetBranchAddress("alljetsmetnomu_mindphi", &vars->alljetsmetnomu_mindphi);
    tree->SetBranchAddress("jetunclet_mindphi", &vars->jetunclet_mindphi);
    tree->SetBranchAddress("metunclet_dphi", &vars->metunclet_dphi);
    tree->SetBranchAddress("metnomuunclet_dphi", &vars->metnomuunclet_dphi);
    tree->SetBranchAddress("dijetmet_scalarSum_pt", &vars->dijetmet_scalarSum_pt);
    tree->SetBranchAddress("dijetmet_vectorialSum_pt", &vars->dijetmet_vectorialSum_pt);
    tree->SetBranchAddress("dijetmet_ptfraction", &vars->dijetmet_ptfraction);
    tree->SetBranchAddress("jet1met_scalarprod", &vars->jet1met_scalarprod);
    tree->SetBranchAddress("jet2met_scalarprod", &vars->jet2met_scalarprod);
    tree->SetBranchAddress("dijetmetnomu_scalarSum_pt", &vars->dijetmetnomu_scalarSum_pt);
    tree->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &vars->dijetmetnomu_vectorialSum_pt);
    tree->SetBranchAddress("dijetmetnomu_ptfraction", &vars->dijetmetnomu_ptfraction);
    tree->SetBranchAddress("jet1metnomu_scalarprod", &vars->jet1metnomu_scalarprod);
    tree->SetBranchAddress("jet2metnomu_scalarprod", &vars->jet2metnomu_scalarprod);
    tree->SetBranchAddress("n_jets_cjv_30", &vars->n_jets_cjv_30);
    tree->SetBranchAddress("n_jets_cjv_20EB_30EE", &vars->n_jets_cjv_20EB_30EE);
    tree->SetBranchAddress("n_jets_15", &vars->n_jets_15);
    tree->SetBranchAddress("n_jets_30", &vars->n_jets_30);
    tree->SetBranchAddress("cjvjetpt", &vars->cjvjetpt);
    tree->SetBranchAddress("passtrigger", &vars->passtrigger);
    tree->SetBranchAddress("passparkedtrigger1", &vars->passparkedtrigger1);
    tree->SetBranchAddress("passparkedtrigger2", &vars->passparkedtrigger2);
    tree->SetBranchAddress("l1met", &vars->l1met);
    tree->SetBranchAddress("metnomuons", &vars->metnomuons);
    tree->SetBranchAddress("nvetomuons", &vars->nvetomuons);
    tree->SetBranchAddress("nselmuons", &vars->nselmuons);
    tree->SetBranchAddress("nvetoelectrons", &vars->nvetoelectrons);
    tree->SetBranchAddress("nselelectrons", &vars->nselelectrons);
    tree->SetBranchAddress("ntaus", &vars->ntaus);
    tree->SetBranchAddress("m_mumu", &vars->m_mumu);
    tree->SetBranchAddress("m_ee", &vars->m_ee);
    tree->SetBranchAddress("m_mumu_gen", &vars->m_mumu_gen);
    tree->SetBranchAddress("genlep1_pt", &vars->genlep1_pt);
    tree->SetBranchAddress("genlep1_eta", &vars->genlep1_eta);
    tree->SetBranchAddress("genlep1_phi", &vars->genlep1_phi);
    tree->SetBranchAddress("genlep1_id", &vars->genlep1_id);
    tree->SetBranchAddress("genlep2_pt", &vars->genlep2_pt);
    tree->SetBranchAddress("genlep2_eta", &vars->genlep2_eta);
    tree->SetBranchAddress("genlep2_phi", &vars->genlep2_phi);
    tree->SetBranchAddress("genlep2_id", &vars->genlep2_id);
    tree->SetBranchAddress("mu1_pt", &vars->mu1_pt);
    tree->SetBranchAddress("mu1_eta", &vars->mu1_eta);
    tree->SetBranchAddress("mu1_phi", &vars->mu1_phi);
    tree->SetBranchAddress("mu2_pt", &vars->mu2_pt);
    tree->SetBranchAddress("mu2_eta", &vars->mu2_eta);
    tree->SetBranchAddress("mu2_phi", &vars->mu2_phi);
    tree->SetBranchAddress("ele1_pt", &vars->ele1_pt);
    tree->SetBranchAddress("ele1_eta", &vars->ele1_eta);
    tree->SetBranchAddress("ele1_phi", &vars->ele1_phi);
    tree->SetBranchAddress("tau1_pt", &vars->tau1_pt);
    tree->SetBranchAddress("tau1_eta", &vars->tau1_eta);
    tree->SetBranchAddress("tau1_phi", &vars->tau1_phi);
    tree->SetBranchAddress("lep_mt", &vars->lep_mt);
    tree->SetBranchAddress("n_vertices", &vars->n_vertices);
  }

  void get_data() {
    UInt_t nentries = tree->GetEntries();

    for(int i = 0; i < nentries; i++) {
      tree -> GetEntry(i);
    }
  }

  DataTree(TFile* data_file, char* tree_name) {
    file = data_file;
    label = tree_name;
    tree = (TTree*) file -> Get("LightTree");
    vars = new LeafVariables();

    set_branch_addresses();
    get_data();
  }

  


  // pass in &var_name e.g. &n_vertices - TODO: make same method for UInt_t
  void create_1d_plot(Double_t* var_name, int bins, int x_min, int x_max) {
    TH1D* histo1 = new TH1D(label, label, bins, x_min, x_max);
  }



};
