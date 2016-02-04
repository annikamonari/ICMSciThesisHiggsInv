#include "../include/data_card.h"


double DataCard::get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  TH1F* signalh = HistoPlot::build_1d_histo(signal_chain, var, with_cut, false, "goff", variables);
  double total_signal = HistoPlot::get_histo_integral(signalh, with_cut, var);

  double sig_sqrt = std::pow(total_signal,0.5);

  return 1+(sig_sqrt/total_signal);
}

 std::vector<double> DataCard::get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double bg_errors[std::vector<int> bin_line()
{
}
];
  double rates = get_rates(data, bg_chains,var,with_cut, variables);
  for(int i=0; i<bg_chains.size();i++)
  {
    bg_errors_no = HistoPlot::single_bg_error(data, bg_chains, bg_chains[i], var, with_cut, variables);
    bg_errors[i] = 1+(bg_errors_no/rates[i]);
  }
  std::vector<double> mc_weights_vector (bg_errors, bg_errors + sizeof(bg_errors) / sizeof(bg_errors[0]));
  return bg_errors_vector;
}
std::vector<double> get_rates(DataChain* data, std::vector<DataChain*> bg_chains,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{//returns total number of each background as an array of doubles.
  double rates[bg_chains.size()];
 
  for(int i=0; i<bg_chains.size();i++)
  {
    double weight = MCWeights::calc_mc_weight(data, bg_chains, bg_chains[i], var, with_cut, variables);
    double N = HistoPlot::get_histo_integral(bg_chains[i], with_cut, var);//integral of single bg
    rates[i]=N*weight;
  }
  std::vector<double> rates_vector (rates, rates + sizeof(rates) / sizeof(rates[0]));
  return rates_vector;
}

std::vector<int> bin_line(std::vector<DataChain*> bg_chains)
{
  int line_length = bg_chains.size()+1;// 1 for signal
  int b_line[line_length];
  for(int i=0;i<line_length;i++)
  {
   b_line[i] = 1; 
  }
  std::vector<int> bl_vector (b_line, b_line + sizeof(b_line) / sizeof(b_line[0]));
  return bl_vector;
}
std::vector<int> process_line_2(std::vector<DataChain*> bg_chains)
{
  int line_length = bg_chains.size()+1;// 1 for signal
  int p_line[line_length];
  for(int i=0;i<line_length;i++)
    {
     p_line[i] = i; 
    }
  std::vector<int> pl_vector (p_line, p_line + sizeof(p_line) / sizeof(p_line[0]));
  return pl_vector;

}

/*
int imax = 1;//bin number
int jmax = bg_chains.size(); //number of backgrounds
int kmax;//number of indepenmdant sources of uncertaintied
bool with_cut = true;*/

