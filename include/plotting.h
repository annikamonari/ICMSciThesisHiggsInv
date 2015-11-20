#ifndef Plotting_h
#define Plotting_h

#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include "data_chain.h"
#include <typeinfo>
#include <sstream>

const char* scale_bins_for_cut(const char* binsc, const char* x_minc_nocut, const char* x_maxc_nocut, const char* x_minc_cut, const char* x_maxc_cut) {
  double x_min_nocut = atof(x_minc_nocut);
  double x_max_nocut = atof(x_maxc_nocut);
  double x_min_cut = atof(x_minc_cut);
  double x_max_cut = atof(x_maxc_cut);
  double fraction = (x_max_cut - x_min_cut)/(x_max_nocut - x_min_nocut);
  double bins = atof(binsc);
  double nbins = bins * fraction;
  nbins = nbins + 0.5;
  int nbins_int = (int) nbins;
  if (nbins_int==0){
	nbins_int=1;
  }
  //char scaled_bins[10];
  //sprintf(scaled_bins, "%d", nbins_int);
std::string scaled_bins_str;
std::ostringstream convert;
convert << nbins_int;
scaled_bins_str = convert.str();
const char* scaled_bins = scaled_bins_str.c_str();
std::cout << "*scaled_bins=" << *scaled_bins << "\n";

  //std::cout << *scaled_bins << "\n";
  return scaled_bins;
}

void draw_stacked_histoplots(std::vector<DataChain*> bg_chains, DataChain* signal_chain, DataChain* data, const char* variable_name, const char* selection, const char* signal_multiplier, const char* bins, const char* x_min, const char* x_max, const char* leg_pos, bool is_cut) {
  //const char* plot_title = build_string({variable_name, " Plot"});
  std::string title_parts(variable_name);
  title_parts.append(" Plot");
  const char* plot_title = title_parts.c_str();

  TCanvas* c1 = new TCanvas("c1", plot_title);

  TLegend* legend_bg;
  if(strcmp(leg_pos, "right") == 0) {
    legend_bg = new TLegend(0.7,0.5,0.88,0.88);
  }
  else {
    legend_bg = new TLegend(0.12,0.5,0.3,0.88);
  }

  THStack hs(plot_title, plot_title);
  
  legend_bg->SetTextSize(0.035);
  legend_bg->SetBorderSize(0);

  int colours[8] = {40, 41, 42, 30, 38, 28, 15, 49};

  //std::cout << "setup canvas, legend and plot" << std::endl;
  for(int i = 0; i < bg_chains.size(); i++) {
  	TH1F* single_bg_histo = bg_chains[i]->histo_for_stack(false, variable_name, selection, bins, x_min, x_max, colours[i], is_cut);
  	hs.Add(single_bg_histo);
  	legend_bg->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  	//std::cout << "histograms added to stack fine" << std::endl;
 	}

  std::string signal_sel(selection);
  signal_sel += "*";
  signal_sel.append(signal_multiplier);

  TH1F* signal_histo = signal_chain->histo_for_stack(true, variable_name, signal_sel.c_str(), bins, x_min, x_max, 0, is_cut);
  legend_bg->AddEntry(signal_histo, signal_chain->legend, "l");

  TH1F* data_histo = data->draw_data(variable_name, selection, bins, x_min, x_max);
  legend_bg->AddEntry(data_histo, data->legend, "lep");
    
  std::string file_parts("graph_bin_cut_adjust/");
   file_parts.append(variable_name);
  file_parts.append("_");
  std::string str = bins;
  std::cout << "*bins: ";
  std::cout << bins[0] << "\n";
  file_parts.append(str);
  file_parts.append(".png");
  const char* file_name = file_parts.c_str();
  //const char* file_name = build_string({variable_name, "_", selection, ".png"});

  hs.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  //std::cout << "data added to plot fine" << std::endl;
  hs.GetYaxis()->SetTitle("Events");
  hs.GetYaxis()->SetLabelSize(0.035);
  hs.GetYaxis()->SetTitleOffset(1.35);
  hs.GetXaxis()->SetTitle(variable_name);
  hs.GetXaxis()->SetLabelSize(0.035);
  hs.GetXaxis()->SetTitleOffset(1.35);
  
  legend_bg->Draw();

  c1->SaveAs(file_name);
  c1->Close();
}

#endif
