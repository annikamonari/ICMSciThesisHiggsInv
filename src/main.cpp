#include <initializer_list>
#include <cmath>
#include "../include/histo_plot.h"

void produce_graphs(bool with_cut) {
		SuperVars* super_vars = new SuperVars();
		std::vector<Variable*> vars = super_vars->get_var_vector();
		std::vector<Variable*> cut_vars = super_vars->get_cut_vector();

		SuperChains* super_chains 								= new SuperChains(&vars, &cut_vars, with_cut);
		std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
		DataChain* signal_chain 										= super_chains->signal_chain;
		DataChain* data_chain 												= super_chains->data_chain;
std::cout<< "bg chain size: "<<bg_chains.size()<<"\n";
std::cout<< "var size: "<<vars.size()<<"\n";

  for (int i = 1; 2/*i < vars.size()*/; i++)
  {
  		HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, with_cut, &cut_vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true);
  theApp.Run();
  return 0;
}
