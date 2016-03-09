#include <initializer_list>
#include <cmath>
#include "../include/mva_analysis.h"
#include <iostream> 
//#include "../include/mlp_analysis.h"

void produce_graphs(bool with_cut, const char* command_line_integer) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();
  SuperChains* super_chains         = new SuperChains();
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;
  std::vector<DataChain*> all_bg_chains = super_chains->get_all_bg_chains();
  std::string mva_type = "BDT";  //go into train_and_run_BDT function to change input parameters
   
  const char * vary_param[] = {"NeuronType","NCycles","HiddenLayers","preprocessing_transform","learning_rate"};
  std::string varying_parameter = "HiddenLayers";//vary_param[param_id];
  const char* preprocessing_transform[] ={"N","G,D,N","G,P,N"};
  const char* console_number = command_line_integer;

  std::string folder_name = "mva_output_plots";

  int relevant_bgs[] = {0, 1, 2, 3,4,5,6,7};//, 6};
  std::string mva_cut_str = "output>-1.1";//"output>0.1";//must be in format "output>0"  

//             0         1             2                3           4          5           6            7
//bg[8] = {"bg_zll","bg_wjets_ev","bg_wjets_muv","bg_wjets_tauv", "bg_top", "bg_vv", "bg_zjets_vv", "bg_qcd"};

  //bg_zll
/*for(int i =sizeof(mva_cut_arr)/sizeof(mva_cut_arr[0]);i>0; i--){*/
    if(std::ifstream("TMVApp1.root")){remove("TMVApp1.root");} // very important otherwise doesnt get deleted and seg faults
    if(std::ifstream("TMVApp.root")){remove("TMVApp.root");} 

    MVAAnalysis::get_mva_results(bg_chains, 4, signal_chain, data_chain, super_vars, folder_name, mva_type, NTrees[0], BoostType[0],AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0],NCycles[0], HiddenLayers[2],mva_cut_str,preprocessing_transform[2],"0.02", console_number);
    //std::cout<<NeuronType[1]<<"\n"; GDN
//}

//for (int i = 0; i < bg_chains.size(); i++)
 // {
  //		std::cout << "============== FOR BG  " << i << "  ==============" << std::endl;
  		/*std::cout << "=================================================" << std::endl;
   	
 if(std::ifstream("TMVApp1.root")){remove("TMVApp1.root");} // very important otherwise doesnt get deleted
int i = atoi(command_line_integer);	
  MVAAnalysis::get_plots_varying_params(bg_chains, i, signal_chain, data_chain, super_vars,
                                     mva_type, "NTrees", NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str,"G,D,N",console_number);*/

 // }

  for (int i = 0; i < 1; i++)
  {
    // HistoPlot::draw_plot(vars[4], bg_chains, signal_chain, data_chain, true, &cut_vars, true,false,"outline.png");
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  //produce_graphs(true, argv[1]);
  //PCA::principal();
  theApp.Run();
  return 0;
}


