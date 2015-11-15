
#include "plotting.h"
#include "analysis.h"
#include <initializer_list>

void produce_graphs(bool plot_signal, bool plot_background, bool plot_data) {
  /* if(plot_signal == false){
  std::vector<const char*> mc_signal_data();
  }*/
  DataChain* bg_zll = new DataChain(z_ll, z_ll_label, z_ll_legend);
  DataChain* bg_wjets_ev = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
  DataChain* bg_wjets_muv = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
  DataChain* bg_top = new DataChain(top, top_label, top_legend);
  DataChain* bg_vv = new DataChain(vv, vv_label, vv_legend);
  DataChain* bg_zjets_vv = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
  DataChain* bg_qcd = new DataChain(qcd, qcd_label, qcd_legend);
  DataChain* mc_signal = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
  /*if(plot_data == false){
  const char* data_arr={};
  //std::vector<const char*> data (data_arr, data_arr+ sizeof(data_arr)/sizeof(const char*));
  DataChain* data_chain = new DataChain(data, data_label, data_legend);
  }*/
  
  DataChain* data_chain = new DataChain(data, data_label, data_legend);

  const char* weight = "total_weight_lepveto";
  const char* vars[5][4] = { 
                        {"dijet_deta", "3.0", "8.5", "right"},
                        {"ht", "0.0", "400.0", "left"}, 
                        {"met", "0.0", "500.0", "right"}, 
                        {"alljetsmet_mindphi", "0.0", "3.5", "left"}, 
                        {"dijet_M", "0.0", "3000.0", "right"} 
                      };

  for(int i = 0; i < 5; i++) {
    std::string selection_str(weight);
    selection_str.append("*");
    selection_str.append(vars[i][0]);
    const char* selection = selection_str.c_str();

    //const char* selection = "total_weight_lepveto*ht";build_string({weight,"*", vars[i][0]});
    const char* x_min = vars[i][1];
    const char* x_max = vars[i][2];
	//create vector of datachain pointers
  DataChain* bg_arr[] ={bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv,bg_qcd, bg_top, bg_vv, bg_zjets_vv}; // create array of pointers
  /*if(plot_background == false){
  bg_arr={};
  }*/
  std::vector<DataChain*> bg (bg_arr, bg_arr+ sizeof(bg_arr)/sizeof(DataChain*));

draw_stacked_histoplots(bg, mc_signal, data_chain, vars[i][0], selection, x_min, x_max, vars[i][3],plot_signal,plot_background,plot_data);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true,true,true);

  theApp.Run();
  
  return 0;
}
