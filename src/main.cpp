#include "../include/histo_plot.h"
#include "../include/analysis.h"
#include <initializer_list>
#include <cmath>

void produce_graphs() {
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

  Variable* variable = new Variable("jet1_pt", "Jet 1 pT", "20", "0.0", "600.0", 
                                    "420.0", "440.0", "100");
  DataChain* myDataChain[8] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv,
          bg_top, bg_vv, bg_zjets_vv, bg_qcd};

  std::vector<DataChain*> bg_chains (myDataChain, myDataChain + sizeof(myDataChain) / sizeof(myDataChain[0]));

  HistoPlot::draw_stacked_histo(variable, bg, signal_chain, data_chain, false);
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  
  return 0;
}
