
#include "plotting.h"
#include "analysis.h"
#include <initializer_list>
#include <cmath>

void produce_graphs() {
  DataChain* bg_zll = new DataChain(z_ll, z_ll_label, z_ll_legend);
  DataChain* bg_wjets_ev = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
  DataChain* bg_wjets_muv = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
  DataChain* bg_top = new DataChain(top, top_label, top_legend);
  DataChain* bg_vv = new DataChain(vv, vv_label, vv_legend);
  DataChain* bg_zjets_vv = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
  DataChain* bg_qcd = new DataChain(qcd, qcd_label, qcd_legend);
  DataChain* mc_signal = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
   
  DataChain* data_chain = new DataChain(data, data_label, data_legend);

  const char* weight = "total_weight_lepveto";
  const char* vars[1][6] = { 
                        {"alljetsmet_mindphi", "0", "3.2", "right", "2.2", "3.2"}
                      };

  for(int i = 0; i < 37; i++) {
    std::string weight_str(weight);
    weight_str.append("*");
    weight_str.append(vars[i][0]);

    //min: x>4.5, max: x<4.5
    std::string cut_max_str(weight_str);
    cut_max_str.append("<");
    cut_max_str.append(vars[i][5]);

    std::string cut_min_str(weight_str);
    cut_min_str.append(">");
    cut_min_str.append(vars[i][4]);

    std::string selection_str(cut_max_str);
    selection_str.append("&&");
    selection_str.append(cut_min_str);

    const char* selection = selection_str.c_str();

    //const char* selection = "total_weight_lepveto*ht";build_string({weight,"*", vars[i][0]});
    const char* x_min = vars[i][1];
    const char* x_max = vars[i][2];
	//create vector of datachain pointers
  DataChain* bg_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv, bg_top, bg_vv, bg_zjets_vv, bg_qcd}; // create array of pointers
  std::vector<DataChain*> bg (bg_arr, bg_arr+ sizeof(bg_arr)/sizeof(DataChain*));
  draw_stacked_histoplots(bg, mc_signal, data_chain, vars[i][0], selection, x_min, x_max, vars[i][3]);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  
  return 0;
}
