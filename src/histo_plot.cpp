#include "../include/histo_plot.h"

void HistoPlot::draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
                                   DataChain* signal_chain, DataChain* data, bool with_cut)
{
  std::string var_str = var->build_title_string(with_cut);
  const char* var_name   = var_str.c_str();
  TCanvas* c1            = new TCanvas("c1", var_name);
  TLegend* legend        = new TLegend(0.0, 0.5, 0.0, 0.88);
  THStack stack 	 	 = draw_stacked_histo(legend, var, bg_chains, with_cut);
  TH1F* signal_histo 	 = draw_signal(signal_chain, var, with_cut);

  TH1F* data_histo   	 = draw_data(data, var, with_cut);

  legend->AddEntry(signal_histo, (build_signal_leg_entry(var, signal_chain)).c_str(), "l");
  legend->AddEntry(data_histo, data->legend, "lep");

  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  const char* x_axis_label =var->name_styled;

  style_stacked_histo(&stack, x_axis_label);

  TH1F* plot_histos[3] = {(TH1F*)(stack.GetStack()->Last()), data_histo, signal_histo};
  TH1F* max_histo 	   = get_max_histo(plot_histos);
  double y_max 		   = get_histo_y_max(max_histo);

  stack.SetMaximum(y_max);

  build_legend(legend, max_histo, var, with_cut);

  c1->SaveAs((build_file_name(var, with_cut)).c_str());
  c1->Close();
}

THStack HistoPlot::draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains, bool with_cut)
{
  std::string var_str = var->build_title_string(with_cut);
  const char* var_name   = var_str.c_str();
  THStack stack(var_name, var_name);
  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut);
    stack.Add(single_bg_histo);
    legend->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  }
  return stack;
}

