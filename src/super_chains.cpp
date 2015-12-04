#include "../include/super_chains.h"

SuperChains::SuperChains(SuperVars* super_vars)
{
	//lepton_sel syntax must have an open ( at the front
		bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend, super_vars, "((nselmuons == 2)&&(m_mumu>60)&&(m_mumu<120)");
		bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend, super_vars, "((nselelectrons == 1)");
		bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend, super_vars, "((nselmuons == 1)");
		bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend, super_vars, "((ntaus == 1)");
		bg_top        = new DataChain(top, top_label, top_legend, super_vars);
		bg_vv         = new DataChain(vv, vv_label, vv_legend, super_vars);
		bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend, super_vars);
		bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend, super_vars);
		signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend, super_vars);
		data_chain    = new DataChain(data, data_label, data_legend, super_vars);
}

std::vector<DataChain*> SuperChains::get_bg_chains()
{
		DataChain* bg_chain_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv,
																															bg_wjets_tauv, bg_top, bg_vv,
																															bg_zjets_vv, bg_qcd};

		std::vector<DataChain*> bg_chains (bg_chain_arr, bg_chain_arr + sizeof(bg_chain_arr) / sizeof(bg_chain_arr[0]));

		return bg_chains;
}
