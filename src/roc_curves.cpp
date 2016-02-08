#include "../include/roc_curves.h"

TH1D* RocCurves::plot_rejBvsS(TFile* training_output)
{
  TH1D* rejBvsS_histo = (TH1D*) training_output->Get("Method_MLP/MLP/MVA_MLP_rejBvsS;1");

  return rejBvsS_histo;
}

void RocCurves::get_rocs(std::vector<TFile*> training_outputs, DataChain* signal,
																									DataChain* bg, SuperVars* super_vars)
{
	 std::vector<Variable*> vars      = super_vars->get_discriminating_vars();
	 std::string preselection         = super_vars->get_final_cuts_str();
	 std::string var_cut_str_tmva     = super_vars->get_cuts_str_for_tmva();
  std::cout << preselection << std::endl;
	 plot_all_rejBvsS(training_outputs, bg->label, signal, bg, preselection, vars[0], &vars);
}

void RocCurves::plot_all_rejBvsS(std::vector<TFile*> training_outputs, std::string bg_name, DataChain* signal,
																																	DataChain* bg, std::string preselection, Variable* var, std::vector<Variable*>* variables)
{
	 std::string plot_name = bg_name + " ROC Curves";
	 TCanvas* c1     = new TCanvas("c1", plot_name.c_str());
	 TLegend* legend = new TLegend(0.15, 0.5, 0.65, 0.2);
	 TGraph* point   = parked_data_point(signal, bg, preselection, var, variables, legend);

	 for (int i = 0; i < 3; i++)
 	{
    std::string file_name(training_outputs[i]->GetName());
    std::string legend_str = HistoPlot::replace_all(HistoPlot::replace_all(file_name, ".root", ""), "/", " - ");
    std::string legend_text = "#splitline{" + legend_str.substr(0, 25) + "}{" + legend_str.substr(26, -1) + "}";

	 		TH1D* rejBvsS_histo    = plot_rejBvsS(training_outputs[i]);
	 		rejBvsS_histo->SetLineColor(HistoPlot::colours()[i+2]);
	 		rejBvsS_histo->SetStats(false);
	 		rejBvsS_histo->SetLineWidth(3);

	 		if (i == 0)
	 		{
	 				rejBvsS_histo->Draw();
	 		}
	 		else
 	  {
	 				rejBvsS_histo->Draw("SAME");
 	  }

	 		legend->AddEntry(rejBvsS_histo, legend_text.c_str(), "f");
 	}
	 style_legend(legend);
	 point->Draw("pSAME");
	 legend->Draw();
	 c1->SaveAs("roc_curves_changing_cycles.png");
	 c1->Close();
}

double RocCurves::get_presel_effy(DataChain* data_chain, std::string preselection, Variable* var, std::vector<Variable*>* variables)
{
	 TH1F* remaining_histo = histo(data_chain, var, preselection);
  TH1F* total_histo = HistoPlot::build_1d_histo(data_chain, var, false, false, "goff", variables, "total_weight_lepveto");

  return remaining_histo->GetEntries() / total_histo->GetEntries();
}

TGraph* RocCurves::parked_data_point(DataChain* signal, DataChain* bg, std::string preselection, Variable* var,
																										std::vector<Variable*>* variables, TLegend* legend)
{
  double rejB = 1 - get_presel_effy(bg, preselection, var, variables);
  double sigeff = get_presel_effy(signal, preselection, var, variables);
  TGraph* point = new TGraph(1);
  point->SetPoint(1, sigeff, rejB);
  point->SetMarkerStyle(20);
  point->SetMarkerColor(kRed);
  legend->AddEntry(point, "Original Preselection", "p");

  return point;
}

TH1F* RocCurves::histo(DataChain* data, Variable* variable, std::string preselection)
{
	 data->chain->Draw((variable->build_var_string("test", true)).c_str(), preselection.c_str());
	 TH1F* histo = (TH1F*) gDirectory->Get("test");
	 return histo;
}

void RocCurves::style_legend(TLegend* legend)
{
	 legend->SetTextSize(0.03);
	 legend->SetBorderSize(0);
	 legend->SetFillStyle(0);
}


