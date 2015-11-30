#include <initializer_list>
#include <cmath>
#include "../include/super_vars.h"




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
