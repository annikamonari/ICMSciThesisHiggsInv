#ifndef Histo_Plot_h
#define Histo_Plot_h

#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include "variable.h"
#include <list>
#include <algorithm>

class HistoPlot {
public:
  static const int* colours() { 
    int ret[8] = {40, 41, 42, 30, 38, 28, 15, 49};
    return ret;
  }

  static void draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
                        DataChain* signal_chain, DataChain* data, bool with_cut);

  static void draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains,
		  	  	  	  	  	  	 bool with_cut);

  static TH1F* get_max_histo(TH1F** plot_histos);

  static double get_histo_y_max(TH1F* histo);

  static std::list<TH1F*> get_histos_from_stack(THStack* hs);

  static void build_legend(TLegend* legend, TH1F* max_histo, Variable* var, bool with_cut);

  static double position_legend_x1(TH1F* max_histo, Variable* var, bool with_cut);

  static void style_stacked_histo(THStack* hs, const char* x_label);

  static void style_legend(TLegend* legend);
  
  static double get_x1_from_bin(double max_bin, double nbins);

  static TH1F* build_1d_histo(DataChain* data_chain, Variable* variable, bool with_cut, 
                              bool is_signal, const char* option);

  static TH1F* draw_data(DataChain* data_chain, Variable* variable, bool with_cut);

  static TH1F* draw_signal(DataChain* data_chain, Variable* variable, bool with_cut);

  static TH1F* draw_background(DataChain* data_chain, Variable* variable, 
                                 int fill_colour, bool with_cut);

  static void set_histo_style(bool is_signal, int fill_colour = 0);
  
  static TH1F* set_error_bars(TH1F* histo);

  static float get_data_error(TH1F* histo, int bin);

  static std::string build_file_name(Variable* variable, bool with_cut);

  static std::string build_signal_leg_entry(Variable* var, DataChain* signal_chain);
};

#endif
