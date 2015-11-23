#include "../include/histo_plot.h"
#include "../include/analysis.h"
#include <initializer_list>
#include <cmath>

void produce_graphs() {
	Variable* jet1_pt = new Variable("jet1_pt","Jet 1 pT", "0.0", "600.0", "420.0", "440.0","10","100");
	Variable* jet2_E = new Variable("jet2_E","Jet 2 Energy", "0.0", "5000.0", "2400.0", "2700.0","50","30");
	Variable* jet1_eta = new Variable("jet1_eta","Jet 1 Eta", "-5.0", "5.0", "0.6", "1.0","50","50");
	Variable* forward_tag_eta = new Variable("forward_tag_eta","Forward Tag Eta", "-5.0", "5.0", "4.1", "4.3","25","30");
	Variable* dijet_deta = new Variable("dijet_deta","Dijet Delta", "3.0", "8.0", "6.4", "6.7","25","10");
	Variable* dijet_sumeta = new Variable("dijet_sumeta","Dijet Sum of Eta", "-6.0", "6.0","3.5", "4.0","50","1");
	Variable* met = new Variable("met","MET", "0.0", "400.0","270.0", "320.0","25","1");
	Variable* metnomu_x = new Variable("metnomu_x","MET-X Excluding Muons", "-400.0", "400.0","340.0", "400.0","25","10");
	Variable* metnomu_y = new Variable("metnomu_y","MET-Y Excluding Muons", "-400.0", "400.0","200.0", "400.0","50","10");
	Variable* met_significance = new Variable("met_significance","MET Significance", "0.0", "12.0","7.2", "10.0","25","10");
	Variable* metnomu_significance = new Variable("metnomu_significance","MET Excluding Muons Significance", "2.0", "12.0","6.8", "10.2","10","20");
	Variable* sumet = new Variable("sumet","Sum of Transverse Energy", "0.0", "2400.0","1900.0", "2400.0","50","100");
	Variable* ht = new Variable("ht", "HCAL Scalar Sum of Energy","0.0", "1200.0","125.0", "175.0","100","10");
	Variable* ht30 = new Variable("ht30","HCAL Scalar Sum of Energy over 30GeV", "0.0", "1200.0","100.0", "150.0","100","100");
	Variable* sqrt_ht = new Variable("sqrt_ht","Square Root HCAL Scalar Sum of Energy", "0.0", "35.0","10.0", "13.0","50","30");
	Variable* unclustered_et = new Variable("unclustered_et","Unclustered Transverse Energy", "0.0", "2000.0","1400.0", "1600.0","50","50");
	Variable* jet1met_dphi = new Variable("jet1met_dphi","(Jet-1,MET); dphi", "0.0", "3.5","2.1", "2.4","50","50");
	Variable* jet2met_dphi = new Variable("jet2met_dphi","(Jet-2,MET); dphi", "0.0", "3.5","1.4", "1.7","30","30");
	Variable* jet1metnomu_dphi = new Variable("jet1metnomu_dphi","(Jet-1,MET); dphi Excluding Muons", "0.0", "3.5","2.1", "2.5","50","50");
	Variable* jet2metnomu_dphi = new Variable("jet2metnomu_dphi","(Jet-2,MET); dphi Excluding Muons", "0.0", "3.5","1.4", "1.7","30","30");
	Variable* jetmetnomu_mindphi = new Variable("jetmetnomu_mindphi","(Two leading jets, MET); min dphi", "0.0", "3.5","2.9", "3.1","25","10");
	Variable* alljetsmet_mindphi = new Variable("alljetsmet_mindphi","(All jets, MET); min dphi", "0", "3.2","2.2", "3.0","25","10");
	Variable* alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi","(All jets, MET); min dphi excluding muons", "0.0", "3.5","2.2", "3.0","25","10");
	Variable* jetunclet_mindphi = new Variable("jetunclet_mindphi","(Two Leading Jets, Unclustered Transverse Energy); min dphi", "0.0", "3.5","2.8", "2.9","25","10");
	Variable* dijetmet_scalarSum_pt = new Variable("dijetmet_scalarSum_pt","Scalar Sum of Transverse Momentum of Two Leading Jets and MET", "0.0", "1200.0","800.0", "900.0","25","30");
	Variable* dijetmet_vectorialSum_pt = new Variable("dijetmet_vectorialSum_pt","Vectorial Sum of Transverse Momentum of Two Leading Jets and MET", "0.0", "400.0","240.0", "250.0","100","100");
	Variable* jet2met_scalarprod = new Variable("jet2met_scalarprod","Jet-2 Scalar Product with MET", "-400.0", "400.0","20.0", "50.0","100","100");
	Variable* dijetmetnomu_scalarSum_pt = new Variable("dijetmetnomu_scalarSum_pt","The Scalar Sum of MET and Two Leading Jets Excluding Muons", "0.0", "1200.0","800.0", "950.0","20","30");
	Variable* l1met = new Variable("l1met","Level 1 trigger MET", "0.0", "400.0","250.0", "400.0","10","40");
	Variable* metnomuons = new Variable("metnomuons","MET Excluding Muons", "0.0", "400.0","320.0", "400.0","25","15");
	Variable* mht = new Variable("mht","Missing HCAL Scalar Sum of Energy", "0.0", "3000.0","2400.0", "2800.0","25","1");
	Variable* met_x = new Variable("met_x","MET-X", "-400.0", "400.0","370.0", "400.0","25","1");
	Variable* met_y = new Variable("met_y","MET-Y", "-400.0", "400.0","180.0", "400.0","25","10");

  DataChain* bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend);
  DataChain* bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
  DataChain* bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
  DataChain* bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
  DataChain* bg_top        = new DataChain(top, top_label, top_legend);
  DataChain* bg_vv         = new DataChain(vv, vv_label, vv_legend);
  DataChain* bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
  DataChain* bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
  DataChain* signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
  DataChain* data_chain    = new DataChain(data, data_label, data_legend);
  DataChain* myDataChain[8] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv,
          bg_top, bg_vv, bg_zjets_vv, bg_qcd};

  std::vector<DataChain*> bg_chains (myDataChain, myDataChain + sizeof(myDataChain) / sizeof(myDataChain[0]));

  HistoPlot::draw_stacked_histo(variable, bg_chains, signal_chain, data_chain, false);
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  return 0;
}
