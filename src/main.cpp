#include "../include/histo_plot.h"
#include "../include/analysis.h"
#include <initializer_list>
#include <cmath>

void produce_graphs() {
	Variables variables;
	Chains chains;

	Variable* var_arr[] = {jet1_pt, jet2_eta, forward_tag_eta/*, central_tag_eta, dijet_deta/*, dijet_dphi, metnomu_x, metnomu_y,
						   metnomu_significance, ht, ht30, sqrt_ht, unclustered_et, jet1metnomu_dphi, jet1metnomu_scalarprod,
						   jet2metnomu_dphi, jetmetnomu_mindphi, alljetsmetnomu_mindphi, dijet_M, jet2met_scalarprod, l1met,
						   metnomuons*/};

	std::vector<Variable*> variables (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

  DataChain* bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend);
  DataChain* bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
  DataChain* bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
  DataChain* bg_top        = new DataChain(top, top_label, top_legend);
  DataChain* bg_vv         = new DataChain(vv, vv_label, vv_legend);
  DataChain* bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
  DataChain* bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
  DataChain* signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
  DataChain* data_chain    = new DataChain(data, data_label, data_legend);

  DataChain* myDataChain[] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv,bg_top, bg_vv, bg_zjets_vv, bg_qcd};

  std::vector<DataChain*> bg_chains (myDataChain, myDataChain + sizeof(myDataChain) / sizeof(myDataChain[0]));

  for (int i = 0; i < 1; i++) {
	  HistoPlot::draw_plot(variables[i], bg_chains, signal_chain, data_chain, false);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  return 0;
}
