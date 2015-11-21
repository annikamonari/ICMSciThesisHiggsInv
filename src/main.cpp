
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
  const char* vars[][8] = { 
                        // {varaible to plot, xmin, xmax, legend position,min_x_cut,max_x_cut,bins}
			{"jet1_pt", "0.0", "600.0", "right","420.0", "440.0","10","100"}
                      };
 // const char* bin_arr[]= {"10","25","50","75","100"};

  for(int i = 1; i < 5; i++) {
       
    std::string cut_max_str(vars_w_cuts[i][0]);
    cut_max_str=cut_max_str+"<"+ vars_w_cuts[i][5] +")";

    std::string cut_min_str(vars_w_cuts[i][0]);
    cut_min_str = "(" + cut_min_str + ">" +vars_w_cuts[i][4];

    cut_max_str = cut_min_str + "&&" + cut_max_str;
    cut_max_str +="*";
    cut_max_str.append(weight);
    

    std::string selection_str(cut_max_str);
    const char* selection = selection_str.c_str();
    const char* x_min = vars_w_cuts[i][1];
    const char* x_max = vars_w_cuts[i][2];
    const char* min_x_cut=vars_w_cuts[i][4];
    const char* max_x_cut=vars_w_cuts[i][5];
    std::cout << "variable = " << vars_w_cuts[i][0] << "\n";
    	//create vector of datachain pointers
    DataChain* bg_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv, bg_top, bg_vv, bg_zjets_vv, bg_qcd}; // create array of pointers
    std::vector<DataChain*> bg (bg_arr, bg_arr+ sizeof(bg_arr)/sizeof(DataChain*));

    const char* signal_multiplier = vars_w_cuts[i][7];
    //const int bin_int = atoi();
    const char* bins =vars_w_cuts[i][6];// &bin_int;
   // const int* scaled_bins = scale_bins_for_cut(bins, x_min,x_max, min_x_cut, max_x_cut);
    //std::cout << "bins:" << *bins <<"+"<<bins<< "\n";
    //std::cout << "scaled bins out put in  main.cpp:" << scaled_bins << "+" <<  *scaled_bins << "\n";
   draw_stacked_histoplots(bg, mc_signal, data_chain, vars_w_cuts[i][0], selection, signal_multiplier, bins, min_x_cut, max_x_cut, vars_w_cuts[i][3], true, x_min, x_max);
   std::cout << "var with cuts number = " << i << "\n";
  //scaled_binsbg_zll->scale_bins_for_cut("100", "0", "100", "50", "100");
  //std::cout<< scaled_bins<<"\n";
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  
  return 0;
}

