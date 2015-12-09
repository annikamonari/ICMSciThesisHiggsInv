#include "../include/histo_plot.h"
#include <algorithm>

void HistoPlot::draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
																										DataChain* signal_chain, DataChain* data, bool with_cut, std::map<const char*, std::map<const char*, double> > mc_weights_ptr,	std::vector<Variable*>* variables)
{
  TCanvas* c1            = new TCanvas("c1", var->name_styled, 800, 700);
  TPad* p1															= new TPad("p1", "p1", 0.0, 0.9, 1.0, 1.0);
  TPad* p2															= new TPad("p2", "p2", 0.0, 0.0, 1.0, 0.9);
  TLegend* legend        = new TLegend(0.0, 0.5, 0.0, 0.88);

  p1->Draw();
  p2->Draw();
  p2->cd();

  THStack stack 	 	 					= draw_stacked_histo(legend, var, bg_chains, with_cut, mc_weights_ptr, variables);
  TH1F* signal_histo 	 		= draw_signal(signal_chain, var, with_cut, legend, mc_weights_ptr,false, variables);
  TH1F* data_histo   	 		= draw_data(data, var, with_cut, legend,mc_weights_ptr,false, variables);

  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  style_stacked_histo(&stack, var->name_styled);

  TH1F* plot_histos[3] = {(TH1F*)(stack.GetStack()->Last()), data_histo, signal_histo};
  TH1F* max_histo 	   	= get_max_histo(plot_histos);

  draw_subtitle(var, variables, with_cut, data, mc_weights_ptr);
  stack.SetMaximum(get_histo_y_max(max_histo)*1.1);
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
}

std::string HistoPlot::get_selection(Variable* variable, std::vector<Variable*>* variables,bool with_cut, bool is_signal, DataChain* bg_chain,
                                    std::map<const char*, std::map<const char*, double> > mc_weights_ptr, 
                                   bool is_background
)
{
		std::string selection;

		if ((variables != NULL) && (with_cut))
	 {
	  	selection = variable->build_multicut_selection(is_signal, variables);
	 }
	 else
	 {
	  	selection = variable->build_selection_string(with_cut, is_signal);
	 }

		selection.insert(selection.find("(") + 1, lep_sel_default() + "&&");

		return add_mc_to_selection(bg_chain, variable, selection, mc_weights_ptr, is_background);
}

std::string HistoPlot::add_mc_to_selection(DataChain* bg_chain, Variable* variable,std::string selection,  
					std::map<const char*, std::map<const char*, double> > mc_weights_ptr, bool is_background,std::vector<Variable*>* variables
)
{
std::cout<<"mc weight test in add mc to sel"<<bg_chain->mc_weights[variable->name]<<"\n";
  if (strcmp(bg_chain->label, "data_chain") && strcmp(bg_chain->label, "signal_chain"))
  {
/*double test  = bg_chain->mc_weights[variable->name];
std::cout<<"variable name = "<<variable->name<<"--mc weight = "<< test<<"\n";*/
	   std::string mc_weight_str = get_string_from_double(mc_weights_ptr[bg_chain->label][variable->name]);
    return selection.insert(selection.find("*") + 1, mc_weight_str + "*");
  }
  else
  {
  		return selection;
  }
}

std::string HistoPlot::get_string_from_double(double num)
{
  std::ostringstream num_ss;
  num_ss << num;
  std::string num_str(num_ss.str());

  return num_str;
}

std::string HistoPlot::sig_to_bg_ratio(Variable* var, TH1F* bg,
																																							TH1F* signal_histo, bool with_cut)
{


  double bg_integral 				= get_histo_integral(bg, with_cut, var);
  double sig_integral 			= get_histo_integral(signal_histo, with_cut, var);
  float signal_mult 					= atof(var->signal_multiplier);
  float sig_to_bg 							= sig_integral / bg_integral / signal_mult;

  std::ostringstream stb;
  stb << sig_to_bg;
  std::string sig_to_bg_str(stb.str());

		return sig_to_bg_str;
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

std::string HistoPlot::replace_all(std::string str, const std::string& from, const std::string& to)
{
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }

  return str;
}

std::string HistoPlot::style_selection(std::string selection)
{
	 std::string sele = replace_all(replace_all(replace_all(replace_all(selection, ")", ""), ">", " > "), "==", " = "), "&&", ", ");

	 return replace_all(replace_all(replace_all(replace_all(replace_all(sele, "_", " "), "))", ""), "(", ""), "((", ""), "<", " < ");
}

