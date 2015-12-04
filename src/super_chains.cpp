#include "../include/super_chains.h"

SuperChains::SuperChains(std::vector<Variable*>* vars, std::vector<Variable*>* cut_vars, bool with_cut)
{
	//lepton_sel syntax must have an open ( at the front
		bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend, "((nselmuons == 2)&&(m_mumu>60)&&(m_mumu<120)");
		bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend, "((nselelectrons == 1)");
		bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend, "((nselmuons == 1)");
		bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend, "((ntaus == 1)");
		bg_top        = new DataChain(top, top_label, top_legend);
		bg_vv         = new DataChain(vv, vv_label, vv_legend);
		bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
		bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
		signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
		data_chain    = new DataChain(data, data_label, data_legend);
		mc_weights 			= build_mc_weight_map(vars, cut_vars, with_cut);
}

std::vector<DataChain*> SuperChains::get_bg_chains()
{
		DataChain* bg_chain_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv,
																															bg_wjets_tauv, bg_top, bg_vv,
																															bg_zjets_vv, bg_qcd};

		std::vector<DataChain*> bg_chains (bg_chain_arr, bg_chain_arr + sizeof(bg_chain_arr) / sizeof(bg_chain_arr[0]));

		return bg_chains;
}

std::map< const char*, std::map < const char*, double > > SuperChains::build_mc_weight_map(std::vector<Variable*>* vars,
																																																																																										std::vector<Variable*>* cut_vars,
																																																																																										bool with_cut)
{
	std::vector<DataChain*> bg_chains = get_bg_chains();
	std::map< const char*, std::map < const char*, double> > mc_weights;

  for (int i = 0; i < bg_chains.size(); i++)
  {
    mc_weights[bg_chains[i]->label] = get_var_mc_weights(bg_chains[i], vars, cut_vars, with_cut);
  }
  return mc_weights;
}

std::map< const char*, double> SuperChains::get_var_mc_weights(DataChain* bg_chain, std::vector<Variable*>* vars,
																																																															std::vector<Variable*>* cut_vars, bool with_cut)
{
	 std::map< const char*, double> var_weights;

	 for (int i = 0; i < (*vars).size(); i++)
	 {
	   if (strcmp(bg_chain->lepton_selection, ""))
	   {
	   		var_weights[(*vars)[i]->name] = HistoPlot::get_mc_weight(bg_chain, data_chain, (*vars)[i], with_cut, cut_vars);
	   }
	   else
	   {
	   		var_weights[(*vars)[i]->name] = 1.0;
	   }
	 }

	 return var_weights;
}
