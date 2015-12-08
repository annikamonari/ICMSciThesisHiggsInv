#include <initializer_list>
#include <cmath>
#include "../include/histo_plot.h"
#include "../include/mc_weights.h"

void produce_graphs() {
		SuperVars* super_vars = new SuperVars();
		std::vector<Variable*> vars = super_vars->get_discriminating_vars();
		std::vector<Variable*> cut_vars = super_vars->get_signal_cut_vars();

		SuperChains* super_chains 								= new SuperChains();
		std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
		DataChain* signal_chain 										= super_chains->signal_chain;
		DataChain* data_chain 												= super_chains->data_chain;

  for (int i = 0; i < vars.size(); i++)
  {
  		//HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &cut_vars);
  		std::string selection = MCWeights::get_mc_selection_str(bg_chains[0], vars[i], &cut_vars, true);
  		MCWeights::calc_mc_weight(data_chain, bg_chains, bg_chains[0], vars[0], true, &cut_vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();
  theApp.Run();
  return 0;
}
