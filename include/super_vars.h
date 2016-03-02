#ifndef Super_Vars_h
#define Super_Vars_h

#include <string>
#include "../include/variable.h"
#include "../include/histo_plot.h"

class SuperVars 
{
 public:
  Variable* jet1_E;
  Variable* jet2_E;
  Variable* forward_tag_eta;
  Variable* dijet_deta;
  Variable* metnomu_significance;
  Variable* sqrt_ht;
  Variable* alljetsmetnomu_mindphi;
  Variable* dijet_M;
  Variable* metnomuons;
  
  Variable* jet1_pt;
  Variable* jet2_pt;
  Variable* jet1_eta;
  Variable* jet2_eta;
  Variable* jet1_phi;
  Variable* jet2_phi;
  Variable* jet_csv1;
  Variable* jet_csv2;
  Variable* dijet_dphi;
  Variable* metnomu_x;
  Variable* metnomu_y;
  Variable* sumet;
  Variable* mht;
  Variable* unclustered_et;
  Variable* jetmet_mindphi;
  Variable* jetmetnomu_mindphi;
  Variable* jetunclet_mindphi;
  Variable* metnomuunclet_dphi;
  Variable* dijetmetnomu_vectorialSum_pt;
  Variable* dijetmetnomu_ptfraction;
  Variable* jet1metnomu_scalarprod;
  Variable* jet2metnomu_scalarprod;
  Variable* n_jets_cjv_30;
  Variable* n_jets_cjv_20EB_30EE;
  Variable* n_jets_15;
  Variable* n_jets_30;
  Variable* cjvjetpt;
  Variable* l1met;
  Variable* m_mumu;
  Variable* m_mumu_gen;
  Variable* n_vertices;
  

  SuperVars();

  std::vector<Variable*> get_discriminating_vars();

  std::vector<Variable*> get_signal_cut_vars();

  std::string get_final_cuts_str();

  std::string get_cuts_str_for_tmva();
};



#endif
