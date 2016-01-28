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

	 plot_all_rejBvsS(training_outputs, bg->label, signal, bg, preselection, vars[0], &vars);
}

void RocCurves::plot_all_rejBvsS(std::vector<TFile*> training_outputs, std::string bg_name, DataChain* signal,
																																	DataChain* bg, std::string preselection, Variable* var, std::vector<Variable*>* variables)
{
	 std::string plot_name = bg_name + " ROC Curves";
	 TCanvas* c1     = new TCanvas("c1", plot_name.c_str());
	 TLegend* legend = new TLegend(0.3, 0.2, 0.5, 0.5);
	 TGraph* point   = parked_data_point(signal, bg, preselection, var, variables);
  HistoPlot::style_legend(legend);
	 for (int i = 0; i < 3; i++)
 	{
    std::string file_name(training_outputs[i]->GetName());
    std::cout << "filename" << file_name << std::endl;
    std::string legend_text = HistoPlot::replace_all(file_name, "/", " - ");
    std::cout << "legendtxt" << legend_text << std::endl;
	 		TH1D* rejBvsS_histo    = plot_rejBvsS(training_outputs[i]);
	 		rejBvsS_histo->SetLineColor(HistoPlot::colours()[i]);
	 		rejBvsS_histo->SetStats(false);
	 		rejBvsS_histo->SetLineWidth(2);
	 		if (i == 0) rejBvsS_histo->Draw();
	 		else rejBvsS_histo->Draw("SAME");
	 		std::cout << "hist" << rejBvsS_histo << std::endl;
	 		legend->AddEntry(rejBvsS_histo, legend_text.c_str(), "f");
 	}
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
																										std::vector<Variable*>* variables)
{
  double rejB = 1 - get_presel_effy(bg, preselection, var, variables);
  double sigeff = get_presel_effy(signal, preselection, var, variables);
  std::cout << "signal effy - " << sigeff << std::endl;
  std::cout << "bg rej - " << rejB << std::endl;
  TGraph* point = new TGraph(1);
  point->SetPoint(1, sigeff, rejB);
  point->SetMarkerStyle(20);

  return point;
}

TH1F* RocCurves::histo(DataChain* data, Variable* variable, std::string preselection)
{
	 data->chain->Draw((variable->build_var_string("test", true)).c_str(), preselection.c_str());
	 TH1F* histo = (TH1F*) gDirectory->Get("test");
	 return histo;
}
