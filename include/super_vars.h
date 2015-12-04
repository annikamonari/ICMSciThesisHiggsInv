#ifndef Super_Vars_h
#define Super_Vars_h

#include "../include/variable.h"

class SuperVars {
public:
		Variable* jet1_E;
		Variable* jet2_E;
		Variable* forward_tag_eta;
		Variable* dijet_deta;
		Variable* dijet_dphi;
		Variable* metnomu_significance;
		Variable* sqrt_ht;
		Variable* alljetsmetnomu_mindphi;
		Variable* dijet_M;
		Variable* metnomuons;
		Variable* m_mumu;

		/*
		 -- Unused Variables --
		Variable* metnomu_x;
		Variable* metnomu_y;
		Variable* central_tag_eta;
		Variable* jetmetnomu_mindphi;
		Variable* unclustered_et;
		Variable* ht;
		Variable* ht30;
		Variable* jet1metnomu_dphi;
		Variable* jet1metnomu_scalarprod;
		Variable* jet2metnomu_dphi;
		Variable* jet2met_scalarprod;
		Variable* l1met;
		Variable* jet1_pt;
		Variable* jet2_eta;
		Variable* nvetomuons;
		Variable* nvetoelectrons;
		Variable* ntaus;
		Variable* nselelectrons;
		Variable* nselmuons;
		*/

  SuperVars();

  std::vector<Variable*> get_var_vector();

  std::vector<Variable*> get_cut_vector();


};



#endif
