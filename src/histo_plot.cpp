#include "../include/histo_plot.h"

void HistoPlot::draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
																										DataChain* signal_chain, DataChain* data, bool with_cut,
																										std::vector<Variable*>* variables)
{
  TCanvas* c1            = new TCanvas("c1", var->name_styled, 800, 700);
  TPad* p1															= new TPad("p1", "p1", 0.0, 0.9, 1.0, 1.0);
  TPad* p2															= new TPad("p2", "p2", 0.0, 0.0, 1.0, 0.9);
  TLegend* legend        = new TLegend(0.0, 0.5, 0.0, 0.88);

  p1->Draw();
  p2->Draw();
  p2->cd();

  THStack stack 	 	 					= draw_stacked_histo(legend, var, bg_chains, with_cut, data, variables);
  TH1F* signal_histo 	 		= draw_signal(signal_chain, var, with_cut, legend, variables);
  TH1F* data_histo   	 		= draw_data(data, var, with_cut, legend, variables);

  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  style_stacked_histo(&stack, var->name_styled);

  TH1F* plot_histos[3] = {(TH1F*)(stack.GetStack()->Last()), data_histo, signal_histo};
  TH1F* max_histo 	   	= get_max_histo(plot_histos);

  draw_subtitle(var, variables, with_cut, plot_histos[0], plot_histos[2]);

  stack.SetMaximum(get_histo_y_max(max_histo)*1.2);
  build_legend(legend, max_histo, var, with_cut);

  p1->cd();
  draw_title(var->name_styled);

  c1->SaveAs((build_file_name(var, with_cut)).c_str());
  c1->Close();
}

void HistoPlot::draw_title(const char* title)
{
		TPaveText* pt = new TPaveText(0.1, 0.1, 0.9, 1.0, "blNDC");
		pt->SetBorderSize(0);
		pt->SetFillColor(0);
		pt->AddText(title);
		pt->SetAllWith(title, "size", 0.5);
		pt->Draw();

	/*TLatex t;
		t.SetTextSize(0.5);
		t.DrawLatexNDC(0.1, 0.5, title);
		t.Draw();*/
}

std::string HistoPlot::get_selection(Variable* variable, std::vector<Variable*>* variables,
																																					bool with_cut, bool is_signal, std::string lepton_sel)
{
		std::string selection;

		if ((variables != NULL) && (with_cut))
	 {
	  	selection = variable->build_multicut_selection(is_signal, variables, lepton_sel);
	 }
	 else
	 {
	  	selection = variable->build_selection_string(with_cut, is_signal, lepton_sel);
	 }

		return selection;
}

double HistoPlot::integral_ratio(Variable* var, TH1F* denom_histo, TH1F* numerator_histo, bool with_cut)
{
  double numerator_integral = get_histo_integral(numerator_histo, with_cut, var);
  double denom_integral 			 = get_histo_integral(denom_histo, with_cut, var);

  return numerator_integral / denom_integral;
}

double HistoPlot::get_histo_integral(TH1F* histo, bool with_cut, Variable* var)
{
		int nbins;
		if (with_cut)
		{
				nbins = (int) (atof(var->bins_cut.c_str()) + 0.5);
		}
		else
		{
				nbins = (int) (atof(var->bins_nocut) + 0.5);
		}

		return histo->Integral(0, nbins + 1);
}

void HistoPlot::draw_subtitle(Variable* variable, std::vector<Variable*>* variables,
																														bool with_cut, TH1F* last_stacked, TH1F* signal_histo)
{

		std::string selection = get_selection(variable, variables, with_cut, false);
		std::string plot_subtitle("#font[12]{");
		std::string s_bg("Signal to Background Ratio: " + get_string_from_double(integral_ratio(variable, last_stacked, signal_histo, with_cut)));
		std::string s_int(" / Signal Integral: " + get_string_from_double(get_histo_integral(signal_histo, with_cut, variable)));
		std::string plot_subsubtitle = s_bg + s_int;

		if (!with_cut)
		{
				plot_subtitle += "No cuts implemented." + s_bg;
		}
		else
		{

				if (selection.length() > 69)
				{

						std::string first_line 			= selection.substr(0, 69);
						//selection.erase(selection.length() - 22, 22);
 
						if (selection.length() > 138)
						{
								std::string second_line = selection.substr(69, 138);
								//std::string third_line 	= selection.substr(148, selection.length() - 1);
								plot_subtitle 									+= ("#splitline{With cuts:" + first_line + "-}{" + second_line + "}");

						}
						else
						{
 								std::string second_line = selection.substr(69, selection.length() - 1);    

								plot_subtitle += ("#splitline{With cuts: " + first_line + "-}{" + second_line + "}");
						}

				}
				else
				{
						plot_subtitle += selection;
				}
		}

		plot_subtitle += "}";

	 /*TLatex t;
	 t.SetTextSize(0.03);
	 t.DrawLatexNDC(0.1, 0.96, plot_subtitle.c_str());
		t.Draw();

		TLatex g;
		g.SetTextSize(0.025);
		g.DrawLatexNDC(0.1, 0.91, plot_subsubtitle.c_str());
		g.Draw();*/

}

