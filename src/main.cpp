#include "plotting.h"

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);

  //DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
  DataTree* tree1 = new DataTree(new TFile("docs/MC_DY1JetsToLL_iglep.root"), "MC_DY1JetsToLL_iglep.root");
DataTree* tree2 = new DataTree(new TFile("docs/MC_DY1JetsToLL.root"), "MC_DY1JetsToLL.root");
DataTree* tree3 = new DataTree(new TFile("docs/MC_DY2JetsToLL_iglep.root"), "MC_DY2JetsToLL_iglep.root");
DataTree* tree4 = new DataTree(new TFile("docs/MC_DY2JetsToLL.root"), "MC_DY2JetsToLL.root");
DataTree* tree5 = new DataTree(new TFile("docs/MC_DY3JetsToLL_iglep.root"), "MC_DY3JetsToLL_iglep.root");
DataTree* tree6 = new DataTree(new TFile("docs/MC_DY3JetsToLL.root"), "MC_DY3JetsToLL.root");
DataTree* tree7 = new DataTree(new TFile("docs/MC_DY4JetsToLL_iglep.root"), "MC_DY4JetsToLL_iglep.root");
DataTree* tree8 = new DataTree(new TFile("docs/MC_DY4JetsToLL.root"), "MC_DY4JetsToLL.root");
DataTree* tree9 = new DataTree(new TFile("docs/MC_DYJetsToLL_iglep.root"), "MC_DYJetsToLL_iglep.root");
DataTree* tree10 = new DataTree(new TFile("docs/MC_DYJetsToLL_PtZ-100-madgraph_iglep.root"), "MC_DYJetsToLL_PtZ-100-madgraph_iglep.root");
DataTree* tree11 = new DataTree(new TFile("docs/MC_DYJetsToLL_PtZ-100-madgraph.root"), "MC_DYJetsToLL_PtZ-100-madgraph.root");
DataTree* tree12 = new DataTree(new TFile("docs/MC_DYJetsToLL.root"), "MC_DYJetsToLL.root");
DataTree* tree13 = new DataTree(new TFile("docs/MC_EWK-W2jminus_enu.root"), "MC_EWK-W2jminus_enu.root");
DataTree* tree14 = new DataTree(new TFile("docs/MC_EWK-W2jminus_munu.root"), "MC_EWK-W2jminus_munu.root");
DataTree* tree15 = new DataTree(new TFile("docs/MC_EWK-W2jminus_taunu.root"), "MC_EWK-W2jminus_taunu.root");
DataTree* tree16 = new DataTree(new TFile("docs/MC_EWK-W2jplus_enu.root"), "MC_EWK-W2jplus_enu.root");
DataTree* tree17 = new DataTree(new TFile("docs/MC_EWK-W2jplus_munu.root"), "MC_EWK-W2jplus_munu.root");
DataTree* tree18 = new DataTree(new TFile("docs/MC_EWK-W2jplus_taunu.root"), "MC_EWK-W2jplus_taunu.root");
DataTree* tree19 = new DataTree(new TFile("docs/MC_EWK-Z2j_iglep.root"), "MC_EWK-Z2j_iglep.root");
DataTree* tree20 = new DataTree(new TFile("docs/MC_EWK-Z2j.root"), "MC_EWK-Z2j.root");
DataTree* tree56 = new DataTree(new TFile("docs/MC_Tbar-tW.root"), "MC_Tbar-tW.root");
DataTree* tree60 = new DataTree(new TFile("docs/MC_T-tW.root"), "MC_T-tW.root");
DataTree* tree66 = new DataTree(new TFile("docs/MC_W1JetsToLNu_enu.root"), "MC_W1JetsToLNu_enu.root");
DataTree* tree67 = new DataTree(new TFile("docs/MC_W1JetsToLNu_munu.root"), "MC_W1JetsToLNu_munu.root");
DataTree* tree68 = new DataTree(new TFile("docs/MC_W1JetsToLNu_taunu.root"), "MC_W1JetsToLNu_taunu.root");
DataTree* tree69 = new DataTree(new TFile("docs/MC_W2JetsToLNu_enu.root"), "MC_W2JetsToLNu_enu.root");
DataTree* tree70 = new DataTree(new TFile("docs/MC_W2JetsToLNu_munu.root"), "MC_W2JetsToLNu_munu.root");
DataTree* tree71 = new DataTree(new TFile("docs/MC_W2JetsToLNu_taunu.root"), "MC_W2JetsToLNu_taunu.root");
DataTree* tree72 = new DataTree(new TFile("docs/MC_W3JetsToLNu_enu.root"), "MC_W3JetsToLNu_enu.root");
DataTree* tree73 = new DataTree(new TFile("docs/MC_W3JetsToLNu_munu.root"), "MC_W3JetsToLNu_munu.root");
DataTree* tree74 = new DataTree(new TFile("docs/MC_W3JetsToLNu_taunu.root"), "MC_W3JetsToLNu_taunu.root");
DataTree* tree75 = new DataTree(new TFile("docs/MC_W4JetsToLNu_enu.root"), "MC_W4JetsToLNu_enu.root");
DataTree* tree76 = new DataTree(new TFile("docs/MC_W4JetsToLNu_munu.root"), "MC_W4JetsToLNu_munu.root");
DataTree* tree77 = new DataTree(new TFile("docs/MC_W4JetsToLNu_taunu.root"), "MC_W4JetsToLNu_taunu.root");
DataTree* tree78 = new DataTree(new TFile("docs/MC_WGamma.root"), "MC_WGamma.root");
DataTree* tree79 = new DataTree(new TFile("docs/MC_WJetsToLNu-v1_enu.root"), "MC_WJetsToLNu-v1_enu.root");
DataTree* tree80 = new DataTree(new TFile("docs/MC_WJetsToLNu-v1_munu.root"), "MC_WJetsToLNu-v1_munu.root");
DataTree* tree81 = new DataTree(new TFile("docs/MC_WJetsToLNu-v1_taunu.root"), "MC_WJetsToLNu-v1_taunu.root");
DataTree* tree82 = new DataTree(new TFile("docs/MC_WJetsToLNu-v2_enu.root"), "MC_WJetsToLNu-v2_enu.root");
DataTree* tree83 = new DataTree(new TFile("docs/MC_WJetsToLNu-v2_munu.root"), "MC_WJetsToLNu-v2_munu.root");
DataTree* tree84 = new DataTree(new TFile("docs/MC_WJetsToLNu-v2_taunu.root"), "MC_WJetsToLNu-v2_taunu.root");
DataTree* tree85 = new DataTree(new TFile("docs/MC_WW-pythia6-tauola.root"), "MC_WW-pythia6-tauola.root");
DataTree* tree86 = new DataTree(new TFile("docs/MC_WZ-pythia6-tauola.root"), "MC_WZ-pythia6-tauola.root");
DataTree* tree87 = new DataTree(new TFile("docs/MC_ZJetsToNuNu_100_HT_200.root"), "MC_ZJetsToNuNu_100_HT_200.root");
DataTree* tree88 = new DataTree(new TFile("docs/MC_ZJetsToNuNu_200_HT_400.root"), "MC_ZJetsToNuNu_200_HT_400.root");
DataTree* tree89 = new DataTree(new TFile("docs/MC_ZJetsToNuNu_400_HT_inf.root"), "MC_ZJetsToNuNu_400_HT_inf.root");
DataTree* tree90 = new DataTree(new TFile("docs/MC_ZJetsToNuNu_50_HT_100.root"), "MC_ZJetsToNuNu_50_HT_100.root");
DataTree* tree91 = new DataTree(new TFile("docs/MC_ZZ-pythia6-tauola.root"), "MC_ZZ-pythia6-tauola.root");


 
  
  TCut cut = NULL;

  draw_stacked_histoplots({tree1}, "jet1_eta", &cut);

  theApp.Run();
  
  return 0;
};
