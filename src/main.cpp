#include <initializer_list>
#include <cmath>
#include "../include/histo_plot.h"

void produce_graphs() {
		SuperVars* super_vars = new SuperVars();
		std::vector<Variable*> vars = super_vars->get_var_vector();
		std::vector<Variable*> cut_vars = super_vars->get_cut_vector();

		SuperChains* super_chains 								= new SuperChains();
		std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
		DataChain* signal_chain 										= super_chains->signal_chain;
		DataChain* data_chain 												= super_chains->data_chain;

  for (int i = 0; i < vars.size(); i++)
  {
  		HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &cut_vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();
  theApp.Run();
  return 0;
}
