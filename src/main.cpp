#include <initializer_list>
#include <cmath>
#include "../include/mva_analysis.h"
#include <iostream> 
//#include "../include/mlp_analysis.h"

void produce_graphs(bool with_cut) {
  SuperVars* super_vars             = new SuperVars();
  std::vector<Variable*> vars       = super_vars->get_discriminating_vars();
  std::vector<Variable*> cut_vars   = super_vars->get_signal_cut_vars();
  SuperChains* super_chains         = new SuperChains();
  std::vector<DataChain*> bg_chains = super_chains->get_bg_chains();
  DataChain* signal_chain           = super_chains->signal_chain;
  DataChain* data_chain             = super_chains->data_chain;
  //std::vector<DataChain*> all_bg_chains = super_chains->get_all_bg_chains();
  std::string mva_type = "MLP";  //go into train_and_run_BDT function to change input parameters
  int bg_id=0;
  int param_id=0;

  const char * vary_param[] = {"NeuronType","NCycles","HiddenLayers","preprocessing_transform"};
  /*bg_id = atoi(command_line_integers[2]);
  param_id = atoi(command_line_integers[1]);*/
  std::string varying_parameter = "HiddenLayers";//vary_param[param_id];
  const char* preprocessing_transform ="N";


  std::string folder_name = "mva_output_plots";

  int relevant_bgs[] = {0, 1, 2, 3,4,5,6,7};//, 6};
  std::string mva_cut_str = "output>0.0";//"output>0.1";//must be in format "output>0"  

//             0         1             2            3            4         5      6            7
//bg[8] = {"bg_zll","bg_wjets_ev","bg_wjets_muv","bg_wjets_tauv", "bg_top", "bg_vv", "bg_zjets_vv", "bg_qcd"};

//const char* mva_cut_arr[]={"output>0.2","output>0.4","output>0.6","output>0.8"};
for(int i =0;i<1; i++){
    if(std::ifstream("TMVApp1.root")){remove("TMVApp1.root");} // very important otherwise doesnt get deleted and seg faults
    //mva_cut_str = mva_cut_arr[i];
    MVAAnalysis::get_mva_results(bg_chains,7, signal_chain, data_chain, super_vars, folder_name, mva_type, NTrees[0], BoostType[0],AdaBoostBeta[0], SeparationType[0], nCuts[0], NeuronType[0],NCycles[0], HiddenLayers[0],mva_cut_str,/*G,D,*/"N");
    //std::cout<<NeuronType[1]<<"\n";
    
}


//std::vector<const char*> files = MVAAnalysis::get_file_vector_for_roc_curves(bg_chains[0]->label, mva_type,"NCycles",preprocessing_transform);
/*
for(int i=0; i<files.size();i++)
{
  std::cout<<"file in files vector number "<<i<<":"<<files[i]<<"\n";
}*/

/*
std::vector<const char*> files2 = MVAAnalysis::get_file_vector_for_roc_curves(bg_chains[0]->label, 
mva_type,"NCycles");
std::cout<<"varying parameter "<<"NCycles"<<"\n";
for(int i=0; i<files2.size();i++)
{
  std::cout<<"file in files vector number "<<i<<":"<<files2[i]<<"\n";
}

std::vector<const char*> files3 = MVAAnalysis::get_file_vector_for_roc_curves(bg_chains[0]->label, 
mva_type,"HiddenLayers");
std::cout<<"varying parameter "<<"HiddenLayers"<<"\n";

for(int i=0; i<files3.size();i++)
{
  std::cout<<"file in files vector number "<<i<<":"<<files3[i]<<"\n";
}
*/


for (int i = 0; i < 1/*bg_chains.size()*/; i++)
  {/*
  		std::cout << "============== FOR BG  " << i << "  ==============" << std::endl;
  		std::cout << "=================================================" << std::endl;
   	
 if(std::ifstream("TMVApp1.root")){remove("TMVApp1.root");} // very important otherwise doesnt get deleted
	
  MVAAnalysis::get_plots_varying_params(all_bg_chains, 0, signal_chain, data_chain, super_vars,
                                     mva_type, varying_parameter, NTrees, BoostType,AdaBoostBeta, SeparationType,
                                      nCuts, NeuronType, NCycles, HiddenLayers,mva_cut_str,"G,D,N");*/

  }

  for (int i = 0; i < 1; i++)
  {
    // HistoPlot::draw_plot(vars[4], bg_chains, signal_chain, data_chain, true, &cut_vars, true,false,"outline.png");
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs(true);
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
