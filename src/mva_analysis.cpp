#include "../include/mva_analysis.h"

TH1F* MVAAnalysis::plot_output(DataChain* combined_data)
{
  combined_data->chain->Draw("output>>output_hist(100, -0.8, 0.8)");
  TH1F* histo = (TH1F*)gDirectory->Get("output_hist");

  return histo;
}

std::vector<double> MVAAnalysis::get_categories(TH1F* output_histo)
{
  double x_min = output_histo->GetBinCenter(output_histo->FindFirstBinAbove(0.0, 1));
  double x_max = output_histo->GetBinCenter(output_histo->FindLastBinAbove(0.0, 1));
  double x_arr[] = {-0.8, x_min * 0.6, 0, x_max * 0.6, 0.8};

  std::vector<double> categories (x_arr, x_arr + sizeof(x_arr) / sizeof(x_arr[0]));

  return categories;
}

std::vector<std::string> MVAAnalysis::get_category_strs(std::vector<double> categories)
{
  std::string cat_strs[4];

	 for (int i = 0; i < 4; i++)
  {
    cat_strs[i] = "(output > " + HistoPlot::get_string_from_double(categories[i]) + ")&&(output <= " + HistoPlot::get_string_from_double(categories[i+1]) + ")";
  }
	 std::vector<std::string> cat_strs_vector (cat_strs, cat_strs + sizeof(cat_strs) / sizeof(cat_strs[0]));
	 std::cout << "cat_strs_vector done" << cat_strs_vector[0] << std::endl;
	 return cat_strs_vector;
}

TH1F* MVAAnalysis::build_histo(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  std::string selection_str = final_cuts;
  std::cout << "final cuts made sel str::" << selection_str << std::endl;
  selection_str.insert(selection_str.find("(") + 1, category + "&&");

  std::cout << selection_str << std::endl;
  std::string var_arg = variable->build_var_string((combined_output->extra_label).c_str(), true);
  std::cout << "label:" << combined_output->extra_label << std::endl;
  std::cout << var_arg << std::endl;
  combined_output->chain->Draw(var_arg.c_str(), selection_str.c_str(), "goff");

  TH1F* histo = (TH1F*)gDirectory->Get((combined_output->extra_label).c_str());

  return histo;
}


TH1F* MVAAnalysis::draw_signal(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(2);
  combined_output->chain->SetLineWidth(3);
  combined_output->chain->SetFillColor(0);

  TH1F* histo = build_histo(combined_output, category, final_cuts, variable);
  std::cout << "sighisto" << histo << std::endl;
  return histo;
}

TH1F* MVAAnalysis::draw_background(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(1);
  combined_output->chain->SetFillColor(40);
  std::cout << "styled" << std::endl;
  TH1F* hist = build_histo(combined_output, category, final_cuts, variable);
  std::cout << "bghisto" << hist << std::endl;
  return hist;
}

void MVAAnalysis::draw_histo(DataChain* combined_output, std::string final_cuts, Variable* variable)
{
	 std::vector<std::string> category_strs = get_category_strs(get_categories(plot_output(combined_output)));
	 std::cout << "final cuts:" << final_cuts << std::endl;
  TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);
  TCanvas* c1     = new TCanvas("c1", variable->name_styled, 800, 800);
  TPad* p1        = new TPad("p1", "p1", 0.0, 0.95, 1.0, 1.0);
  TPad* p2        = new TPad("p2", "p2", 0.0, 0.2, 1.0, 0.95);
  TPad* p3        = new TPad("p3", "p3", 0.0, 0.0, 1.0, 0.2);

  p1->SetLeftMargin(0.102);
  p2->SetBottomMargin(0.012);
  p2->SetLeftMargin(0.105);
  p3->SetBottomMargin(0.3);
  p3->SetLeftMargin(0.102);

  p1->Draw();
  p2->Draw();
  p3->Draw();
  legend->Draw();
  p2->cd();
  std::cout << "setup plot well" << std::endl;
  //TH1F* very_sig = draw_signal(combined_output, category_strs[3], final_cuts, variable);
  TH1F* very_bg   = draw_background(combined_output, category_strs[0], final_cuts, variable);
  std::cout << "made histograms" << std::endl;
  //legend->AddEntry(very_sig, category_strs[3].c_str(), "f");
  //legend->AddEntry(very_bg, category_strs[0].c_str(), "f");
  std::cout << "drew legends" << std::endl;
  very_bg->Draw();
  //very_sig->Draw();
  std::cout << "drew histograms" << std::endl;/*
  TH1F* plot_histos[2] = {very_sig, very_bg};
  very_bg->SetMaximum(HistoPlot::get_histo_y_max(HistoPlot::get_max_histo(plot_histos))*1.1);
  std::cout << "maximum set" << std::endl;
  HistoPlot::draw_subtitle(variable, NULL, true, combined_output, final_cuts);
  std::cout << "draw subtitle" << std::endl;

  p3->cd();
  TH1F* data_bg_ratio_histo = HistoPlot::data_to_bg_ratio_histo(plot_histos[0], plot_histos[1]);
  data_bg_ratio_histo->Draw("e1");
  HistoPlot::style_ratio_histo(data_bg_ratio_histo, variable->name_styled);
  HistoPlot::draw_yline_on_plot(variable, true, 1.0);
  p1->cd();
  HistoPlot::draw_title(combined_output->legend);*/

  c1->SaveAs("output_test.png");
  c1->Close();
}

void MVAAnalysis::plot_bdt_results(DataChain* bg_chain, DataChain* signal_chain, SuperVars* super_vars)
{
	 std::vector<Variable*> vars      = super_vars->get_discriminating_vars();
	 std::string selection_str        = super_vars->get_final_cuts_str();
	 std::string var_cut_str_tmva     = super_vars->get_cuts_str_for_tmva();
  DataChain* combined_output       = BDTAnalysis::get_BDT_results(bg_chain, signal_chain, &vars, var_cut_str_tmva);

  draw_histo(combined_output, selection_str, vars[0]);
}
