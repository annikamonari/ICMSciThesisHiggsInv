#include "plotting.h"

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);

  //DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
  DataTree* tree1 = new DataTree(new TFile("docs/MC_DY1JetsToLL_iglep.root"), "MC_DY1JetsToLL_iglep.root");
  DataTree* tree2 = new DataTree(new TFile("docs/MC_EWK-W2jminus_enu.root"), "MC_EWK-W2jminus-enu");
  DataTree* tree3 = new DataTree(new TFile("docs/MC_QCD-Pt-1000to1400-pythia6.root"), "MC_QCD-Pt-1000to1400-pythia6");
  TCut cut = NULL;

  draw_stacked_histoplots({tree1, tree2, tree3}, "jet1_eta", &cut);

  theApp.Run();
  
  return 0;
};