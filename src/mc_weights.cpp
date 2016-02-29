#include "../include/mc_weights.h"

std::string MCWeights::get_mc_selection_str(DataChain* bg_chain, Variable* variable, 
                                            std::vector<Variable*>* variables, std::string mva_cut_str)
{
  std::string selection_str = variable->build_multicut_selection(false, variables);

  if (bg_chain->lep_sel != "")
  {
  	 selection_str.insert(selection_str.find("(") + 1, bg_chain->lep_sel);
  }

  if (selection_str.find("(&&", 0) == 0)
  	{
  		 selection_str.erase(1, 2);
  	}
  //if (variable->name_styled = "MVA Output"){std::cout<<"mc selection string : "<<selection_str<<"\n";}
  selection_str = HistoPlot::add_mva_cut_to_selection(selection_str, mva_cut_str);
  return selection_str;
}

double MCWeights::get_nevents(DataChain* data_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables, 
                              std::string mc_selection, std::string mva_cut_str)
{

  TH1F* histo = HistoPlot::build_1d_histo(data_chain, var, with_cut, false, "goff", 
variables, mc_selection, mva_cut_str);


int total = HistoPlot::get_histo_integral(histo, with_cut, var);


  return total;
}

double MCWeights::get_all_bg_in_ctrl(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
                                     std::vector<Variable*>* variables, std::string mc_selection, std::string mva_cut_str)
{
  double total_integral = 0.0;

  for (int i = 0; i < bg_chains.size(); i++)
  {
    total_integral += get_nevents(bg_chains[i], var, with_cut, variables, mc_selection, mva_cut_str);
  }

  return total_integral;
}

double MCWeights::calc_mc_weight(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables,std::string mva_cut)
{
  double mc_weight;
  std::string mc_selection  = get_mc_selection_str(bg_chain, var, variables, mva_cut);
  double data_in_ctrl     = get_nevents(data, var, with_cut, variables, mc_selection, mva_cut);
//std::cout<<"data in control region: "<<data_in_ctrl<<"\n";
  double ctrl_mc_in_ctrl  = get_nevents(bg_chain, var, with_cut, variables, mc_selection, mva_cut);
//std::cout<<"background to be weighted in control region: "<<ctrl_mc_in_ctrl<<"\n";
  double other_bg_in_ctrl = get_all_bg_in_ctrl(bg_chains, var, with_cut, variables, mc_selection, mva_cut) - ctrl_mc_in_ctrl;
//std::cout<<"other BGs in control region: "<<other_bg_in_ctrl<<"\n";

  if(ctrl_mc_in_ctrl!=0){ mc_weight = (data_in_ctrl - other_bg_in_ctrl) / ctrl_mc_in_ctrl;}
  else{mc_weight = 1;}
  
  if (mc_weight<0) {mc_weight=1;
std::cout<<" other bg in control bigger than data -> negative MC weight\n";} 
std::cout<<"mc weights: "<<mc_weight;
  return mc_weight;
}

double MCWeights::calc_weight_error(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string mva_cut)
{
  std::string mc_selection = get_mc_selection_str(bg_chain, var, variables,mva_cut);

  double data_N_C       = get_nevents(data, var, with_cut, variables, mc_selection, mva_cut);
//if (var->name_styled = "MVA Output"){std::cout<<"data gen fine for output\n";}
  double MC_N_C         = get_nevents(bg_chain, var, with_cut, variables, mc_selection, mva_cut); 
double weight_error;
if(MC_N_C!=0){

//if (var->name_styled = "MVA Output"){std::cout<<"mc selection gen fine for output\n";}

  double bg_N_C         = get_all_bg_in_ctrl(bg_chains, var, with_cut, variables, mc_selection, mva_cut) - MC_N_C;
  double sigma_data_N_C = std::pow(data_N_C, 0.5);
  double sigma_MC_N_C   = std::pow(MC_N_C, 0.5);
  double sigma_bg_N_C   = std::pow(bg_N_C, 0.5);
  double err1           = sigma_data_N_C/MC_N_C;
  double err2           = sigma_bg_N_C/MC_N_C;
  double err3           = (data_N_C- bg_N_C)/(pow(MC_N_C,1.5));
  double error_sq       = std::pow(err1,2) + std::pow(err2,2) + std::pow(err3,2);
  weight_error   = std::pow(error_sq, 0.5);
}
else if (MC_N_C==0){weight_error=1;}
  return weight_error;

}


