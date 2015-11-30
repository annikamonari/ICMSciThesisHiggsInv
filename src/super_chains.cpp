#include "../include/super_chains.h"

SuperChains::SuperChains()
{
		bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend);
		bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend);
		bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend);
		bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend);
		bg_top        = new DataChain(top, top_label, top_legend);
		bg_vv         = new DataChain(vv, vv_label, vv_legend);
		bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
		bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
		signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
		data_chain    = new DataChain(data, data_label, data_legend);
}

std::vector<DataChain*> SuperChains::get_bg_chains(Chains chains)
{
		DataChain* bg_chain_arr[] = {chains.bg_zll, chains.bg_wjets_ev, chains.bg_wjets_muv,
																															chains.bg_wjets_tauv, chains.bg_top, chains.bg_vv,
																															chains.bg_zjets_vv, chains.bg_qcd};

		std::vector<DataChain*> bg_chains (bg_chain_arr, bg_chain_arr + sizeof(bg_chain_arr) / sizeof(bg_chain_arr[0]));

		return bg_chains;
}