std::string HistoPlot::get_string_from_double(double num)
{
	 std::ostringstream num_ss;
	 num_ss << num;
	 std::string num_str(num_ss.str());

	 return num_str;
}

THStack HistoPlot::draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains,
																																						bool with_cut, DataChain* data_chain, std::vector<Variable*>* variables)
{
  THStack stack(var->name_styled, "");

  for(int i = 0; i < bg_chains.size(); i++) {
   double other_bg_in_ctrl = get_other_bg_in_ctrl(bg_chains, var, with_cut, variables, bg_chains[i]->lepton_selection);
   std::string lep_sel_w_mc_weight = get_mc_weight_lep_sel_str(bg_chains[i], data_chain, var, variables, with_cut,
																																																															other_bg_in_ctrl);
   std::cout << bg_chains[i]->label << " -- mc weight string: " << lep_sel_w_mc_weight << std::endl;
   TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut, variables, lep_sel_w_mc_weight);
   stack.Add(single_bg_histo);
   legend->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  }

  return stack;
}

TH1F* HistoPlot::get_max_histo(TH1F** plot_histos)
{
  double plot_max = 0.0;
  TH1F* histo_max = NULL;

  for (int i = 1; i < 3; i++)
  {
    double y_max = get_histo_y_max(plot_histos[i]);
    if (y_max > plot_max)
    {
      plot_max = y_max;
      histo_max = plot_histos[i];
    }
  }
  return histo_max;
}

double HistoPlot::get_histo_y_max(TH1F* histo)
{
  return histo->GetBinContent(histo->GetMaximumBin());
}

void HistoPlot::build_legend(TLegend* legend, TH1F* max_histo, Variable* var, bool with_cut)
{
  double x1 = position_legend_x1(max_histo, var, with_cut);
  double x2 = x1 + 0.18;

  style_legend(legend);

  legend->SetX1(x1);
  legend->SetX2(x2);
  legend->Draw();
}

double HistoPlot::position_legend_x1(TH1F* max_histo, Variable* var, bool with_cut)
{
  int max_bin 		= max_histo->GetMaximumBin();
  double nbins		= var->get_bins(with_cut);
  double max_bin_x1 = get_x1_from_bin(max_bin, nbins);

  if (max_bin_x1 > 0.5)
  {
    return 0.12;
  }
  else
  {
    return 0.7;
  }
}

double HistoPlot::get_x1_from_bin(double max_bin, double nbins)
{
  return max_bin * 0.8 / nbins + 0.1;
}

void HistoPlot::style_stacked_histo(THStack* hs, const char* x_label)
{
  hs->GetYaxis()->SetTitle("Events");
  hs->GetYaxis()->SetLabelSize(0.035);
  hs->GetYaxis()->SetTitleOffset(1.55);
  hs->GetXaxis()->SetTitle(x_label);
  hs->GetXaxis()->SetLabelSize(0.035);
  hs->GetXaxis()->SetTitleOffset(1.35);
}

void HistoPlot::style_legend(TLegend* legend)
{
  legend->SetTextSize(0.035);
  legend->SetBorderSize(0);
}

TH1F* HistoPlot::build_1d_histo(DataChain* data_chain, Variable* variable, bool with_cut, 
                                bool is_signal, const char* option, std::vector<Variable*>* variables, std::string lepton_sel)
{
		std::string var_arg   = variable->build_var_string(data_chain->label, with_cut);
  std::string selection = get_selection(variable, variables, with_cut, is_signal, lepton_sel);

  data_chain->chain->Draw(var_arg.c_str(), selection.c_str(), option);

  return (TH1F*)gDirectory->Get(data_chain->label);
}

TH1F* HistoPlot::draw_data(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
																											std::vector<Variable*>* variables, std::string lepton_sel)
{
  data_chain->chain->SetMarkerStyle(7);
  data_chain->chain->SetMarkerColor(1);
  data_chain->chain->SetLineColor(1);
  TH1F* data_histo = set_error_bars(build_1d_histo(data_chain, variable, with_cut, false, "E1", variables));
  legend->AddEntry(data_histo, data_chain->legend, "lep");

  return data_histo;
}

TH1F* HistoPlot::draw_signal(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
																													std::vector<Variable*>* variables, std::string lepton_sel)
{
  data_chain->chain->SetLineColor(2);
  data_chain->chain->SetLineWidth(3);
  data_chain->chain->SetFillColor(0);
  TH1F* signal_histo = build_1d_histo(data_chain, variable, with_cut, true, "goff", variables);
  legend->AddEntry(signal_histo, (build_signal_leg_entry(variable, data_chain)).c_str(), "l");

  return signal_histo;
}

