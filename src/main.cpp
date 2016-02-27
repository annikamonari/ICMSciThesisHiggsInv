#include <initializer_list>
#include <cmath>
#include "../include/mva_analysis.h"
#include <iostream> 
//#include "../include/mlp_analysis.h"

void produce_graphs(bool with_cut, char** command_line_integers) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();
  SuperChains* super_chains         = new SuperChains();
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;
  std::string mva_type = "MLP";  //go into train_and_run_BDT function to change input parameters
  int bg_id=0;
  int param_id=0;

  std::string varying_param1 = "SeparationType";
  std::string varying_param2 = "NeuronType";
  std::string varying_param3 = "NCycles";
  std::string varying_param4 = "HiddenLayers";
  bg_id = atoi(command_line_integers[0]);
  param_id = atoi(command_line_integers[1]);
  std::string varying_param = "NeuronType";
  

  const std::string bg[8] = {"bg_zll", "bg_wjets_ev", "bg_wjets_muv", "bg_wjets_tauv", "bg_top", "bg_vv", "bg_zjets_vv", "bg_qcd"};

  std::string folder_name = mva_type+ "_varying_" + varying_param;

  int relevant_bgs[] = {0, 1, 2, 3};//, 6};
  std::string mva_cut_str = "output>0.0";//"output>0.1";//must be in format "output>0"  

//                  0         1             2            3            4         5      6            7
//int array of bgs {bg_zll, bg_wjets_ev, bg_wjets_muv,bg_wjets_tauv, bg_top, bg_vv,bg_zjets_vv, bg_qcd};
std::cout<<NeuronType[1]<<"\n";
/*
for(int i =0;i<bg_chains.size(); i++){
  for(int j =0;j<2; j++){
    if(std::ifstream("~/mproject/ICMSciThesisHiggsInv/TMVApp1.root")){remove("~/mproject/ICMSciThesisHiggsInv/TM    VApp1.root");} // very important otherwise doesnt get deleted
*//* bg_id*//*
    MVAAnalysis::get_mva_results(bg_chains,i, signal_chain, data_chain, super_vars, "MLP_varying_Neuro    nType", mva_type, NTrees[0], BoostType[0],AdaBoostBeta[1], SeparationType[0], nCuts[2], NeuronType[j],     NCycles[0], HiddenLayers[0],mva_cut_str);
    //std::cout<<NeuronType[1]<<"\n";
}
}*/
/*int bg_int=bg_id;
int command_line_input_integer=param_id;
varying_param = "SeparationType";
mva_type = "BDT"; 
folder_name = mva_type+ "_varying_" + varying_param;

MVAAnalysis::get_mva_results(bg_chains,bg_int, signal_chain, data_chain, super_vars, "bg_zll", 
mva_type, NTrees[command_line_input_integer], BoostType[0],AdaBoostBeta[1], SeparationType[0], nCuts[2], NeuronType[command_line_input_integer], NCycles[0], HiddenLayers[0],mva_cut_str);*/

for (int i = 0; i < 1/*bg_chains.size()*/; i++)
  {
  		std::cout << "============== FOR BG  " << i << "  ==============" << std::endl;
  		std::cout << "=================================================" << std::endl;
   	
 if(std::ifstream("~/mproject/ICMSciThesisHiggsInv/TMVApp1.root")){remove("~/mproject/ICMSciThesisHiggsInv/TMVApp1.root");} // very important otherwise doesnt get deleted
	
  MVAAnalysis::get_plots_varying_params(bg_chains, relevant_bgs[i], signal_chain, data_chain, super_vars,
                                     "MLP", "NeuronType", NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str);
  /*MVAAnalysis::get_plots_varying_params(bg_chains, relevant_bgs[i], signal_chain, data_chain, super_vars,
                                     mva_type2, varying_param2, NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str);
  MVAAnalysis::get_plots_varying_params(bg_chains, relevant_bgs[i], signal_chain, data_chain, super_vars,
                                     mva_type2, varying_param3, NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str);
  MVAAnalysis::get_plots_varying_params(bg_chains, relevant_bgs[i], signal_chain, data_chain, super_vars,
                                     mva_type2, varying_param4, NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str);*/

 if(std::ifstream("~/mproject/ICMSciThesisHiggsInv/TMVApp1.root")){remove("~/mproject/ICMSciThesisHiggsInv/TMVApp1.root");} // very important otherwise doesnt get deleted

  }
//void DataCard::create_datacard(mc_weights, data_chain, signal_chain, bg_chains, var,true, variables)

  for (int i = 0; i < 1; i++)
  {
    // HistoPlot::draw_plot(vars[4], bg_chains, signal_chain, data_chain, true, &cut_vars, true,false,"outline.png");
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true,argv);
  theApp.Run();
  return 0;
}

/*
#include <iostream> 
#include <cstdlib> 
using namespace std;

int main(int argc, char* argv[]) { 
   for(int i = 1; i < argc; i++) 
      cout << atoi(argv[i]) << endl; 
   return 0; 
}
*/
