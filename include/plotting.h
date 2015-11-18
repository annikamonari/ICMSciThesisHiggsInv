#ifndef Plotting_h
#define Plotting_h

#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include "data_chain.h"

void draw_stacked_histoplots(std::vector<DataChain*> bg_chains, DataChain* signal_chain, DataChain* data, const char* variable_name, const char* selection, const char* bins, const char* x_min, const char* x_max, const char* leg_pos, bool is_cut) {
  //const char* plot_title = build_string({variable_name, " Plot"});
  std::string title_parts(variable_name);
  title_parts.append(" Plot");
  const char* plot_title = title_parts.c_str();

  TCanvas* c1 = new TCanvas("c1", plot_title, 800, 1000);
  TPad* bg = new TPad("bg", "", 0.0, 0.3, 1.0, 1.0);
  TPad* sig = new TPad("sig", "", 0.0, 0.0, 1.0, 0.3);
  bg->Draw();
  sig->Draw();

  bg->cd();
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

  std::cout << "setup canvas, legend and plot" << std::endl;
  for(int i = 0; i < bg_chains.size(); i++) {
  	TH1F* single_bg_histo = bg_chains[i]->histo_for_stack(false, variable_name, selection, bins, x_min, x_max, colours[i], is_cut);
  	hs.Add(single_bg_histo);
  	legend_bg->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  	std::cout << "histograms added to stack fine" << std::endl;
 	}

  TH1F* signal_histo = signal_chain->histo_for_stack(true, variable_name, selection, bins, x_min, x_max, 0, is_cut);
  legend_bg->AddEntry(signal_histo, signal_chain->legend, "l");

  TH1F* data_histo = data->draw_data(variable_name, selection, bins, x_min, x_max);
  legend_bg->AddEntry(data_histo, data->legend, "lep");
    
  std::string file_parts(variable_name);
  file_parts.append("_");
  file_parts.append(bins);
  file_parts.append(".png");
  const char* file_name = file_parts.c_str();
  //const char* file_name = build_string({variable_name, "_", selection, ".png"});

  hs.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  std::cout << "data added to plot fine" << std::endl;
  hs.GetYaxis()->SetTitle("Events");
  hs.GetYaxis()->SetLabelSize(0.035);
  hs.GetYaxis()->SetTitleOffset(1.35);
  hs.GetXaxis()->SetTitle(variable_name);
  hs.GetXaxis()->SetLabelSize(0.035);
  hs.GetXaxis()->SetTitleOffset(1.35);
  
  legend_bg->Draw();

  sig->cd();
  signal_histo->Draw();
  signal_histo->SetTitle("");
  signal_histo->GetYaxis()->SetTitle("Events");
  signal_histo->GetYaxis()->SetLabelSize(0.035);
  signal_histo->GetYaxis()->SetTitleOffset(1.35);
  signal_histo->GetXaxis()->SetTitle(variable_name);
  signal_histo->GetXaxis()->SetLabelSize(0.035);
  signal_histo->GetXaxis()->SetTitleOffset(1.35);

  c1->SaveAs(file_name);
  c1->Close();
}

#endif
