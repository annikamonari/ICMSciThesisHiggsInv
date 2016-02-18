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
  std::string mva_type = "BDT";  //go into train_and_run_BDT function to change input parameters
  std::string varying_param = "SeparationType";
  int relevant_bgs[] = {0, 1, 2, 3};//, 6};
std::string mva_cut_str = "output>0.1";//must be in format "output>0" 
std::string ajmd_name_mva_cut="BDT_varying_SeparationType/output_BDT-bg_zll-NTrees=10-BoostType=AdaBoost-AdaBoostBeta=0.1-SeparationType=GiniIndex-nCuts=5alljetsmetnomu_mindphioutput>0.0.png";
  for (int i = 0; i < 1; i++)
  {
  		std::cout << "============== FOR BG  " << i << "  ==============" << std::endl;
  		std::cout << "=================================================" << std::endl;
   		

  MVAAnalysis::get_plots_varying_params(bg_chains, relevant_bgs[i], signal_chain, data_chain, super_vars,
                                     mva_type, varying_param, NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str);
  }
/*std::string datac;
datac = DataCard::create_datacard(data_chain, signal_chain, bg_chains, vars[0], true, &vars,mva_cut_str, ajmd_name_mva_cut);*/

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