/*{
  std::string var_str = var->build_title_string(with_cut);
  const char* var_name   = var_str.c_str();
  std::string file_name  = build_file_name(var, with_cut);
  TCanvas* c1            = new TCanvas("c1", var_name);
  TLegend* legend        = new TLegend(0.0, 0.5, 0.0, 0.88);
  style_legend(legend);
  THStack stack(var_name, var_name);

  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut);
    stack.Add(single_bg_histo);
    //legend->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  }
  TH1F* signal_histo = draw_signal(signal_chain, var, with_cut);
  TH1F* data_histo   = draw_data(data, var, with_cut);

  //legend->AddEntry(signal_histo, signal_chain->legend, "l");
  //legend->AddEntry(data_histo, data->legend, "lep");
  
  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  const char* x_axis_label =var->name_styled;
  style_stacked_histo(&stack, x_axis_label);

  TH1F* last_stacked  = (TH1F*)(stack.GetStack()->Last());
  std::list<double> y_max_list = get_y_max(data_histo, last_stacked);
  double y_max = y_max_list.front();
  TH1F* which_histo;
  if (y_max_list.back() == 1.0)
  {
    which_histo = last_stacked;
  }
  else
  {
	which_histo = data_histo;
  }
  std::list<double> leg_coords = legend_coords(which_histo, var, with_cut, y_max);
  stack.SetMaximum(y_max);
  //legend->SetX1(leg_coords.front());
  //legend->SetX2(leg_coords.back());
  //legend->Draw();
  

  c1->SaveAs(file_name.c_str());
  c1->Close();
  std::cout << "display " << file_name  << "\n";
}

std::list<double> HistoPlot::get_y_max(TH1F* data, TH1F* background)
{
  double data_max = data->GetBinContent(data->GetMaximumBin());
  double bg_max = background->GetBinContent(background->GetMaximumBin());
  std::list<double> y_max_list;
  if (data_max > bg_max)
  {
	y_max_list.push_back(data_max*1.1);
    y_max_list.push_back(0.0);
  }
  else
  {
	y_max_list.push_back(bg_max*1.1);
	y_max_list.push_back(1.0);
  }
  return y_max_list;
}

std::list<TH1F*> HistoPlot::get_histos_from_stack(THStack* hs)
{
  TList* histos = hs->GetHists();
  std::list<TH1F*> histo_list;
  TIter next(histos);
  TH1F* histo;
  while ((histo =(TH1F*)next())) {
    histo_list.push_back(histo);
  }
  return histo_list;
}


std::list<double> HistoPlot::legend_coords(TH1F* histo, Variable* var, bool with_cut, double y_max)
{
  double x_min;
  double x_max;

  if (with_cut) 
  {
    x_min = atof(var->x_min_cut);
    x_max = atof(var->x_max_cut);
  }
  else 
  {
    x_min = atof(var->x_min_nocut);
    x_max = atof(var->x_max_nocut);
  }

  double dx            = x_max - x_min;
  double dy            = y_max;
  double x_width       = 0.18;
  float y1             = 0.5;
  double y1_gc         = get_x_from_x1(y1, dy);
  float y2             = 0.88;
  legend->SetX1(leg_coords.front());
  legend->SetX2(leg_coords.back());
  legend->Draw();
nt start_bin        = histo->FindBin(get_x_from_x1(0.12, dx));
  int stop_bin         = histo->FindBin(get_x_from_x1(0.67, dx));

  double x1_best       = 0.0;
  int min_data_overlap = 100;
  for (int i = start_bin; i <= stop_bin; i++) 
  {
    float x1         = get_x1_from_x(histo->GetXaxis()->GetBinCenter(i), dx);
    int end_bin      = histo->FindBin(get_x_from_x1(x1 + x_width, dx));
    TLegend* leg     = new TLegend(x1, y1, x1 + x_width, y2);
    int data_overlap = get_leg_overlap(histo, leg, i, end_bin, y1_gc);
    if (data_overlap <= min_data_overlap)
    {
      min_data_overlap = data_overlap;
      x1_best          = x1;
    }
  }
  double x2 = x1_best + x_width;

  std::list<double> leg_coords;
  leg_coords.push_front(x2);
  leg_coords.push_front(x1_best);
  return leg_coords;
}

int HistoPlot::get_leg_overlap(TH1F* histo, TLegend* leg, int start_bin, int end_bin, double y1_gc) 
{
  int data_overlap = 0;
  

  for (int i = start_bin; i <= end_bin; i++) 
  {
    double x = histo->GetXaxis()->GetBinCenter(i);
    double y = histo->GetBinContent(i);
    if (y > y1_gc)
    {
     data_overlap += 1;
    }
  }

  return data_overlap;
}

float HistoPlot::get_x_from_x1(float x1, double dx) 
{
  return (x1 - 0.1) * dx / 0.8;
}

float HistoPlot::get_x1_from_x(float x, double dx) 
{
  return x * 0.8 / dx + 0.1;
}*/


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
  double x1 	  = position_legend_x1(max_histo, var, with_cut);
  double x2 	  = x1 + 0.18;

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
  hs->GetYaxis()->SetTitleOffset(1.35);
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
                                bool is_signal, const char* option) 
{
  std::string var_arg   = variable->build_var_string(data_chain->label, with_cut);
  std::string selection = variable->build_selection_string(with_cut, is_signal);

  data_chain->chain->Draw(var_arg.c_str(), selection.c_str(), option);

  return (TH1F*)gDirectory->Get(data_chain->label);
}

TH1F* HistoPlot::draw_data(DataChain* data_chain, Variable* variable, bool with_cut)
{
  data_chain->chain->SetMarkerStyle(7);
  data_chain->chain->SetMarkerColor(1);
  data_chain->chain->SetLineColor(1);

  TH1F* histo = set_error_bars(build_1d_histo(data_chain, variable, with_cut, false, "E1"));

  return histo;
}

TH1F* HistoPlot::draw_signal(DataChain* data_chain, Variable* variable, bool with_cut)
{
  data_chain->chain->SetLineColor(2);
  data_chain->chain->SetLineWidth(3);
  data_chain->chain->SetFillColor(0);

  return build_1d_histo(data_chain, variable, with_cut, true, "goff");
}

TH1F* HistoPlot::draw_background(DataChain* data_chain, Variable* variable, 
                                 int fill_colour, bool with_cut) 
{
  data_chain->chain->SetLineColor(1);
  data_chain->chain->SetFillColor(fill_colour);

  return build_1d_histo(data_chain, variable, with_cut, false, "goff");
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
  std::string file_name("dijm/");
  file_name.append(variable->name);

  if (with_cut)
  {
    file_name += "_cut_";
    file_name.append((variable->bins_cut).c_str());
    file_name += "_";
    file_name.append(variable->x_min_cut);
    file_name += "_";
    file_name.append(variable->x_max_cut);
    file_name += "+";
    file_name.append("dijm");

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



