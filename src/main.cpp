
#include "plotting.h"
#include "analysis.h"
#include <initializer_list>
#include <cmath>


  char* int_to_char(int int_to_convert){
	char char_of_int[5];
	sprintf(char_of_int, "%d", int_to_convert);
	return char_of_int;
}


void produce_graphs(int bin_number) {
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
  
  char* bin_num_str=int_to_char(bin_number);
  const char* weight = "total_weight_lepveto";
  const char* vars[][6] = { 
                        // {varaible to plot, bins, xmin, xmax, legend position, signal_multiplier}
                        {"met", bin_num_str, "0.0", "400.0", "right", "100"}
                      };
 std::cout << vars[0][1] <<"\n";

  for(int i = 0; i < 1; i++) {

    //min: x>4.5, max: x<4.5
    /*
    std::string cut_max_str(weight_str);
    cut_max_str.append("<");
    cut_max_str.append(vars[i][5]);

    std::string cut_min_str(weight_str);
    cut_min_str.append(">");
    cut_min_str.append(vars[i][4]);
    */

    std::string selection_str(weight);
    const char* selection = selection_str.c_str();

    const char* signal_multiplier = vars[i][5];
    const char* bins = int_to_char(bin_number);
    std::cout << bins <<"\n";
    const char* x_min = vars[i][2];
    const char* x_max = vars[i][3];
	//create vector of datachain pointers
    DataChain* bg_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv, bg_top, bg_vv, bg_zjets_vv, bg_qcd}; // create array of pointers
    std::vector<DataChain*> bg (bg_arr, bg_arr+ sizeof(bg_arr)/sizeof(DataChain*));
    draw_stacked_histoplots(bg, mc_signal, data_chain, vars[i][0], selection, signal_multiplier, bins, x_min, x_max, vars[i][3], true);
    //bg_zll->scale_bins_for_cut("100", "0", "100", "50", "100");
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
    int in;
    std::cout << "Please enter a bin number:";
    std::cin >> in;

produce_graphs(in);

  theApp.Run();
  
  return 0;
}
