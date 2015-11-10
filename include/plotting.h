#ifndef Plotting_h
#define Plotting_h

#include <TROOT.h>
#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TH2.h>
#include <vector>
#include "data_tree.h"


void draw_stacked_histoplots(std::vector<DataTree*> data_trees, char* variable_name, TCut* cut = NULL) {
  TCanvas* c1 = new TCanvas("c1", "stacked hists");
  THStack hs("Stacked Histogram", variable_name);
  TLegend* legend = new TLegend(0.2,0.2,0.5,0.4);
  legend->SetTextSize(0.04);

  for(int i = 0; i < data_trees.size(); i++) {
    TH1F* single_histo = data_trees[i]->create_histo_for_stack(i + 2, variable_name, cut);

    hs.Add(single_histo);
    legend->AddEntry(single_histo, data_trees[i]->label, "f");
  }

  hs.Draw();
  c1->Update();
  legend->Draw();
  c1->Update();
}

#endif