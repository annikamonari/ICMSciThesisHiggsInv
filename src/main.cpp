#include "plotting.h"

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);

  DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
  DataTree* tree2 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-2.root"), "Data Run 2");
  TCut cut = NULL;

  draw_stacked_histoplots({tree1, tree2}, "jet1_eta", &cut);

  theApp.Run();
  
  return 0;
};