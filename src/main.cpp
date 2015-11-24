#include "../include/histo_plot.h"
#include "../include/analysis.h"
#include <initializer_list>
#include <cmath>

void produce_graphs() {
	Variable* jet1_pt = new Variable("jet1_pt","Jet 1 pT", "0.0", "600.0", "40.0", "90.0","50","100");
	Variable* jet2_eta = new Variable("jet2_eta","Jet 2 Eta", "-5.0", "5.0", "-5.0", "-3.7","60","20");
	Variable* forward_tag_eta = new Variable("forward_tag_eta","Forward Tag Eta", "-5.0", "5.0", "-5.0", "-3.8","60","50");
	Variable* central_tag_eta = new Variable("central_tag_eta","Central Tag Eta", "-5.0", "5.0", "-4.0", "-3.0","50","50");
	Variable* dijet_deta = new Variable("dijet_deta","Dijet Deta", "3.6", "8.0", "5.5", "8.0","25","100");
	Variable* dijet_dphi = new Variable("dijet_dphi","Dijet dphi", "0.0", "3.2", "0.0", "2.2","35","40");
	Variable* metnomu_x = new Variable("metnomu_x","MET-X Excluding Muons", "-400.0", "400.0","-400.0", "-180.0","60","70");
	Variable* metnomu_y = new Variable("metnomu_y","MET-Y Excluding Muons", "-400.0", "400.0","140.0", "300.0","70","70");
	Variable* metnomu_significance = new Variable("metnomu_significance","MET Excluding Muons Significance", "2.0", "12.0","5.2", "12.0","50","70");
	Variable* ht = new Variable("ht", "HCAL Scalar Sum of Energy","0.0", "1200.0","75.0", "175.0","60","50");
	Variable* ht30 = new Variable("ht30","HCAL Scalar Sum of Energy over 30GeV", "0.0", "1200.0","50.0", "140.0","75","30");
	Variable* sqrt_ht = new Variable("sqrt_ht","Square Root HCAL Scalar Sum of Energy", "0.0", "35.0","9.0", "13.0","75","50");
	Variable* unclustered_et = new Variable("unclustered_et","Unclustered Transverse Energy", "0.0", "2000.0","200.0", "1000.0","75","0");
	Variable* jet1metnomu_dphi = new Variable("jet1metnomu_dphi","Jet-1,MET dphi Excluding Muons", "0.0", "3.5","1.5", "2.5","60","100");
	Variable* jet1metnomu_scalarprod = new Variable("jet1metnomu_scalarprod","(Jet-1,MET); Scalar Product Excluding Muons", "-2000.0", "2000.0","-2000.0", "-400.0","90","60");
	Variable* jet2metnomu_dphi = new Variable("jet2metnomu_dphi","Jet-2,MET dphi Excluding Muons", "0.0", "3.5","0.5", "2.2","60","100");
	Variable* jetmetnomu_mindphi = new Variable("jetmetnomu_mindphi","Two leading jets, MET min dphi", "0.0", "3.5","0.5", "2.2","40","70");
	Variable* alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi","All jets, MET min dphi excluding muons", "0.0", "3.5","1.7", "3.0","40","50");
	Variable* dijet_M = new Variable("dijet_M","Dijet Mass", "0.0", "1800.0","900.0", "3000.0","50","100");
	Variable* jet2met_scalarprod = new Variable("jet2met_scalarprod","Jet-2 Scalar Product with MET", "-400.0", "400.0","20.0", "50.0","100","100");
	Variable* l1met = new Variable("l1met","Level 1 trigger MET", "0.0", "400.0","130.0", "250.0","50","40");
	Variable* metnomuons = new Variable("metnomuons","MET Excluding Muons", "0.0", "400.0","180.0", "400.0","50","80");

	Variable* var_arr[] = {jet1_pt, jet2_eta, forward_tag_eta, central_tag_eta, dijet_deta, dijet_dphi, metnomu_x, metnomu_y,
						   metnomu_significance, ht, ht30, sqrt_ht, unclustered_et, jet1metnomu_dphi, jet1metnomu_scalarprod,
						   jet2metnomu_dphi, jetmetnomu_mindphi, alljetsmetnomu_mindphi, dijet_M, jet2met_scalarprod, l1met,
						   metnomuons};

	std::vector<Variable*> variables (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

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

  DataChain* myDataChain[] = {bg_zll, bg_wjets_ev, bg_wjets_muv, bg_wjets_tauv,bg_top, bg_vv, bg_zjets_vv, bg_qcd};

  std::vector<DataChain*> bg_chains (myDataChain, myDataChain + sizeof(myDataChain) / sizeof(myDataChain[0]));

  for (int i = 0; i < variables.size(); i++) {
	  HistoPlot::draw_stacked_histo(variables[i], bg_chains, signal_chain, data_chain, false);
  }
}

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  produce_graphs();

  theApp.Run();
  return 0;
}
