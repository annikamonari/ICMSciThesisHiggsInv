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
  TLegend* legend = new TLegend(0.6,0.4,0.9,0.9);
  legend->SetTextSize(0.04);
  legend->SetBorderSize(0);

  int colours[11] = {41, 43, 30, 40, 38, 11, 16, 32, 22, 24, 13};

  for(int i = 0; i < data_trees.size(); i++) {
    TH1F* single_histo = data_trees[i]->create_histo_for_stack(colours[i], variable_name, selection);

    hs.Add(single_histo);
    legend->AddEntry(single_histo, data_trees[i]->label, "f");
  }

<<<<<<< HEAD
  //std::string s1;
  //s1=variable_name*;
  //s1.append(".png");
  
=======
  std::string file_name(variable_name);
  file_name.append("_");
  file_name.append(selection);
  file_name.append(".png");

>>>>>>> 02ba25d491f619608a6de7cddce01a4a9012a01b
  hs.Draw();
  //hs.GetYaxis()->SetTitle("Frequency");
  hs.GetXaxis()->SetTitle(variable_name);
  hs.GetXaxis()->SetRangeUser(6, 12);
  c1->Update();
  legend->Draw();
  c1->Update();
<<<<<<< HEAD
  //c1->SavesAs(s1);}
=======

  c1->SaveAs(file_name.c_str());
  c1->Close();
}
>>>>>>> 02ba25d491f619608a6de7cddce01a4a9012a01b

#endif
