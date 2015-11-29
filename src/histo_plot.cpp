#include "../include/histo_plot.h"

void HistoPlot::draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
																										DataChain* signal_chain, DataChain* data, bool with_cut,
																										std::vector<Variable*> variables)
{
  const char* var_name 	 = var->name_styled;
  TCanvas* c1            = new TCanvas("c1", var_name);
  TLegend* legend        = new TLegend(0.0, 0.5, 0.0, 0.88);
  THStack stack 	 	 					= draw_stacked_histo(legend, var, bg_chains, with_cut);
  TH1F* signal_histo 	 		= draw_signal(signal_chain, var, with_cut, legend);
  TH1F* data_histo   	 		= draw_data(data, var, with_cut, legend);

  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  style_stacked_histo(&stack, var_name);

  TH1F* plot_histos[3] = {(TH1F*)(stack.GetStack()->Last()), data_histo, signal_histo};
  TH1F* max_histo 	   	= get_max_histo(plot_histos);

  stack.SetMaximum(get_histo_y_max(max_histo));
  build_legend(legend, max_histo, var, with_cut);

  c1->SaveAs((build_file_name(var, with_cut)).c_str());
  c1->Close();
}

THStack HistoPlot::draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains,
																																						bool with_cut, std::vector<Variable*> variables)
{
  const char* var_name = var->name_styled;
  THStack stack(var_name, var_name);

  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut, variables);
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
  hs->GetYaxis()->SetTitleOffset(1.45);
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
                                bool is_signal, const char* option, std::vector<Variable*> variables)
{
		std::cout << variables.size() << std::endl;
		std::string var_arg   = variable->build_var_string(data_chain->label, with_cut);
  std::string selection;
  std::cout << variables.size() << std::endl;
  if ((variables.size() > 0) && (with_cut))
  {
  		selection = variable->build_multicut_selection(is_signal, variables);
  }
  else
  {
  		selection = variable->build_selection_string(with_cut, is_signal);
  }
  std::cout << selection << std::endl;
  data_chain->chain->Draw(var_arg.c_str(), selection.c_str(), option);

  return (TH1F*)gDirectory->Get(data_chain->label);
}

TH1F* HistoPlot::draw_data(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
																											std::vector<Variable*> variables)
{
  data_chain->chain->SetMarkerStyle(7);
  data_chain->chain->SetMarkerColor(1);
  data_chain->chain->SetLineColor(1);
  TH1F* data_histo = set_error_bars(build_1d_histo(data_chain, variable, with_cut, false, "E1", variables));
  legend->AddEntry(data_histo, data_chain->legend, "lep");

  return data_histo;
}

TH1F* HistoPlot::draw_signal(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
																													std::vector<Variable*> variables)
{
  data_chain->chain->SetLineColor(2);
  data_chain->chain->SetLineWidth(3);
  data_chain->chain->SetFillColor(0);
  TH1F* signal_histo = build_1d_histo(data_chain, variable, with_cut, true, "goff", variables);
  legend->AddEntry(signal_histo, (build_signal_leg_entry(variable, data_chain)).c_str(), "l");

  return signal_histo;
}

TH1F* HistoPlot::draw_background(DataChain* data_chain, Variable* variable, 
                                 int fill_colour, bool with_cut, std::vector<Variable*> variables)
{
  data_chain->chain->SetLineColor(1);
  data_chain->chain->SetFillColor(fill_colour);

  return build_1d_histo(data_chain, variable, with_cut, false, "goff", variables);
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
