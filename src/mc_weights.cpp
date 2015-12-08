#include "../include/mc_weights.h"

std::string MCWeights::get_mc_selection_str(DataChain* bg_chain, Variable* variable, std::vector<Variable*>* variables,
																																	bool with_cut)
{
  std::string selection_str = HistoPlot::get_selection(variable, variables, with_cut, false);
  selection_str.insert(selection_str.find("(") + 1, bg_chain->lep_sel + "&&");
  std::cout << selection_str << std::endl;
  return selection_str;
}

double MCWeights::get_nevents(DataChain* data_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string selection)
{
  return HistoPlot::get_histo_integral(HistoPlot::build_1d_histo(data_chain, var, with_cut, false, "goff", variables, selection), with_cut, var);
}

double MCWeights::get_all_bg_in_ctrl(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
                                       std::vector<Variable*>* variables, std::string selection)
{
  double total_integral = 0.0;

  for (int i = 0; i < bg_chains.size(); i++)
  {
  		total_integral += get_nevents(bg_chains[i], var, with_cut, variables, selection);
  }
  std::cout << total_integral << std::endl;
  return total_integral;
}

double MCWeights::calc_mc_weight(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
																																	Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  std::string selection   = get_mc_selection_str(bg_chain, var, variables, with_cut);
	 double data_in_ctrl     = get_nevents(data, var, with_cut, variables, selection);
  double ctrl_mc_in_ctrl  = get_nevents(bg_chain, var, with_cut, variables, selection);
  double other_bg_in_ctrl = get_all_bg_in_ctrl(bg_chains, var, with_cut, variables, selection) - ctrl_mc_in_ctrl;

  return (data_in_ctrl - other_bg_in_ctrl) / ctrl_mc_in_ctrl;
}
