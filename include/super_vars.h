#ifndef Super_Vars_h
#define Super_Vars_h

#include "../include/variable.h"

class SuperVars {
public:
		Variable* jet1_pt;
		Variable* jet2_eta;
		Variable* forward_tag_eta;
		Variable* central_tag_eta;
		Variable* dijet_deta;
		Variable* dijet_dphi;
		Variable* metnomu_x;
		Variable* metnomu_y;
		Variable* metnomu_significance;
		Variable* ht;
		Variable* ht30;
		Variable* sqrt_ht;
		Variable* unclustered_et;
		Variable* jet1metnomu_dphi;
		Variable* jet1metnomu_scalarprod;
		Variable* jet2metnomu_dphi;
		Variable* jetmetnomu_mindphi;
		Variable* alljetsmetnomu_mindphi;
		Variable* dijet_M;
		Variable* jet2met_scalarprod;
		Variable* l1met;
		Variable* metnomuons;
		Variable* m_mumu;
		Variable* met;
		Variable* met_significance;

  SuperVars();

  std::vector<Variable*> get_var_vector();

  std::vector<Variable*> get_cut_vector();


};



#endif