TH1F* HistoPlot::draw_background(DataChain* data_chain, Variable* variable, int fill_colour, bool with_cut,
																																	std::vector<Variable*>* variables, std::string lepton_sel)
{
  data_chain->chain->SetLineColor(1);
  data_chain->chain->SetFillColor(fill_colour);

  return build_1d_histo(data_chain, variable, with_cut, false, "goff", variables, lepton_sel);
}


TH1F* HistoPlot::set_error_bars(TH1F* histo) 
{
  int nbins = histo->GetNbinsX();
  
  for(int i = 0; i < nbins; i++) {
    double error_val = get_data_error(histo, i);
    histo->SetBinError(i, error_val);
  }

  return histo;
}

float HistoPlot::get_data_error(TH1F* histo, int bin) 
{
  double integral = histo->Integral(bin, bin + 1);

  return std::pow(integral, 0.5);
}

std::string HistoPlot::build_file_name(Variable* variable, bool with_cut) 
{
  std::string file_name(variable->name);

  if (with_cut)
  {
    file_name += "_cut_";
    file_name.append((variable->bins_cut).c_str());
    file_name += "_";
    file_name.append(variable->x_min_cut);
    file_name += "_";
    file_name.append(variable->x_max_cut);
  }
  else
  {
    file_name += "_nocut_";
    file_name.append(variable->bins_nocut);
    file_name += "_";
    file_name.append(variable->x_min_nocut);
    file_name += "_";
    file_name.append(variable->x_max_nocut);
  }
  file_name += ".png";

  return file_name;
}

std::string HistoPlot::build_signal_leg_entry(Variable* var, DataChain* signal_chain)
{
  std::string signal_leg_str(signal_chain->legend);
  signal_leg_str += " (x";
  signal_leg_str.append(var->signal_multiplier);
  signal_leg_str += ")";

  return signal_leg_str;
}

double HistoPlot::get_mc_weight(DataChain* bg_chain, DataChain* chain_of_data, double other_bg_in_ctrl,
																																Variable* var, bool with_cut, std::vector<Variable*>* variables)
{
	 std::string lepton_sel = bg_chain->lepton_selection;
		// number of events from process A MC in control region
		double a_events_ctrl_region = get_n_events(bg_chain, var, with_cut, variables, lepton_sel);
		// number of data events process A in control region
		double data_events_ctrl_region = get_n_events(chain_of_data, var, with_cut, variables, lepton_sel);

		return (data_events_ctrl_region - other_bg_in_ctrl) / a_events_ctrl_region;
}

double HistoPlot::get_n_events(DataChain* chain_of_data, Variable* var, bool with_cut,
																															std::vector<Variable*>* variables, std::string lepton_sel)
{
  return get_histo_integral(build_1d_histo(chain_of_data, var, with_cut, true, "goff", variables, lepton_sel), with_cut, var);
}

double HistoPlot::get_other_bg_in_ctrl(std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
																																							std::vector<Variable*>* variables, std::string lepton_sel)
{
  double nevents = 0.0;

  if (lepton_sel != "")
  {
  		for (int i = 0; i < bg_chains.size(); i++)
  		{
    		nevents += get_n_events(bg_chains[i], var, with_cut, variables, lepton_sel);
  		}
  }

  return nevents;
}

std::string HistoPlot::get_mc_weight_lep_sel_str(DataChain* bg_chain, DataChain* data_chain, Variable* var,
																																																	std::vector<Variable*>* variables, bool with_cut, double other_bg_in_ctrl)
{
	 std::string lep_sel_w_mc_weight;
	 double z_ll_mc_weight = 1.0;
	 std::cout << bg_chain->label << std::endl;
	 if (bg_chain->lepton_selection != "")
	 {
	 	 double mc_weight = get_mc_weight(bg_chain, data_chain, other_bg_in_ctrl, var, with_cut, variables);
	   lep_sel_w_mc_weight = get_string_from_double(mc_weight) + "*" + lepton_sel_default();

	   if (!strcmp(bg_chain->label, "bg_zll"))
	   {
	    	z_ll_mc_weight = mc_weight;
		  }
	   std::cout << bg_chain->label << lep_sel_w_mc_weight << std::endl;
  }
  else
  {
  		if (!strcmp(bg_chain->label, "bg_zjets_vv"))
  		{
  				double mc_weight = z_ll_mc_weight * 5.652;
  				lep_sel_w_mc_weight = get_string_from_double(mc_weight) + "*" + lepton_sel_default();
  				std::cout << bg_chain->label << lep_sel_w_mc_weight << std::endl;
  		}
  		else
  		{
  				lep_sel_w_mc_weight = lepton_sel_default();
  				std::cout << bg_chain->label << lep_sel_w_mc_weight << std::endl;
  		}
  }
	 std::cout << bg_chain->label << lep_sel_w_mc_weight << std::endl;
	 return lep_sel_w_mc_weight;
}
