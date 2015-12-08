#include "../include/super_vars.h"

SuperVars::SuperVars()
{
		forward_tag_eta = new Variable("forward_tag_eta","ForwardTagEta","-5.0","5.0","1.8",
																																	"5.0","60","50", true);
		dijet_deta = new Variable("dijet_deta","DijetDeta","3.5","8.0","4.2","8.0","25","100");
		metnomu_significance = new Variable("metnomu_significance","METExcludingMuonsSignificance",
																																						"3.0","12.0","3.5","","50","70");
		sqrt_ht = new Variable("sqrt_ht","SquareRootHCALScalarSumofEnergy","0.0","35.0","9.0",
																									"18.0","75","50");
		alljetsmetnomu_mindphi = new Variable("alljetsmetnomu_mindphi","Alljets,METmindphiexcludingmuons",
																																								"0.0","3.5","0.5","3.0","40","50");
		dijet_M = new Variable("dijet_M","DijetMass","0.0","2000.0","800.0","","50","100");
		metnomuons = new Variable("metnomuons","METExcludingMuons","0.0","400.0","120.0","",
																												"50","80");
		jet1_E = new Variable("jet1_E","Jet1E","0.0","5000.0","50.0","","30","100");
		jet2_E = new Variable("jet2_E","Jet2E","0.0","5000.0","45.0","","30","100");
}

std::vector<Variable*> SuperVars::get_discriminating_vars()
{
		Variable* var_arr[] = {alljetsmetnomu_mindphi};

		std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

		return vars;
}

std::vector<Variable*> SuperVars::get_signal_cut_vars()
{
		Variable* var_arr[] =		{metnomu_significance, alljetsmetnomu_mindphi, dijet_deta};
																									/*{m_mumu, forward_tag_eta, dijet_deta, metnomu_significance, sqrt_ht, dijet_M,
																									alljetsmetnomu_mindphi, metnomuons, jet1_pt, jet2_eta, central_tag_eta,
																									dijet_dphi, metnomu_x, metnomu_y,  ht, ht30, unclustered_et, jet1metnomu_dphi,
																									jet1metnomu_scalarprod, jet2metnomu_dphi, jetmetnomu_mindphi, jet2met_scalarprod,
																									l1met};*/

		std::vector<Variable*> vars (var_arr, var_arr + sizeof(var_arr) / sizeof(var_arr[0]));

		return vars;
}


