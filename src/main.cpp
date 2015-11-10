#include "plotting.h"
#include <initializer_list>

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);

  //DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
  DataTree* tree1 = new DataTree(new TFile("docs/MC_DY1JetsToLL.root"), "DY1Jets->ll");
  DataTree* tree2 = new DataTree(new TFile("docs/MC_DY2JetsToLL.root"), "DY2Jets->ll");
  DataTree* tree3 = new DataTree(new TFile("docs/MC_DY3JetsToLL.root"), "DY3Jets->ll");
  DataTree* tree4 = new DataTree(new TFile("docs/MC_DY4JetsToLL.root"), "DY4Jets->ll");
  DataTree* tree5 = new DataTree(new TFile("docs/MC_EWK-W2jminus_enu.root"), "W2jminus_enu");
  DataTree* tree6 = new DataTree(new TFile("docs/MC_EWK-W2jminus_munu.root"), "W2jminus_munu");
  DataTree* tree7 = new DataTree(new TFile("docs/MC_EWK-W2jminus_taunu.root"), "W2jminus_taunu");
  DataTree* tree8 = new DataTree(new TFile("docs/MC_EWK-W2jplus_enu.root"), "W2jplus_enu");
  DataTree* tree9 = new DataTree(new TFile("docs/MC_EWK-W2jplus_munu.root"), "W2jplus_munu");
  DataTree* tree10 = new DataTree(new TFile("docs/MC_EWK-W2jplus_taunu.root"), "W2jplus_taunu");
  DataTree* tree11 = new DataTree(new TFile("docs/MC_EWK-Z2j.root"), "Z+2jets");


  std::vector<DataTree*> trees = {tree1, tree2, tree3, tree4, tree5, tree6, tree7, tree8, tree9, tree10, tree11};

  char* weights = "sqrt_ht*total_weight_lepveto";

  char* variables[4] = {"dijet_deta", "sqrt_ht", "dijet_dphi", "jetmet_mindphi"};

  draw_stacked_histoplots(trees, "sqrt_ht", weights);

  theApp.Run();
  
  return 0;
};