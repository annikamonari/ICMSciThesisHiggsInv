#include "../include/classifier_outputs.h"

std::vector<TH1D*> ClassifierOutputs::get_classifier_histos(TFile* classifier_output, std::string method_name)
{
	 std::string histo_dir;
	 TH1D* histos[4];

	 if (method_name == "MLP")
	 {
	   histo_dir = "Method_MLP/MLP/MVA_MLP_";
	 }
		else if (method_name == "BDT")
		{
		 	histo_dir = "Method_BDT/BDT/MVA_BDT_";
		}
	 histos[0] = get_histo_from_output(classifier_output, histo_dir + "S;1");
	 histos[1] = get_histo_from_output(classifier_output, histo_dir + "Train_S;1");
	 histos[2] = get_histo_from_output(classifier_output, histo_dir + "B;1");
	 histos[3] = get_histo_from_output(classifier_output, histo_dir + "Train_B;1");

	 std::vector<TH1D*> histos_vector (histos, histos + sizeof(histos) / sizeof(histos[0]));

	 return histos_vector;
}

TH1D* ClassifierOutputs::get_histo_from_output(TFile* file, std::string histo_path)
{
  TH1D* histo = (TH1D*) file->Get(histo_path.c_str());

  return (TH1D*) histo->Clone();
}

std::vector<TH1D*> ClassifierOutputs::normalise_histos(std::vector<TH1D*> histos)
{
  for (int i = 0; i < histos.size(); i++)
  {
    double integral = histos[i]->Integral();
  		histos[i]->Scale(1/integral);
  }

  return histos;
}

void ClassifierOutputs::plot_histos(std::vector<TH1D*> histos, TFile* file)
{
	 std::vector<TH1D*> normalised_histos = histos; //normalise_histos(histos);
	 TCanvas* c1     = new TCanvas("c1", "OverTraining Check");
	 TLegend* legend = new TLegend(0.12, 0.6, 0.38, 0.86);
	 RocCurves::style_legend(legend);
	 int colours[4] = {2, 46, 4, 38};

	 for (int i = 0; i < normalised_histos.size(); i++)
	 {
	 		style_histo(normalised_histos[i], colours[i]);
				std::string leg_entry = "#splitline{" + HistoPlot::replace_all(normalised_histos[i]->GetName(), "_", " ") + "}";
				leg_entry += "{(" + DataCard::double_to_str(normalised_histos[i]->GetEntries()) + " Entries)}";
	 		legend->AddEntry(normalised_histos[i], leg_entry.c_str(), "lep");
	 		normalised_histos[i]->SetMaximum((normalised_histos[0]->GetMaximum())*2.5);
	 		HistoPlot::set_th1d_error_bars(normalised_histos[i]);
	 		normalised_histos[i]->Draw("e1SAME");
	 }
	 draw_ktest(normalised_histos);
	 legend->Draw("SAME");
  std::string file_name(file->GetName());
  file_name = HistoPlot::replace_all(HistoPlot::replace_all(file_name, "bg_zll/", ""), ".root", ".png");
	 c1->SaveAs(file_name.c_str());
	 c1->Close();
}

void ClassifierOutputs::draw_ktest(std::vector<TH1D*> normalised_histos)
{
	 double ktest_sig = normalised_histos[0]->KolmogorovTest(normalised_histos[1]);
		double ktest_bg  = normalised_histos[2]->KolmogorovTest(normalised_histos[3]);
		std::string text = "Kolmogorov Test - signal: " + DataCard::double_to_str(ktest_sig) + "; background: " + DataCard::double_to_str(ktest_bg);
		TPaveText* pt = new TPaveText(0.4, 0.8, 0.9, 0.9, "blNDC");
		pt->SetBorderSize(0);
		pt->SetFillStyle(0);
		pt->AddText(text.c_str());
		pt->SetTextAlign(32);
		pt->SetAllWith(text.c_str(), "size", 0.03);
		pt->Draw("SAME");
}

void ClassifierOutputs::draw_classifier_outputs(TFile* file, std::string method_name)
{
	 std::vector<TH1D*> histos = get_classifier_histos(file, method_name);
	 plot_histos(histos, file);
}

void ClassifierOutputs::style_histo(TH1D* histo, int colour)
{
	 histo->SetMarkerColor(colour);
		histo->SetLineColor(colour);
		histo->SetMarkerStyle(20);
		histo->SetTitle("OverTraining Check");
		histo->SetXTitle("MVA Output");
		histo->SetStats(false);
}
