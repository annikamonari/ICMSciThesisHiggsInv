#include "../include/mva_analysis.h"

void MVAAnalysis::plot_output(DataChain* combined_data)
{
  combined_data->chain->Draw("output>>output_hist(100, -0.8, 0.8)");
  //TH1F* output = (TH1F*)gDirectory->Get("output_hist");

  //return output;
}

std::vector<double> MVAAnalysis::get_x_range(TH1F* output_histo)
{
  double x_min = output_histo->GetBinCenter(output_histo->FindFirstBinAbove(0.0, 1));
  double x_max = output_histo->GetBinCenter(output_histo->FindLastBinAbove(0.0, 1));
  double x_arr[] = {x_min, x_max};

  std::vector<double> x_range (x_arr, x_arr + sizeof(x_arr) / sizeof(x_arr[0]));

  return x_range;
}

std::vector<double> MVAAnalysis::get_categories(std::vector<double> x_range)
{
  double x_arr[] = {x_range[0], x_range[0] * 0.6, 0, x_range[1] * 0.6, x_range[1]};

	 std::vector<double> categories (x_arr, x_arr + sizeof(x_arr) / sizeof(x_arr[0]));

	 return categories;
}

std::vector<std::string> MVAAnalysis::get_category_strs(std::vector<double> categories)
{
  std::string cat_strs[4];

	 for (int i = 0; i < 4; i++)
  {
    cat_strs[i] = "(output >" + HistoPlot::get_string_from_double(categories[i]) + ")&&(output <= " + HistoPlot::get_string_from_double(categories[i+1]) + ")";
  }
	 std::vector<std::string> cat_strs_vector (cat_strs, cat_strs + sizeof(cat_strs) / sizeof(cat_strs[0]));

	 return cat_strs_vector;
}

TH1F* MVAAnalysis::build_histo(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																					std::vector<Variable*>* variables, DataChain* bg_chain)
{
  std::string selection_str = HistoPlot::get_selection(variable, variables, with_cut, is_signal, bg_chain);
  if (selection != "")
  {
  		selection_str.insert(selection_str.find("(") + 1, selection + "&&");
  }
  std::cout << selection_str << std::endl;
  std::string var_arg = variable->build_var_string(bg_chain->label, with_cut);
  std::cout << var_arg << std::endl;
  data->Draw(var_arg.c_str(), selection_str.c_str());

  //return (TH1F*)gDirectory->Get(bg_chain->label);
}


TH1F* MVAAnalysis::draw_signal(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																		std::vector<Variable*>* variables, DataChain* bg_chain)
{
  data->SetLineColor(2);
  data->SetLineWidth(3);
  data->SetFillColor(0);
  TH1F* signal_histo = build_histo(data, selection, variable, with_cut, true, variables, bg_chain);

  return signal_histo;
}

TH1F* MVAAnalysis::draw_background(TChain* data, std::string selection, Variable* variable, bool with_cut, bool is_signal,
																						std::vector<Variable*>* variables, DataChain* bg_chain)
{
  data->SetLineColor(1);
  data->SetFillColor(40);

  return build_histo(data, selection, variable, with_cut, false, variables, bg_chain);
}

void MVAAnalysis::draw_histo(Variable* variable, TChain* data, std::vector<Variable*>* variables, DataChain* bg_chain)
{
  data->Draw("output>>output(100, -1.0, 1.0)");
  TH1F* pre_histo = (TH1F*)gDirectory->Get("output");
  /*std::vector<std::string> category_sels = get_category_strs(get_categories(get_x_range(pre_histo)));
  TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);
  TCanvas* c1     = new TCanvas("c1", "BDT Output", 800, 800);

  TH1F* very_sig = build_histo(data, category_sels[3], variable, true, true, variables, bg_chain);
  //TH1F* very_bg = build_histo(data, category_sels[0], variable, true, false, variables, bg_chain);

  legend->AddEntry(very_sig, "Signal", "f");
  //legend->AddEntry(very_bg, bg_chain->legend, "f");

  very_sig->Draw();
  std::cout << "vs histo drawn" << std::endl;
  //very_bg->Draw("SAME");
  std::cout << "histos drawn" << std::endl;
  //c1->SaveAs("output_test.png");
  //c1->Close();*/
}
