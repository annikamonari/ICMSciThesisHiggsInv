#include "../include/super_chains.h"

SuperChains::SuperChains(std::vector<Variable*>* discriminating_vars, std::vector<Variable*>* cut_vars, bool with_cut)
{
		bg_zll        = new DataChain(z_ll, z_ll_label, z_ll_legend, "(nselmuons == 2)&&(m_mumu>60)&&(m_mumu<120)");
		bg_wjets_ev   = new DataChain(wjets_ev, wjets_ev_label, wjets_ev_legend, "(nselelectrons == 1)");
		bg_wjets_muv  = new DataChain(wjets_muv, wjets_muv_label, wjets_muv_legend, "(nselmuons == 1)");
		bg_wjets_tauv = new DataChain(wjets_tauv, wjets_tauv_label, wjets_tauv_legend, "(ntaus == 1)");
		bg_top        = new DataChain(top, top_label, top_legend);
		bg_vv         = new DataChain(vv, vv_label, vv_legend);
		bg_zjets_vv   = new DataChain(zjets_vv, zjets_vv_label, zjets_vv_legend);
		bg_qcd        = new DataChain(qcd, qcd_label, qcd_legend);
		signal_chain  = new DataChain(mc_signal_data, mc_signal_label, mc_signal_legend);
		data_chain    = new DataChain(data, data_label, data_legend);
		mc_weights    = build_mc_weight_map(discriminating_vars, cut_vars, with_cut);

		set_chain_mc_weights();
}

std::vector<DataChain*> SuperChains::get_bg_chains()
{
		DataChain* bg_chain_arr[] = {bg_zll, bg_wjets_ev, bg_wjets_muv,
																															bg_wjets_tauv, bg_top, bg_vv,
																															bg_zjets_vv, bg_qcd};

		std::vector<DataChain*> bg_chains (bg_chain_arr, bg_chain_arr + sizeof(bg_chain_arr) / sizeof(bg_chain_arr[0]));

		return bg_chains;
}

std::map<const char*, std::map<const char*, double> > SuperChains::build_mc_weight_map(std::vector<Variable*>* discriminating_vars,
																																																																									std::vector<Variable*>* cut_vars,
																																																																									bool with_cut)
{
	 std::vector<DataChain*> bg_chains = get_bg_chains();
	 std::map<const char*, std::map<const char*, double> > mc_weights;

  for (int i = 0; i < bg_chains.size(); i++)
  {
    mc_weights[bg_chains[i]->label] = get_var_mc_weights(bg_chains[i], discriminating_vars, cut_vars, with_cut);
  }

  return set_bg_zjets_vv_weights(mc_weights, discriminating_vars);
}

std::map<const char*, double> SuperChains::get_var_mc_weights(DataChain* bg_chain, std::vector<Variable*>* vars,
																																																															std::vector<Variable*>* cut_vars, bool with_cut)
{
	 std::map<const char*, double> var_weights;

	 for (int i = 0; i < (*vars).size(); i++)
	 {
	 		if (bg_chain->lep_sel != "")
	   {
	   		var_weights[(*vars)[i]->name] = MCWeights::calc_mc_weight(data_chain, get_bg_chains(),
																																																																bg_chain, (*vars)[i], with_cut, cut_vars);
	   }
	   else
	   {
	   		var_weights[(*vars)[i]->name] = 1.0;
	   }
	 }

	 return var_weights;
}

std::map<const char*, std::map<const char*, double> > SuperChains::set_bg_zjets_vv_weights(std::map<const char*, std::map<const char*,
																																																																																											double> > mc_weights,
																																																																																											std::vector<Variable*>* vars)
{
	 for (int i = 0; i < (*vars).size(); i++)
	 {
    mc_weights[bg_zjets_vv->label][(*vars)[i]->name] = mc_weights[bg_zll->label][(*vars)[i]->name] * 5.651 * 1.513;
	 }

	 return mc_weights;
}

void SuperChains::set_chain_mc_weights()
{
	 bg_zll->set_mc_weights(mc_weights[bg_zll->label]);
		bg_wjets_ev->set_mc_weights(mc_weights[bg_wjets_ev->label]);
		bg_wjets_muv->set_mc_weights(mc_weights[bg_wjets_muv->label]);
		bg_wjets_tauv->set_mc_weights(mc_weights[bg_wjets_tauv->label]);
		bg_top->set_mc_weights(mc_weights[bg_top->label]);
		bg_vv->set_mc_weights(mc_weights[bg_vv->label]);
		bg_zjets_vv->set_mc_weights(mc_weights[bg_zjets_vv->label]);
		bg_qcd->set_mc_weights(mc_weights[bg_qcd->label]);
}
