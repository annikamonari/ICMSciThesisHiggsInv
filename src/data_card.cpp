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


double DataCard::get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double rates[bg_chains.size()];
 
  for(int i=0; i<bg_chains.size();i++)
  {
    double weight = MCWeights::calc_mc_weight(data, bg_chains, bg_chain, var, with_cut, variables);
    double N = 1; //HistoPlot::get_histo_integral(bg_chains[i], with_cut, var);//integral of single bg
    rates[i]=N*weight;
  }  
   return rates;
}

int DataCard::test() {

  std::fstream fs;
  fs.open ("test1.txt", std::fstream::in | std::fstream::out | std::fstream::app);

  fs << "\n more lorem ipsum \n";
  fs << "test  0   0   9";

  fs.close();

  return 0;
}

std::string jmax_string(int jmax)
{
  std::string jmax_str = "jmax ";
  jmax_str += std::to_string(jmax);
  jmax_str += "  number of backgrounds";

  return jmax_str;
}

std::string imax_string(int imax)
{
  return "imax 1  number of channels";
}

std::string kmax_string(int kmax)
{
  std::string kmax_str = "kmax ";
  kmax_str += std::to_string(kmax);
  kmax_str += "  number of nuisance parameters (sources of systematical uncertainties)";

  return kmax_str;
}

std::string bin_header_string()
{
	 return "bin 1";
}

std::string bin_observation_string(int nbins)
{
  std::string bin_obs_str;
  bin_obs_str += "observation ";
  bin_obs_str += std::to_string(nbins);

  return bin_obs_str;
}

std::string bin_grid_line(int cols)
{
  std::string bin_grid_str = "bin";
	 for (int i = 0; i < cols; i++)
  {
    bin_grid_str += "   1";
  }

	 return bin_grid_str;
}

std::string process_labels(std::vector<DataChain*> bg_chains, DataChain* signal_chain)
{
  std::string process_labels_str = "process   ";
  process_labels_str.append(signal_chain->label);

  for (int i = 0; i < bg_chains.size(); i++)
  {
    process_labels_str += "   ";
    process_labels_str.append(bg_chains[i]->label);
  }

  return process_labels_str;
}

std::string dashed_line()
{
  return "------------";
}

std::string process_2_string(std::vector<int> line_2_vals)
{
	 for (int i = 0; i < line_2_vals.size(); i++)
	 	{

	 	}
}

/*
int imax = 1;//bin number
int jmax = bg_chains.size(); //number of backgrounds
int kmax;//number of indepenmdant sources of uncertaintied
bool with_cut = true;*/

