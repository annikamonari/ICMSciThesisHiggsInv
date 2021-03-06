#ifndef Histo_Plot_h
#define Histo_Plot_h

#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TLatex.h>
#include "../include/super_chains.h"
#include <list>
#include <algorithm>

class MCWeights;

class HistoPlot 
{
 public:
  static const int* colours() { 
    int ret[8] = {40, 41, 42, 30, 38, 28, 15, 49};
    return ret;
  }

  static std::string lep_sel_default()
  {
    return "(nvetomuons==0)&&(nvetoelectrons==0)";
  }

  static void draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
                        DataChain* signal_chain, DataChain* data, bool with_cut,
                        std::vector<Variable*>* variables = NULL, bool plot_data = true, 
			bool is_control_region= false, std::string file_name = "",
			std::string mc_selection="", std::string mva_cut_str ="");

  static std::string get_mva_name(std::string img_name, std::string var_name, std::string mva_cut_str);

  static void draw_yline_on_plot(Variable* var, bool with_cut, double y);

  static TH1F* data_to_bg_ratio_histo(TH1F* data_histo, TH1F* bg_histo);

  static TH1F* set_ratio_error_bars(TH1F* ratio_histo, TH1F* data_histo, TH1F* bg_histo);

  static void draw_title(const char* title);

  static double get_histo_integral(TH1F* histo, bool with_cut, Variable* var);

  static void draw_subtitle(Variable* variable, std::vector<Variable*>* variables,
                            bool with_cut, DataChain* data, std::string supervar_selection = "",std::string mva_cut_str="");

  static std::string style_selection(std::string selection);

  static std::string replace_all(std::string str, const std::string& from, const std::string& to);

  static double sig_to_bg_ratio(Variable* var, TH1F* last_stacked, TH1F* signal_histo,
                                     bool with_cut);

  static std::string get_selection(Variable* variable, std::vector<Variable*>* variables,
                                   bool with_cut, bool is_signal, DataChain* bg_chain, double mc_weight = 1.0, std::string mva_cut_str="");

  static std::string add_mc_to_selection(DataChain* bg_chain, Variable* variable, std::string mc_selection, double mc_weight);

  static std::string add_mva_cut_to_selection(std::string selection, std::string mva_cut_str);

  static std::vector<double> mc_weights(DataChain* data, std::vector<DataChain*> bg_chains,                                 Variable* var, bool with_cut, std::vector<Variable*>* variables, std::string mva_cut_str ="");

  static double single_bg_error(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables, double weight, std::string mc_selection="", std::string mva_cut_str ="");

  static std::vector<double> get_mc_weight_errors(DataChain* data, std::vector<DataChain*> bg_chains,
																	                                 Variable* var, bool with_cut, std::vector<Variable*>* variables,
																																																		std::vector<double> bg_mc_weights, std::string mva_cut_str ="");

  static std::string get_string_from_double(double num);

  static THStack draw_stacked_histo(TLegend* legend, Variable* var,
                                    std::vector<DataChain*> bg_chains, bool with_cut,std::vector<double> mc_weights_vector, std::vector<Variable*>* variables = NULL, DataChain* data = NULL,
				    std::string mc_selection="", std::string mva_cut_str ="");

  static TH1F* get_max_histo(std::vector<TH1F*> plot_histos);

  static double get_histo_y_max(TH1F* histo);

  static std::list<TH1F*> get_histos_from_stack(THStack* hs);

  static void build_legend(TLegend* legend, TH1F* max_histo, Variable* var, bool with_cut);

  static double position_legend_x1(TH1F* max_histo, Variable* var, bool with_cut);

  static void style_stacked_histo(THStack* hs, const char* x_label);

  static void style_ratio_histo(TH1F* single_histo, const char* x_label, bool plot_data);

  static void style_legend(TLegend* legend);
  
  static double get_x1_from_bin(double max_bin, double nbins);

  static TH1F* build_1d_histo(DataChain* data_chain, Variable* variable, bool with_cut, 
                              bool is_signal, const char* option,
                              std::vector<Variable*>* variables = NULL, std::string mc_selection = "", 
				std::string mva_cut_str ="", double mc_weight = 1);

  static TH1F* draw_data(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
                         std::vector<Variable*>* variables = NULL, std::string mc_selection = "", std::string mva_cut_str ="");

  static TH1F* draw_signal(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
                           std::vector<Variable*>* variables = NULL, std::string mc_selection = "", std::string mva_cut_str ="");

  static TH1F* draw_background(DataChain* data_chain, Variable* variable, int fill_colour, bool with_cut,
                               std::vector<Variable*>* variables = NULL, std::string mc_selection = "", std::string mva_cut_str ="", double mc_weight = 1);

  static void set_histo_style(bool is_signal, int fill_colour = 0);
  
  static TH1F* set_error_bars(TH1F* histo);

  static void set_th1d_error_bars(TH1D* histo);

  static float get_data_error(TH1F* histo, int bin);

  static double get_th1d_data_error(TH1D* histo, int bin);

  static std::string build_file_name(Variable* variable, bool with_cut);

  static std::string build_signal_leg_entry(Variable* var, DataChain* signal_chain);

  static void plot_control_region( DataChain* data, DataChain* signal_chain, DataChain* single_bg_chain, 
std::vector<DataChain*> bg_chains, 
Variable* var, std::vector<Variable*>* variables,std::string mva_cut_str="");
};

#endif

