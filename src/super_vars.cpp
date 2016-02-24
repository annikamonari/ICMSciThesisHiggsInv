#include "../include/super_vars.h"

SuperVars::SuperVars()
{
  forward_tag_eta        = new Variable("forward_tag_eta","Forward Tag #eta","-5.0","5.0","1.8",
                                        "5.0","60","1", "", true);
  dijet_deta             = new Variable("dijet_deta","Dijet #Delta#eta","3.5","8.0","4.2","8.0","25","1", "");
  metnomu_significance   = new Variable("metnomu_significance","MET Significance (No Muons)",
                                        "3.0","12.0","3.5","","50","1", "");
  sqrt_ht                = new Variable("sqrt_ht","Square Root HCAL Scalar Sum of Energy","0.0","35.0","9.0",
                                        "18.0","75","1", "GeV^{0.5}");
  alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi","All Jets - MET Min. #Delta#phi (No Muons)",
                                        "0.0","3.5","2.0","3.0","40","1", "");
  dijet_M                = new Variable("dijet_M","Dijet Mass","0.0","2000.0","800.0","","50","1", "GeV");
  metnomuons             = new Variable("metnomuons","MET (No Muons)","0.0","400.0","120.0","",
                                        "50","1", "GeV");
  jet1_E                 = new Variable("jet1_E","Jet1E","0.0","5000.0","50.0","","30","100", "GeV");
  jet2_E                 = new Variable("jet2_E","Jet2E","0.0","5000.0","45.0","","30","100", "GeV");
}

std::vector<Variable*> SuperVars::get_discriminating_vars()
{
  Variable* var_arr[] = {
  	                      alljetsmetnomu_mindphi, forward_tag_eta, dijet_deta, metnomu_significance,
  	                      sqrt_ht, dijet_M, metnomuons
  	                     };

  std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

  return vars;
}

std::vector<Variable*> SuperVars::get_signal_cut_vars()
{
  Variable* var_arr[] =  {alljetsmetnomu_mindphi, metnomu_significance, dijet_deta, jet1_E, jet2_E};

  std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

  return vars;
}


std::string SuperVars::get_final_cuts_str()
{
	 std::vector<Variable*> cut_vars = get_signal_cut_vars();
	 std::string cuts_str            = cut_vars[0]->build_multicut_selection(false, &cut_vars);

	 cuts_str.insert(cuts_str.find("(") + 1, HistoPlot::lep_sel_default());

	 return cuts_str;
}

std::string SuperVars::get_cuts_str_for_tmva()
{
  std::string cut_str = HistoPlot::replace_all(
  		                      HistoPlot::replace_all(
  		                     		 HistoPlot::replace_all(get_final_cuts_str(),
																																																			"(", " "),
																																																 "*total_weight_lepveto", ""),
																																														")", " ");

  return cut_str;
}