void HistoPlot::draw_subtitle(Variable* variable, std::vector<Variable*>* variables,bool with_cut, DataChain* data,std::map<const char*, std::map<const char*, double> > mc_weights_ptr)
{
		std::string selection = "Selection: " + style_selection(get_selection(variable, variables, with_cut, false, data,mc_weights_ptr,true));
		std::replace(selection.begin(), selection.end(), '(', ' ');
		std::replace(selection.begin(), selection.end(), ')', ' ');
		std::string line_1 = "#font[12]{" + selection.substr(0, 88) + "-}";
		std::string line_2 = "#font[12]{" + selection.substr(88, 88) + "-}";
		std::string line_3 = "#font[12]{" + selection.substr(176, 88) + "}";

	 /*TLatex t;
	 t.SetTextSize(0.03);
	 t.DrawLatexNDC(0.1, 0.97, line_1.c_str());
		t.Draw();

		TLatex d;
		d.SetTextSize(0.03);
		d.DrawLatexNDC(0.1, 0.94, line_2.c_str());
		d.Draw();

		TLatex f;
		f.SetTextSize(0.03);
		f.DrawLatexNDC(0.1, 0.91, line_3.c_str());
		f.Draw();*/
}


THStack HistoPlot::draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains,
																																						bool with_cut, std::map<const char*, std::map<const char*, double> > mc_weights_ptr, std::vector<Variable*>* variables)
{
  THStack stack(var->name_styled, "");

  for(int i = 0; i < bg_chains.size(); i++) {
    std::cout<<"adding background "<<bg_chains[i]->label<<", "<<var->name<<" with mc = "<<mc_weights_ptr[bg_chains[i]->label][var->name]<<"\n";
    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut,mc_weights_ptr, variables);
    stack.Add(single_bg_histo);
    std::string legend_str(bg_chains[i]->legend);
    legend_str += (" #font[12]{(MC weight: " + get_string_from_double(bg_chains[i]->mc_weights[var->name]) + ")}");
    legend->AddEntry(single_bg_histo, legend_str.c_str(), "f");
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
  double x2 = x1 + 0.26;

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
    return 0.56;
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
  legend->SetTextSize(0.025);
  legend->SetBorderSize(0);
}

TH1F* HistoPlot::build_1d_histo(DataChain* data_chain, Variable* variable, bool with_cut, bool is_signal,const char* option, std::map<const char*, std::map<const char*, double> > mc_weights_ptr, 
                              bool is_background,
std::vector<Variable*>* variables,
                             std::string selection)
{
		std::string var_arg   = variable->build_var_string(data_chain->label, with_cut);
  std::string selection_str;

  if (selection == "")
  {
  		selection_str = get_selection(variable, variables, with_cut, is_signal, data_chain, mc_weights_ptr, is_background);
  }
  else
  {
  		selection_str = selection;
  }

  data_chain->chain->Draw(var_arg.c_str(), selection_str.c_str(), option);

  return (TH1F*)gDirectory->Get(data_chain->label);
}

TH1F* HistoPlot::draw_data(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend, std::map<const char*, std::map<const char*, double> > mc_weights_ptr, 
                                   bool is_background,
																											std::vector<Variable*>* variables)
{
  data_chain->chain->SetMarkerStyle(7);
  data_chain->chain->SetMarkerColor(1);
  data_chain->chain->SetLineColor(1);
  TH1F* data_histo = set_error_bars(build_1d_histo(data_chain, variable, with_cut, false, "E1",mc_weights_ptr,false, variables));
  legend->AddEntry(data_histo, data_chain->legend, "lep");

  return data_histo;
}

TH1F* HistoPlot::draw_signal(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend, std::map<const char*, std::map<const char*, double> > mc_weights_ptr, 
                                   bool is_background,

																													std::vector<Variable*>* variables)
{
  data_chain->chain->SetLineColor(2);
  data_chain->chain->SetLineWidth(3);
  data_chain->chain->SetFillColor(0);
  TH1F* signal_histo = build_1d_histo(data_chain, variable, with_cut, true, "goff",mc_weights_ptr,false, variables);
  legend->AddEntry(signal_histo, (build_signal_leg_entry(variable, data_chain)).c_str(), "l");

  return signal_histo;
}

TH1F* HistoPlot::draw_background(DataChain* data_chain, Variable* variable, 
                                 int fill_colour, bool with_cut,
			                              std::map<const char*, std::map<const char*, double> > mc_weights_ptr,   
                                 std::vector<Variable*>* variables)
{
  data_chain->chain->SetLineColor(1);
  data_chain->chain->SetFillColor(fill_colour);
  bool is_background = true;
  return build_1d_histo(data_chain, variable, with_cut, false, "goff",mc_weights_ptr,false, variables);
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
