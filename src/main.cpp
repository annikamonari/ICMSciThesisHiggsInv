#include "plotting.h"

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);

  //DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
DataTree* tree1 = new DataTree(new TFile("docs/MC_DY1JetsToLL_iglep.root"), "MC_DY1JetsToLL_iglep.root");
DataTree* tree2 = new DataTree(new TFile("docs/MC_DY1JetsToLL.root"), "MC_DY1JetsToLL.root");

  TCut cut = NULL;

  draw_stacked_histoplots({tree1, tree2}, "jet1_eta", &cut);

  theApp.Run();
  
  return 0;
}
