#include "../include/mva_analysis.h"
#include "../include/bdt_analysis.h"
#include "../include/mlp_analysis.h"

TH1F* MVAAnalysis::plot_output(DataChain* combined_data)
{
  combined_data->chain->Draw("output>>output_hist(100, -0.8, 0.8)");
  TH1F* histo = (TH1F*)gDirectory->Get("output_hist");

  return histo;
}

std::vector<double> MVAAnalysis::get_categories(TH1F* output_histo)
{
  int first_bin = output_histo->FindFirstBinAbove(0.0, 1);
  int zero_bin = output_histo->FindBin(0.0);
  int last_bin = output_histo->FindLastBinAbove(0.0, 1);
  double total_integral = output_histo->Integral(0, output_histo->GetNbinsX() + 1);

  double tmp_integral_bg;
  double tmp_integral_sig;
  int bg_bin;
  int sig_bin;
  //bg
  for (int i = zero_bin; i > first_bin; i--)
  	{
    tmp_integral_bg = output_histo->Integral(first_bin, i);
    bg_bin = i;
    if ((tmp_integral_bg / total_integral) < 0.1)
    	{
    		break;
    	}
  	}
  std::cout << "bg" << bg_bin << std::endl;
  //sig
  for (int i = zero_bin; i < last_bin; i++)
  {
    tmp_integral_sig = output_histo->Integral(i, last_bin);
    sig_bin = i;
    if ((tmp_integral_bg / total_integral) < 0.1)
    {
      break;
    }
  }
  std::cout << "sig" << sig_bin << std::endl;
	 double bg_up_lim = output_histo->GetBinCenter(bg_bin);
  double sig_low_lim = output_histo->GetBinCenter(sig_bin);
  double x_arr[] = {-0.8, bg_up_lim, 0, sig_low_lim, 0.8};
  std::cout << "bg_xmax" << bg_up_lim << std::endl;
  std::cout << "sig_xmin" << sig_low_lim << std::endl;
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

TH1F* MVAAnalysis::build_histo(DataChain* combined_output, std::string selection_str, Variable* variable, std::string histo_label)
{
  std::string hist_label = combined_output->extra_label + histo_label;

  std::string var_arg = variable->build_var_string(hist_label.c_str(), true);

  combined_output->chain->Draw(var_arg.c_str(), selection_str.c_str(), "goff");

  TH1F* histo = (TH1F*)gDirectory->Get(hist_label.c_str());

  return histo;
}

std::string MVAAnalysis::build_output_sel_str(std::string category, std::string final_cuts)
{
	 std::string selection_str = final_cuts;
	 selection_str.insert(selection_str.find("(") + 1, category + "&&");

	 return selection_str;
}

TH1F* MVAAnalysis::draw_signal(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(2);
  combined_output->chain->SetLineWidth(3);
  combined_output->chain->SetFillColor(0);

  TH1F* histo = build_histo(combined_output, build_output_sel_str(category, final_cuts), variable, "signal");

  return histo;
}

TH1F* MVAAnalysis::draw_background(DataChain* combined_output, std::string category, std::string final_cuts, Variable* variable)
{
  combined_output->chain->SetLineColor(1);
  combined_output->chain->SetFillColor(40);

  TH1F* hist = build_histo(combined_output, build_output_sel_str(category, final_cuts), variable, "bg");

  return hist;
}

void MVAAnalysis::style_histo(TH1F* histo)
{
	 histo->GetYaxis()->SetTitle("Events");
	 histo->GetYaxis()->SetLabelSize(0.035);
	 histo->GetYaxis()->SetTitleOffset(1.55);
	 histo->GetXaxis()->SetLabelSize(0);
	 histo->SetStats(kFALSE);
	 histo->SetTitle("");
}

void MVAAnalysis::draw_histo(DataChain* combined_output, std::string final_cuts, Variable* variable)
{
	 std::vector<std::string> category_strs = get_category_strs(get_categories(plot_output(combined_output)));

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
  p2->cd();

  TH1F* very_sig = draw_signal(combined_output, category_strs[3], final_cuts, variable);
  TH1F* very_bg  = draw_background(combined_output, category_strs[0], final_cuts, variable);

  legend->AddEntry(very_sig, "Signal (Top 10% of output)", "f");
  legend->AddEntry(very_bg, "Background (Bottom 10% of output)", "f");
  HistoPlot::style_legend(legend);

  very_bg->Draw();
  very_sig->Draw("SAME");
  legend->Draw("SAME");
  style_histo(very_bg);
  style_histo(very_sig);
  TH1F* plot_histos[2] = {very_sig, very_bg};
  std::vector<TH1F*> plot_histos_vector (plot_histos, plot_histos + sizeof(plot_histos) / sizeof(plot_histos[0]));
  TH1F* max_histo = HistoPlot::get_max_histo(plot_histos_vector);

  very_bg->SetMaximum(HistoPlot::get_histo_y_max(max_histo)*1.1);

  HistoPlot::draw_subtitle(variable, NULL, true, combined_output, final_cuts);

  p3->cd();
  TH1F* data_bg_ratio_histo = HistoPlot::data_to_bg_ratio_histo(plot_histos[0], plot_histos[1]);
  data_bg_ratio_histo->Draw("e1");
  HistoPlot::style_ratio_histo(data_bg_ratio_histo, variable->name_styled);
  HistoPlot::draw_yline_on_plot(variable, true, 1.0);
  p1->cd();
  HistoPlot::draw_title((combined_output->extra_label).c_str());

  c1->SaveAs("output_test.png");
  c1->Close();
}

void MVAAnalysis::plot_bdt_results(std::vector<DataChain*> bg_chains, DataChain* signal_chain, DataChain* data_chain, SuperVars* super_vars, const char* NTrees, const char* BoostType,const char* AdaBoostBeta,const char* SeparationType,const char* nCuts)
{
	 std::vector<Variable*> vars      = super_vars->get_signal_cut_vars();
	 std::vector<Variable*> vars2      = super_vars->get_discriminating_vars();
	 std::string selection_str        = super_vars->get_final_cuts_str();
	 std::string var_cut_str_tmva     = super_vars->get_cuts_str_for_tmva();

	 BDTAnalysis::create_BDT(bg_chains[0], signal_chain, &vars2, var_cut_str_tmva, NTrees,BoostType,AdaBoostBeta,
	SeparationType, nCuts);

	 std::vector<DataChain*> output_bg_chains = get_output_bg_chains(bg_chains, vars, var_cut_str_tmva);
	 DataChain* output_signal_chain           = get_output_signal_chain(signal_chain, vars, var_cut_str_tmva);
  Variable* mva_output = new Variable("output","MVA Output","-1.0","1.0","-0.8","0.8","125","1", "", false);
  HistoPlot::draw_plot(mva_output, output_bg_chains, output_signal_chain, data_chain, true, &vars, false);
}

std::vector<DataChain*> MVAAnalysis::get_output_bg_chains(std::vector<DataChain*> bg_chains, std::vector<Variable*> vars, std::string var_cut_str_tmva)
{
  std::vector<DataChain*> output_bg_chains;

	 for (int i = 0; i < bg_chains.size(); i++)
  {
	 		DataChain* combined_output = BDTAnalysis::get_BDT_results(bg_chains[i], &vars, var_cut_str_tmva);
	 		output_bg_chains.push_back(combined_output);
  }

	 return output_bg_chains;
}

DataChain* MVAAnalysis::get_output_signal_chain(DataChain* signal_chain, std::vector<Variable*> vars, std::string var_cut_str_tmva)
{
  return BDTAnalysis::get_BDT_results(signal_chain, &vars, var_cut_str_tmva);
}

void MVAAnalysis::train_and_run_BDT(std::vector<DataChain*> bg_chains, DataChain* signal_chain, std::vector<Variable*> vars, std::string var_cut_str_tmva,const char* mva_type)
{  
  if (!strcmp(mva_type, "BDT"))
  {
  for (int j=0; j < 1/*bg_chains.size*/; j++)//variable loop
    {    
        BDTAnalysis::create_BDT(bg_chains[j], signal_chain, &vars, var_cut_str_tmva,
        NTrees[0],BoostType[0],AdaBoostBeta[0],SeparationType[0], nCuts[0]);
	BDTAnalysis::get_BDT_results(bg_chains[j], &vars,var_cut_str_tmva);
    }
   }
  if (!strcmp(mva_type, "MLP"))
  {
        MLPAnalysis::create_MLP(bg_chains[0], signal_chain, &vars, var_cut_str_tmva,
        NeuronType[0],NCycles[0],HiddenLayers[5]);
        MLPAnalysis::get_MLP_results(bg_chains[0], &vars, var_cut_str_tmva);
   }
}
