#include "../include/super_vars.h"

SuperVars::SuperVars()
{
		jet1_E = new Variable("jet1_E","Jet1E","0.0","5000.0","50.0","","30","100");
		jet2_E = new Variable("jet2_E","Jet2E","0.0","5000.0","45.0","","30","100");
		jet1_pt = new Variable("jet1_pt","Jet1pT","0.0","600.0","40.0","500.0","50","100");
		jet2_eta = new Variable("jet2_eta","Jet2Eta","-5.0","5.0","0.2","5.0","60","20");
		forward_tag_eta = new Variable("forward_tag_eta","ForwardTagEta","-5.0","5.0","1.8",
																																	"5.0","60","50",true);
		central_tag_eta = new Variable("central_tag_eta","CentralTagEta","-5.0","5.0","0.0",
																																	"5.0","50","50");
		dijet_deta = new Variable("dijet_deta","DijetDeta","3.5","8.0","4.2","8.0","25","100");
		dijet_dphi = new Variable("dijet_dphi","Dijetdphi","0.0","3.2","0.0","2.2","35","40");
		metnomu_x = new Variable("metnomu_x","MET-XExcludingMuons","-400.0","400.0","0.0",
																											"400.0","60","70");
		metnomu_y = new Variable("metnomu_y","MET-YExcludingMuons","-400.0","400.0","0.0",
																											"300.0","70","70");
		metnomu_significance = new Variable("metnomu_significance","METExcludingMuonsSignificance",
																																						"3.0","12.0","3.5","","50","70");
		ht = new Variable("ht","HCALScalarSumofEnergy","0.0","1200.0","50","600","60","50");
		ht30 = new Variable("ht30","HCALScalarSumofEnergyover30GeV","0.0","1200.0","50.0",
																						"1100.0","75","30");
		sqrt_ht = new Variable("sqrt_ht","SquareRootHCALScalarSumofEnergy","0.0","35.0","9.0",
																									"18.0","75","50");
		unclustered_et = new Variable("unclustered_et","UnclusteredTransverseEnergy","0.0",
																																"2000.0","0.0","1000.0","75","0");
		jet1metnomu_dphi = new Variable("jet1metnomu_dphi","Jet-1,METdphiExcludingMuons","0.0",
																																		"3.5","1.5","2.5","60","100");
		jet1metnomu_scalarprod = new Variable("jet1metnomu_scalarprod",
																																								"(Jet-1,MET)ScalarProductExcludingMuons","-2000.0",
																																								"2000.0","0.0","1000.0","90","60");
		jet2metnomu_dphi = new Variable("jet2metnomu_dphi","Jet-2,METdphiExcludingMuons","0.0",
																																		"3.5","0.5","3.2","60","100");
		jetmetnomu_mindphi = new Variable("jetmetnomu_mindphi","Twoleadingjets,METmindphi","0.0",
																																				"3.5","0.5","3.2","40","70");
		alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi","Alljets,METmindphiexcludingmuons",
																																								"0.0","3.5","0.5","3.0","40","50");
		dijet_M = new Variable("dijet_M","DijetMass","0.0","2000.0","800.0","","50","100");
		jet2met_scalarprod = new Variable("jet2met_scalarprod","Jet-2ScalarProductwithMET","-400.0",
																																				"400.0","0.0","100.0","100","100");
		l1met = new Variable("l1met","Level1triggerMET","0.0","400.0","0.0","250.0","50","40");
		metnomuons = new Variable("metnomuons","METExcludingMuons","0.0","400.0","120.0","",
																												"50","80");
		m_mumu = new Variable("m_mumu","MMuonMuon","0","400.0","60","120",
																														"50","80");
		nvetoelectrons = new Variable("nvetoelectrons","Number of Vetoed Electrons","0","20.0","0","",
																																"10","10");
		nvetomuons = new Variable("nvetomuons","Number of Vetoed Muons","0","20.0","0","",
																																		"10","10");
		ntaus = new Variable("ntaus","Number of Taus","0","20.0","0","", "10","10");
		nselelectrons = new Variable("nselelectrons","Number of Selected Electrons","0","20.0","0","",
																																						"10","10");
		nselmuons = new Variable("nselmuons","Number of Selected Muons","0","20.0","0", "", "10","10");
}

std::vector<Variable*> SuperVars::get_var_vector()
{
		Variable* var_arr[] = {metnomu_significance};
																								/*dijet_deta, sqrt_ht, dijet_M,alljetsmetnomu_mindphi, metnomuons, jet1_pt, jet2_eta, central_tag_eta,
																									dijet_dphi, metnomu_x, metnomu_y,  ht, ht30, unclustered_et, jet1metnomu_dphi,
																									jet1metnomu_scalarprod, jet2metnomu_dphi, jetmetnomu_mindphi, jet2met_scalarprod,
																									l1met*/

		std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

		return vars;
}

std::vector<Variable*> SuperVars::get_cut_vector()
{
		Variable* var_arr[] =		{metnomu_significance, alljetsmetnomu_mindphi, dijet_deta, nvetoelectrons, nvetomuons};
																									/*{m_mumu, forward_tag_eta, dijet_deta, metnomu_significance, sqrt_ht, dijet_M,
																									alljetsmetnomu_mindphi, metnomuons, jet1_pt, jet2_eta, central_tag_eta,
																									dijet_dphi, metnomu_x, metnomu_y,  ht, ht30, unclustered_et, jet1metnomu_dphi,
																									jet1metnomu_scalarprod, jet2metnomu_dphi, jetmetnomu_mindphi, jet2met_scalarprod,
																									l1met};*/

		std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

		return vars;
}
