#include "../include/data_card.h"


double DataCard::get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  TH1F* signalh = HistoPlot::build_1d_histo(signal_chain, var, with_cut, false, "goff", variables);
  double total_signal = HistoPlot::get_histo_integral(signalh, with_cut, var);

  double sig_sqrt = std::pow(total_signal,0.5);

  return 1+(sig_sqrt/total_signal);
}

double* DataCard::get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double bg_errors[bg_chains.size()];
  double rates = get_rates(data, sbg_chains,  bg_chain,var,with_cut, variables);
  for(int i=0; i<bg_chains.size();i++)
  {
    bg_errors_no = HistoPlot::single_bg_error(data, bg_chains, bg_chains[i], var, with_cut, variables);
    bg_errors[i] = 1+(bg_errors_no/rates[i]);
  }
  return bg_errors;
}
double get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double rates[bg_chains.size()];
 
  for(int i=0; i<bg_chains.size();i++)
  {
    double weight = MCWeights::calc_mc_weight(data, bg_chains, bg_chain, var, with_cut, variables);
    double N = get_histo_integral(bg, with_cut, var);//integral of single bg
    rates[i]=N*weight;
  }  
   return rates;
}

/*
int imax = 1;//bin number
int jmax = bg_chains.size(); //number of backgrounds
int kmax;//number of indepenmdant sources of uncertaintied
bool with_cut = true;*/

