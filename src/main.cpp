#include <initializer_list>
#include <cmath>
#include "../include/bdt_analysis.h"

void produce_graphs(bool with_cut) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();

  SuperChains* super_chains         = new SuperChains(&vars, &cut_vars, with_cut);
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;

  BDTAnalysis::create_BDT(bg_chains[0], signal_chain, &vars, super_vars->get_cuts_str_for_tmva());
  BDTAnalysis::evaluate_BDT(bg_chains[0], signal_chain, &vars);

  for (int i = 0; i < vars.size(); i++)
  {
    //HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &cut_vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true);
  theApp.Run();
  return 0;
}
