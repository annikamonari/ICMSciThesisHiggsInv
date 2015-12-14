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

  SuperVars();

  std::vector<Variable*> get_discriminating_vars();

  std::vector<Variable*> get_signal_cut_vars();

  std::string get_cuts_str_for_tmva();
};



#endif
