#include <initializer_list>
#include <cmath>
#include "../include/mva_analysis.h"

//#include "../include/mlp_analysis.h"

void produce_graphs(bool with_cut) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();
  SuperChains* super_chains         = new SuperChains();
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;
  const char* mva_type = "MLP";  //go into train_and_run_BDT function to change input parameters

  MVAAnalysis::get_plots_varying_params(bg_chains, 0, signal_chain, data_chain, super_vars, "MLP", "NeuronType", NTrees, BoostType,
  																			                   AdaBoostBeta, SeparationType, nCuts, NeuronType, NCycles, HiddenLayers);

  /*TFile* file1 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=10-HiddenLayers=5,5,5.root");
  TFile* file2 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=100-HiddenLayers=5,5,5.root");
  TFile* file3 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=1000-HiddenLayers=5,5,5.root");
  TFile* file5 = TFile::Open("bg_zll/MLP-NeuronType=sigmoid-NCycles=500-HiddenLayers=2.root");

  TFile* files_arr[] = {file1, file2, file3, file5};
  std::vector<TFile*> files (files_arr, files_arr + sizeof(files_arr) / sizeof(files_arr[0]));
  //ClassifierOutputs::plot_classifiers_for_all_files(files, "MLP");

  //DataCard::create_datacard(data_chain, signal_chain, bg_chains, cut_vars[0], true, &cut_vars,mva_type);
    /*MVAAnalysis::train_and_run_BDT(bg_chains, signal_chain, cut_vars, super_vars->get_cuts_str_for_tmva(),mva_type);

  std::vector<TFile*> tfiles (files, files+ sizeof(files)/sizeof(TFile*));
  RocCurves::get_rocs(tfiles, signal_chain, bg_chains[0], super_vars, "MLP");
  */

  for (int i = 0; i < 1; i++)
  {
     //HistoPlot::draw_plot(vars[i], bg_chains, signal_chain, data_chain, true, &cut_vars, false);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true);
  theApp.Run();
  return 0;
}
