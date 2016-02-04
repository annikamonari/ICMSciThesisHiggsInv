/*#include "../include/data_card.h"
#include <sstream>
#include <string>

double DataCard::get_signal_error(DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  TH1F* signalh = HistoPlot::build_1d_histo(signal_chain, var, with_cut, false, "goff", variables);
  double total_signal = HistoPlot::get_histo_integral(signalh, with_cut, var);

  double sig_sqrt = std::pow(total_signal,0.5);

  return 1+(sig_sqrt/total_signal);
}

std::vector<double> DataCard::get_bg_errors(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double bg_errors[bg_chains.size()];
  std::vector<double> rates = get_rates(data, bg_chains, signal_chain, var,with_cut, variables);
  for(int i=0; i<bg_chains.size();i++)
  {
    double bg_errors_no = HistoPlot::single_bg_error(data, bg_chains, bg_chains[i], var, with_cut, variables);
    bg_errors[i] = 1+(bg_errors_no/rates[i+1]);
  }
  std::vector<double> bg_error_vector (bg_errors, bg_errors + sizeof(bg_errors) / sizeof(bg_errors[0]));

  return bg_error_vector;
}

std::vector<double> DataCard::get_rates(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* signal_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables)
{//returns total number of each background as an array of doubles.
  double rates[bg_chains.size() + 1];
  TH1F* signal_histo = HistoPlot::build_1d_histo(signal_chain, var, with_cut, true, "goff", variables);
  rates[0] = HistoPlot::get_histo_integral(signal_histo, with_cut, var);
 
  for(int i = 0; i < bg_chains.size();i++)
  {
    double weight = MCWeights::calc_mc_weight(data, bg_chains, bg_chains[i], var, with_cut, variables);
    TH1F* histo = HistoPlot::build_1d_histo(bg_chains[i], var, with_cut, false, "goff", variables, "", weight);
    double N = HistoPlot::get_histo_integral(histo, with_cut, var);//integral of single bg
    rates[i + 1]=N*weight;
  }
  std::vector<double> rates_vector (rates, rates + sizeof(rates) / sizeof(rates[0]));

  return rates_vector;
}

std::vector<int> DataCard::process_line_2(int size)
{
  int p_line[size];
  for(int i=0;i<size;i++)
    {
     p_line[i] = i; 
    }
  std::vector<int> pl_vector (p_line, p_line + sizeof(p_line) / sizeof(p_line[0]));
  return pl_vector;

}

int DataCard::test() {

  std::fstream fs;
  fs.open ("test1.txt", std::fstream::in | std::fstream::out | std::fstream::app);

  fs << "\n more lorem ipsum \n";
  fs << "test  0   0   9";

  fs.close();

  return 0;
}
std::string DataCard::int_to_str(int sint)
{
  std::ostringstream ss;
  ss << sint;
  std::string str(ss.str());
  return str;
}
std::string DataCard::jmax_string(int jmax)
{
  std::string jmax_str = "jmax ";
  jmax_str += int_to_str(jmax);

  jmax_str += "  number of backgrounds \n";

  return jmax_str;
}

std::string DataCard::imax_string()
{
  return "imax 1  number of channels \n";
}

std::string DataCard::kmax_string(int kmax)
{
  std::string kmax_str = "kmax ";
  kmax_str += int_to_str(kmax);
  kmax_str += "  number of nuisance parameters (sources of systematical uncertainties) \n";
  return kmax_str;
}

std::string DataCard::bin_header_string()
{
	 return "bin 1 \n";
}

std::string DataCard::bin_observation_string(int nbins)
{
  std::string bin_obs_str;
  bin_obs_str += "observation ";
  bin_obs_str += int_to_str(nbins);
  bin_obs_str += " \n";


  return bin_obs_str;
}

std::string DataCard::bin_grid_line(int cols)
{
  std::string bin_grid_str = "bin";
	 for (int i = 0; i < cols; i++)
  {
    bin_grid_str += "   1";
  }
  bin_grid_str += " \n";

	 return bin_grid_str;
}

std::string DataCard::process_labels(std::vector<DataChain*> bg_chains, DataChain* signal_chain)
{
  std::string process_labels_str = "process   ";
  process_labels_str.append(signal_chain->label);

  for (int i = 0; i < bg_chains.size(); i++)
  {
    process_labels_str += "   ";
    process_labels_str.append(bg_chains[i]->label);
  }
  process_labels_str += " \n";

  return process_labels_str;
}

std::string DataCard::dashed_line()
{
  return "------------ \n";
}

//signal is 0, backgrounds are all 1 onwards
std::string DataCard::process_2_string(std::vector<int> line_2_vals)
{
	 std::string line_2 = "process";
	 for (int i = 0; i < line_2_vals.size(); i++)
	 	{
	 		line_2 += "   ";
    line_2 += int_to_str(line_2_vals[i]);
	 	}
  line_2 += "\n";

	 return line_2;
}

std::string DataCard::rate_string(std::vector<double> rates)
{
	 std::string rate_str = "rate";
  for (int i = 0; i < rates.size(); i++)
  {
  		rate_str += "   ";
  		rate_str += int_to_str(rates[i]);
  }
  rate_str += " \n";

  return rate_str;
}

std::vector<std::vector<double> > DataCard::get_uncertainty_vectors(double signal_error, std::vector<double> bg_errors)
{
  int size = bg_errors.size() + 1;
  std::vector<std::vector<double> > error_lines(size, std::vector<double>(size));
  error_lines[0] = get_zeros(size);
  error_lines[0][0] = signal_error;

  for (int i = 0; i < size; i++)
  {
  		error_lines[i+1] = get_zeros(size);
    error_lines[i+1][i+1] = bg_errors[i];
  }

  return error_lines;
}

std::string DataCard::get_uncertainties_string(std::vector<std::vector<double> > uncertainty_vectors)
{
  std::string uncertainties = "";

  for (int i = 0; i < uncertainty_vectors.size(); i++)
  	{
    uncertainties += ("uncertainty" + int_to_str(i) + " lnN  ");
    uncertainties += get_single_uncertainty_str(uncertainty_vectors[i]);
    uncertainties += "\n";
  	}

  return uncertainties;
}

std::string DataCard::get_systematic_string(DataChain* data, std::vector<DataChain*> bg_chains,
																																												DataChain* signal_chain, Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
  double signal_error = get_signal_error(signal_chain, var, with_cut, variables);
  std::vector<double> bg_errors = get_bg_errors(data, bg_chains, signal_chain, var, with_cut, variables);
  std::vector<std::vector<double> > uncertainty_vectors = DataCard::get_uncertainty_vectors(signal_error, bg_errors);

  return get_uncertainties_string(uncertainty_vectors);
}

std::string DataCard::get_single_uncertainty_str(std::vector<double> single_uncertainty_vector)
{
	 std::string vector_str = "";
	 for (int i = 0; i < single_uncertainty_vector.size(); i++)
	 {
    vector_str += "   ";
	 		if (single_uncertainty_vector[i] == 0)
    	{
      vector_str += "-";
    	}
	 		else
	 			{
	 				vector_str += int_to_str(single_uncertainty_vector[i]);
	 			}
	 }

	 return vector_str;
}

std::vector<double> DataCard::get_zeros(int size)
{
  double zero_arr[size];
  for (int i = 0; i < size; i++)
  {
    zero_arr[i] = 0;
  }
  std::vector<double> zeros (zero_arr, zero_arr + sizeof(zero_arr) / sizeof(zero_arr[0]));

  return zeros;
}

void DataCard::create_datacard(DataChain* data_chain, DataChain* signal_chain, std::vector<DataChain*> bg_chains,
																					Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
	 std::fstream fs;
	 fs.open ("test1.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  int size = 1 + bg_chains.size();
	 fs << imax_string();
  fs << jmax_string(size - 1);
  fs << kmax_string(size);
  fs << dashed_line();
  fs << bin_header_string();
  fs << bin_observation_string(get_total_nevents(bg_chains, var, with_cut, variables));
  fs << dashed_line();
  fs << bin_grid_line(size);
  fs << process_2_string(process_line_2(size));
  fs << rate_string(get_rates(data_chain, bg_chains, signal_chain, var, with_cut, variables));
  fs << dashed_line();
  fs << get_systematic_string(data_chain, bg_chains, signal_chain, var, with_cut, variables);
	 fs.close();
}

double DataCard::get_total_nevents(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
	 double total = 0;
	 for (int i = 0; i < bg_chains.size(); i++)
	 	{
	 		TH1F* histo = HistoPlot::build_1d_histo(bg_chains[i], var, with_cut, false, "goff", variables);
	 		double integral = HistoPlot::get_histo_integral(histo, with_cut, var);
	 		total += integral;
	 	}

	 return total;
}

/*
int imax = 1;//bin number
int jmax = bg_chains.size(); //number of backgrounds
int kmax;//number of indepenmdant sources of uncertaintied
bool with_cut = true;*/

