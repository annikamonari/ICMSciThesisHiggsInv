#include "../include/classifier_outputs.h"

void ClassifierOutputs::plot_classifiers_for_all_files(std::vector<TFile*> files, std::string method_name, std::string dir)
{
	 TCanvas* c1 = new TCanvas("c1", "OverTraining Check", 800, 800);
	 std::vector<int> npads = get_npads(files.size());
	 c1->Divide(npads[0], npads[1], 0.00001, 0.005);
  std::cout << "=> Divided Canvas..." << std::endl;
	 for (int i = 0; i < files.size(); i++)
	 {
    c1->cd(i+1);
    draw_classifier_outputs(files[i], method_name);
	 }
  std::string file_name = dir + "/overtraining_check.png";
	 c1->SaveAs(file_name.c_str());
	 c1->Close();
}

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
	 std::cout << "Signal" << histos[0] << std::endl;
	 histos[1] = get_histo_from_output(classifier_output, histo_dir + "Train_S;1");
	 std::cout << "Signal train" << histos[1] << std::endl;
	 histos[2] = get_histo_from_output(classifier_output, histo_dir + "B;1");
	 std::cout << "BG" << histos[2] << std::endl;
	 histos[3] = get_histo_from_output(classifier_output, histo_dir + "Train_B;1");
	 std::cout << "BG train" << histos[3] << std::endl;
	 std::vector<TH1D*> histos_vector (histos, histos + sizeof(histos) / sizeof(histos[0]));

	 return histos_vector;
}

TH1D* ClassifierOutputs::get_histo_from_output(TFile* file, std::string histo_path)
{
  TH1D* histo = (TH1D*) file->Get(histo_path.c_str());
  std::cout << "got histo" << histo << std::endl;
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
	 std::string file_name(file->GetName());
	 file_name                            = HistoPlot::replace_all(file_name, "/", " - ");
	 std::string file_name_parsed         = HistoPlot::replace_all(HistoPlot::replace_all(file_name, ".root", ""), "-", ", ");
	 TLegend* legend                      = new TLegend(0.12, 0.6, 0.38, 0.86);
	 int colours[4]                       = {2, 46, 4, 38};
	 double plot_max                      = get_plot_max(histos);
	 RocCurves::style_legend(legend);

	 for (int i = 0; i < histos.size(); i++)
	 {
	 		style_histo(histos[i], colours[i], i, file_name_parsed, plot_max);
				std::string leg_entry = "#splitline{" + HistoPlot::replace_all(histos[i]->GetName(), "_", " ") + "}";
				leg_entry += "{(" + DataCard::double_to_str(histos[i]->GetEntries()) + " Entries)}";
	 		legend->AddEntry(histos[i], leg_entry.c_str(), "lep");

	 		if(i == 0||i == 2){
			   HistoPlot::set_th1d_error_bars(histos[i]);
	 		  histos[i]->Draw("samee");
			}
			if(i == 1||i == 3){
			  histos[i]->Draw("samehist");
			  histos[i]->Draw("samehist");
			}
	 }
	 draw_ktest(histos);
	 draw_title(file_name_parsed);
	 legend->Draw("SAME");
}

void ClassifierOutputs::draw_ktest(std::vector<TH1D*> normalised_histos)
{
	 double ktest_sig = normalised_histos[0]->KolmogorovTest(normalised_histos[1]);
		double ktest_bg  = normalised_histos[2]->KolmogorovTest(normalised_histos[3]);
		std::string text = "Kolmogorov Test - signal: " + DataCard::double_to_str(ktest_sig) + "; background: " + DataCard::double_to_str(ktest_bg);
		TPaveText* pt = new TPaveText(0.4, 0.9, 0.9, 0.85, "blNDC");
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
	 std::cout << "=> Got Classifier Histos" << std::endl;
	 plot_histos(histos, file);
}

void ClassifierOutputs::style_histo(TH1D* histo, int colour, int hist_no, std::string tfile_name, double plot_max)
{
	if(hist_no == 0 ){//s1
	  histo->SetMarkerColor(colour);
	  histo->SetLineColor(colour);
   histo->SetMarkerStyle(20);
	}
	if(hist_no == 1 ){//train s1
	  histo->SetLineColor(colour);
	  histo->SetFillColor(colour);
	  histo->SetFillStyle(3005);
	}
	if(hist_no == 2 ){// b1
	  histo->SetMarkerColor(colour);
	  histo->SetLineColor(colour);
   histo->SetMarkerStyle(20);
	}
	if(hist_no == 3 ){// train b1
	  histo->SetLineColor(colour);
	  histo->SetFillColor(colour);
	  histo->SetFillStyle(3004);

	}
	histo->SetTitle("");
	histo->SetXTitle("MVA Output");
	histo->SetYTitle("Events/Bin (Un-normalised)");
	histo->SetStats(false);
	histo->SetMaximum(plot_max*1.4);
}

void ClassifierOutputs::draw_title(std::string title)
{
	  TPaveText* pt = new TPaveText(0.15, 0.98, 0.9, 0.9, "blNDC");
	  std::string split_title = "#splitline{" + title.substr(0, 30) + "}{" + title.substr(26, -1) + "}";
			pt->SetBorderSize(0);
			pt->SetFillStyle(0);
			pt->AddText(split_title.c_str());
			pt->SetTextAlign(21);
			pt->SetAllWith(split_title.c_str(), "size", 0.04);
			pt->Draw("SAME");
}

double ClassifierOutputs::get_plot_max(std::vector<TH1D*> histos)
{
	 TH1F* th1f_histos[4];
  std::vector<TH1F*> th1f_vector (th1f_histos, th1f_histos + sizeof(th1f_histos) / sizeof(th1f_histos[0]));

	 for (int i = 0; i < histos.size(); i++)
	 {
	 		TH1F tmp;
	 		(*histos[i]).Copy(tmp);
    th1f_vector[i] = (TH1F*) (&tmp)->Clone();
	 }
	 TH1F* max_histo = HistoPlot::get_max_histo(th1f_vector);

	 return HistoPlot::get_histo_y_max(max_histo);
}

std::vector<int> ClassifierOutputs::get_npads(int nfiles)
{
  int npads[2]; // {nx, ny}
  npads[0] = 2;

	 if (nfiles % 2)
	 {
    npads[1] = (nfiles + 1) / 2;
  }
  else
  {
  		npads[1] = nfiles / 2;
  }
	 std::vector<int> npads_vector (npads, npads + sizeof(npads) / sizeof(npads[0]));

	 return npads_vector;
}
