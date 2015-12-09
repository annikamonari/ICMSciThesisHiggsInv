#include "../include/mc_weights.h"

std::string MCWeights::get_mc_selection_str(DataChain* bg_chain, Variable* variable, std::vector<Variable*>* variables)
{
  std::string selection_str = variable->build_multicut_selection(false, variables);
  selection_str.insert(selection_str.find("(") + 1, bg_chain->lep_sel + "&&");

  return selection_str;
}

double MCWeights::get_nevents(DataChain* data_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string selection)
{
  return HistoPlot::get_histo_integral(build_histo(data_chain, var, variables, with_cut, false, "goff", selection), with_cut, var);
}

double MCWeights::get_all_bg_in_ctrl(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
                                       std::vector<Variable*>* variables, std::string selection)
{
  double total_integral = 0.0;

  for (int i = 0; i < bg_chains.size(); i++)
  {
  		total_integral += get_nevents(bg_chains[i], var, with_cut, variables, selection);
  }

  return total_integral;
}

double MCWeights::calc_mc_weight(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  std::string selection   = get_mc_selection_str(bg_chain, var, variables);
  double data_in_ctrl     = get_nevents(data, var, with_cut, variables, selection);
  double ctrl_mc_in_ctrl  = get_nevents(bg_chain, var, with_cut, variables, selection);
  double other_bg_in_ctrl = get_all_bg_in_ctrl(bg_chains, var, with_cut, variables, selection) - ctrl_mc_in_ctrl;
			//std::cout<<"calc mc weights func in mc_wieghts gives data in control =  "<<data_in_ctrl<<"\n"<<"bg to be weighted = "<<ctrl_mc_in_ctrl<<"\n"<<"other gb = "<<other_bg_in_ctrl<<"\n";

  return (data_in_ctrl - other_bg_in_ctrl) / ctrl_mc_in_ctrl;
}

TH1F* MCWeights::build_histo(DataChain* data_chain, Variable* variable,std::vector<Variable*>* variables, bool with_cut, bool is_signal,const char* option,std::string selection)
{
  std::string var_arg   = variable->build_var_string(data_chain->label, with_cut);
  std::string selection_str;

  if (selection == "")
  {
  		selection_str = get_selection(variable, variables, with_cut, is_signal, data_chain);
  }
  else
  {
  		selection_str = selection;
  }

  data_chain->chain->Draw(var_arg.c_str(), selection_str.c_str(), option);

  return (TH1F*)gDirectory->Get(data_chain->label);
}

std::string MCWeights::get_selection(Variable* variable, std::vector<Variable*>* variables,bool with_cut, bool is_signal, DataChain* bg_chain)
{
		std::string selection;

		if ((variables != NULL) && (with_cut))
	 {
	  	selection = variable->build_multicut_selection(is_signal, variables);
	 }
	 else
	 {
	  	selection = variable->build_selection_string(with_cut, is_signal);
	 }

		selection.insert(selection.find("(") + 1, lep_sel_default() + "&&");

		return selection;
}

