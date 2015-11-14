
#include "plotting.h"
//<<<<<<< HEAD
//=======
#include "analysis.h"
//>>>>>>> 74c1885ba329c353c0be89d3c150bfb95706afaa
#include <initializer_list>

void produce_graphs() {
  DataChain* bg_zll = new DataChain(z_ll, z_ll_label, z_ll_legend);
  DataChain* bg_wjets_ev = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
  DataChain* bg_wjets_muv = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
  DataChain* bg_top = new DataChain(top, top_label, top_legend);
  DataChain* bg_vv = new DataChain(vv, vv_label, vv_legend);
  DataChain* bg_zjets_vv = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);

  DataChain* mc_signal = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);

  DataChain* data_chain = new DataChain(data, data_label, data_legend);

//<<<<<<< HEAD
  //DataTree* tree1 = new DataTree(new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root"), "Data Run 0");
//<<<<<<< HEAD
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
//=======
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
//>>>>>>> 02ba25d491f619608a6de7cddce01a4a9012a01b
//=======
  const char* weight = "total_weight_lepveto";
  const char* vars[5][4] = { 
                        {"dijet_deta", "3.0", "8.5", "right"},
                        {"ht", "0.0", "400.0", "left"}, 
                        {"met", "0.0", "500.0", "right"}, 
                        {"alljetsmet_mindphi", "0.0", "3.5", "left"}, 
                        {"dijet_M", "0.0", "3000.0", "right"} 
                      };

  for(int i = 0; i < 5; i++) {
    std::string selection_str(weight);
    selection_str.append("*");
    selection_str.append(vars[i][0]);
    const char* selection = selection_str.c_str();

    //const char* selection = "total_weight_lepveto*ht";build_string({weight,"*", vars[i][0]});
    const char* x_min = vars[i][1];
    const char* x_max = vars[i][2];

     
draw_stacked_histoplots({bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv, bg_top, bg_vv, bg_zjets_vv}, mc_signal, data_chain, vars[i][0], selection, x_min, x_max, vars[i][3]);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();
//>>>>>>> 74c1885ba329c353c0be89d3c150bfb95706afaa

  theApp.Run();
  
  return 0;
}
