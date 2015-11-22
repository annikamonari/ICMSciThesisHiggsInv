#include "histo_plot.h"

void HistoPlot::draw_stacked_histo(Variable* var, std::vector<DataChain*> bg_chains, 
                                   DataChain* signal_chain, DataChain* data, bool with_cut)
{
  const char* var_name   = var->name_styled;
  std::string file_name  = build_file_name(var, with_cut);
  TCanvas* c1            = new TCanvas("c1", var_name);
  TLegend* legend        = new TLegend(0.14, 0.5, 0.32, 0.88);
  style_legend(legend);
  THStack stack(var_name, var_name);

  for(int i = 0; i < bg_chains.size(); i++) {
    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut);
    stack.Add(single_bg_histo);
    legend->AddEntry(single_bg_histo, bg_chains[i]->legend, "f");
  }
  std::cout << "bg stack" << std::endl;
  TH1F* signal_histo = draw_signal(signal_chain, var, with_cut);
  TH1F* data_histo   = draw_data(data, var, with_cut);

  legend->AddEntry(signal_histo, signal_chain->legend, "l");
  legend->AddEntry(data_histo, data->legend, "lep");

  stack.Draw();
  data_histo->Draw("SAME");
  signal_histo->Draw("SAME");

  style_stacked_histo(&stack, var_name);

  TH1F* last_stacked  = (TH1F*)(stack.GetStack()->Last());
  double* leg_coords   = legend_coords(last_stacked, var, with_cut);
  std::cout << *leg_coords << std::endl;
  //legend->SetX1(leg_coords[0]);
  //legend->SetX2(leg_coords[1]);
  legend->Draw();
  
  c1->SaveAs(file_name.c_str());
  c1->Close();
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

double* HistoPlot::legend_coords(TH1F* histo, Variable* var, bool with_cut)
{
  // x1(in legend) = x/dx * 0.8 + 0.1
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
  float x_width        = 0.18;
  float y1             = 0.5;
  float y2             = 0.88;
  int start_bin        = histo->FindBin(get_x_from_x1(0.12, dx));
  int stop_bin         = histo->FindBin(get_x_from_x1(0.7, dx));

  float x1_best        = 0.0;
  int min_data_overlap = 100;

  for (int i = start_bin; i <= stop_bin; i++) 
  {
    float x1         = get_x1_from_x(histo->GetXaxis()->GetBinCenter(i), dx);
    int end_bin      = histo->FindBin(get_x_from_x1(x1 + x_width, dx));
    TLegend* leg     = new TLegend(x1, y1, x1 + x_width, y2);
    int data_overlap = get_leg_overlap(histo, leg, start_bin, end_bin);
    std::cout << data_overlap << std::endl;
    if (data_overlap < min_data_overlap) 
    {
      min_data_overlap = data_overlap;
      x1_best          = x1;
    }
  }
  double leg_coords[2] = {x1_best, x1_best + 0.18};
  std::cout << x1_best << std::endl;
  return leg_coords;
}

int HistoPlot::get_leg_overlap(TH1F* histo, TLegend* leg, int start_bin, int end_bin) 
{
  int data_overlap = 0;

  for (int i = start_bin; i <= end_bin; i++) 
  {
    double x = histo->GetXaxis()->GetBinCenter(i);
    double y = histo->GetBinContent(i);

    data_overlap += leg->IsInside(x, y);
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

double HistoPlot::get_data_error(TH1F* histo, int bin) 
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
    file_name.append(variable->bins_cut);
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
