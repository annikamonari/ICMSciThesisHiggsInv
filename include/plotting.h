#ifndef Plotting_h
#define Plotting_h

#include <TROOT.h>
#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TH2.h>
#include "data_chain.h"


void draw_stacked_histoplots(std::vector<DataChain*> bg_chains, DataChain* signal_chain, char* variable_name, char* selection, float x_min, float x_max) {
  char* plot_title = build_title({variable_name, " Plot"});
  TCanvas* c1      = new TCanvas("c1", plot_title);
  TLegend* legend  = new TLegend(0.6,0.4,0.88,0.88);

  THStack hs(plot_title, plot_title);
  
  legend->SetTextSize(0.04);
  legend->SetBorderSize(0);

  int colours[8] = {40, 41, 42, 30, 38, 28, 15, 49};

  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_bg_histo = bg_chains[i]->histo_for_stack(false, variable_name, selection, x_min, x_max, colours[i]);
    hs.Add(single_bg_histo);
    legend->AddEntry(single_bg_histo, bg_chains[i]->label, "f");
  }

  if(signal_chain != NULL) {
    TH1F* signal_histo = signal_chain->histo_for_stack(false, variable_name, selection, x_min, x_max, 0);
    hs.Add(signal_histo);
    legend->AddEntry(signal_histo, signal_chain->label, "l");
  }

  char* file_name = build_string({variable_name, "_", selection, ".png"});

  hs.Draw();
  hs.GetYaxis()->SetTitle("Events");
  hs.GetYaxis()->SetLabelSize(0.05);

  hs.GetXaxis()->SetTitle(build_title({variable_name}));
  hs.GetXaxis()->SetLabelSize(0.05);
  hs.GetXaxis()->SetRangeUser(x_min, x_max);

  legend->Draw();

  c1->Update();
  c1->SaveAs(file_name);
  c1->Close();
}

#endif