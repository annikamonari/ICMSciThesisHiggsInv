#include "../include/variables.h"
#include <initializer_list>
#include <cmath>

std::vector<DataChain*> get_bg_chains(Chains chains)
{
		DataChain* bg_chain_arr[] = {chains.bg_zll, chains.bg_wjets_ev, chains.bg_wjets_muv,
																															chains.bg_wjets_tauv, chains.bg_top, chains.bg_vv,
																															chains.bg_zjets_vv, chains.bg_qcd};

		std::vector<DataChain*> bg_chains (bg_chain_arr, bg_chain_arr + sizeof(bg_chain_arr) / sizeof(bg_chain_arr[0]));

		return bg_chains;
}


void produce_graphs() {
		Variables* variables 							= new Variables();
		std::vector<Variable*> vars = variables->get_var_vector();

		Chains chains;
		std::vector<DataChain*> bg_chains = get_bg_chains(chains);
		DataChain* signal_chain 										= chains.signal_chain;
		DataChain* data_chain 												= chains.data_chain;

  for (int i = 0; i < 1; i++)
  {
  		HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();
  theApp.Run();
  return 0;
}
