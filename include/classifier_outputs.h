#ifndef Classifier_Outputs_h
#define Classifier_Outputs_h

#include "data_card.h"

class ClassifierOutputs
{
 public:
  static std::vector<TH1D*> get_classifier_histos(TFile* classifier_output, std::string method_name);

  static TH1D* get_histo_from_output(TFile* file, std::string histo_path);

  static std::vector<TH1D*> normalise_histos(std::vector<TH1D*> histos);

  static void plot_histos(std::vector<TH1D*> histos, TFile* file);

  static void draw_ktest(std::vector<TH1D*> normalised_histos);

  static void draw_classifier_outputs(TFile* file, std::string method_name);

  static void style_histo(TH1D* histo, int colour, int hist_no, std::string tfile_name, double plot_max);

  static std::vector<int> get_npads(int nfiles);

  static void plot_classifiers_for_all_files(std::vector<TFile*> files, std::string method_name, std::string dir);

  static double get_plot_max(std::vector<TH1D*> histos);

  static void draw_title(std::string title);
};








#endif
