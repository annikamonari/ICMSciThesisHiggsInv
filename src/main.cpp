#include <initializer_list>
#include <cmath>
#include "../include/super_vars.h"
#include "../include/super_chains.h"



void produce_graphs() {
		SuperVars* super_vars = new SuperVars();
		std::vector<Variable*> vars = super_vars->get_var_vector();

		SuperChains* super_chains = new SuperChains();
		std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
		DataChain* signal_chain 										= super_chains->signal_chain;
		DataChain* data_chain 												= super_chains->data_chain;

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
