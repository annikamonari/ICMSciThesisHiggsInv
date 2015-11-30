#include "../include/histo_plot.h"
#include "../include/analysis.h"
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

std::vector<Variable*> get_var_vector(Variables variables)
{
		Variable* var_arr[] = {/*variables.jet1_pt, variables.jet2_eta, */variables.forward_tag_eta,
																									/*variables.central_tag_eta, variables.dijet_deta, variables.dijet_dphi,
																									variables.metnomu_x, variables.metnomu_y, */variables.metnomu_significance,/*
																									variables.ht, variables.ht30, variables.sqrt_ht, variables.unclustered_et,
																									variables.jet1metnomu_dphi, variables.jet1metnomu_scalarprod,
																									variables.jet2metnomu_dphi, variables.jetmetnomu_mindphi,
																									variables.alljetsmetnomu_mindphi,*/ variables.dijet_M/*,
																									variables.jet2met_scalarprod, variables.l1met, variables.metnomuons*/};

		std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

		return vars;
}

void produce_graphs() {
		Variables variables;
		std::vector<Variable*> vars 						= get_var_vector(variables);

		Chains chains;
		std::vector<DataChain*> bg_chains = get_bg_chains(chains);
		DataChain* signal_chain 										= chains.signal_chain;
		DataChain* data_chain 												= chains.data_chain;

  for (int i = 0; i < 1; i++) {
	  HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, false, &vars);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  return 0;
}
