#ifndef Plotting_h
#define Plotting_h

#include <TROOT.h>
#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TH2.h>
#include "data_chain.h"


void draw_stacked_histoplots(std::vector<DataChain*> bg_chains, char* variable_name, char* selection, float x_min, float x_max) {
  char* plot_title = build_title({variable_name, " Plot"});
  TCanvas* c1      = new TCanvas("c1", plot_title);
  TLegend* legend  = new TLegend(0.6,0.4,0.88,0.88);

  THStack hs(plot_title, plot_title);
  
  legend->SetTextSize(0.04);
  legend->SetBorderSize(0);

  int colours[11] = {41, 43, 30, 40, 38, 11, 16, 32, 22, 24, 13};

  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_histo = data_trees[i]->histo_for_stack(colours[i], variable_name, selection);
    hs.Add(single_histo);
    legend->AddEntry(single_histo, data_trees[i]->label, "f");
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

char* build_title(std::vector<char*> words) {
  char* title = build_string(words);
  title[0] = toupper(title[0]);
  return title;
}

#endif