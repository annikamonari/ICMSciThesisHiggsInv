#ifndef Plotting_h
#define Plotting_h

#include <TROOT.h>
#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TH2.h>
#include <vector>
#include "data_tree.h"


void draw_stacked_histoplots(std::vector<DataTree*> data_trees, char* variable_name, char* selection) {
  TCanvas* c1 = new TCanvas("c1", "stacked hists");
  THStack hs("Stacked Histogram", variable_name);
  TLegend* legend = new TLegend(0.6,0.7,0.9,0.9);
  legend->SetTextSize(0.04);
  legend->SetBorderSize(0);

  int colours[7] = {41, 43, 30, 40, 38, 11, 16};

  for(int i = 0; i < data_trees.size(); i++) {
    TH1F* single_histo = data_trees[i]->create_histo_for_stack(colours[i], variable_name, selection);

    hs.Add(single_histo);
    legend->AddEntry(single_histo, data_trees[i]->label, "f");
  }

  hs.Draw();
  //hs.GetYaxis()->SetTitle("Frequency");
  hs.GetXaxis()->SetTitle(variable_name);
  c1->Update();
  legend->Draw();
  c1->Update();
}

#endif