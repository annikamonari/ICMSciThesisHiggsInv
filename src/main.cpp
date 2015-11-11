
#include "plotting.h"
#include "analysis.h"
#include <initializer_list>

void produce_graphs() {
  DataChain* bg_zll = new DataChain(z_ll, z_ll_label);
  DataChain* bg_wjets_ev = new DataChain(wjets_ev, wjets_ev_label);
  DataChain* bg_wjets_muv = new DataChain(wjets_muv, wjets_muv_label);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label);
  DataChain* bg_top = new DataChain(top, top_label);
  DataChain* bg_vv = new DataChain(vv, vv_label);
  DataChain* bg_zjets_vv = new DataChain(zjets_vv, zjets_vv_label);

  DataChain* mc_signal = new DataChain(mc_signal_data, mc_signal_label);

  DataChain* data_chain = new DataChain(data, data_label);

  const char* weight = "total_weight_lepveto";
  const char* vars[5][3] = { 
                        {"dijet_deta", "0.0", "8.5"},
                        {"ht", "0.0", "400.0"}, 
                        {"met", "-200.0", "200.0"}, 
                        {"alljetsmet_mindphi", "0.0", "3.5"}, 
                        {"dijet_M", "0.0", "3000.0"} 
                      };

  for(int i = 0; i < 5; i++) {

    std::string selection_str(weight);
    selection_str.append("*");
    selection_str.append(vars[i][0]);
    const char* selection = selection_str.c_str();

    //const char* selection = "total_weight_lepveto*ht";build_string({weight,"*", vars[i][0]});
    float x_min = atof(vars[i][1]);
    float x_max = atof(vars[i][2]);

    draw_stacked_histoplots({bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv, bg_top, bg_vv, bg_zjets_vv}, mc_signal, data_chain, vars[i][0], selection, x_min, x_max);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  
  return 0;
};