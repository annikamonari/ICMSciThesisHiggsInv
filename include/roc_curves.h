#ifndef Roc_Curves_h
#define Roc_Curves_h

#include "../include/bdt_analysis.h"

#include "TH2F.h"
#include "TFile.h"
#include "TIterator.h"
#include "TKey.h"
#include "TGraph.h"

class RocCurves
{
 public:
  static TH1D* plot_rejBvsS(TFile* training_output);

  static void get_rocs(std::vector<TFile*> training_outputs, DataChain* signal,
																													DataChain* bg, SuperVars* super_vars);

  static void plot_all_rejBvsS(std::vector<TFile*> training_outputs, std::string bg_name, DataChain* signal,
																																										DataChain* bg, std::string preselection, Variable* var, std::vector<Variable*>* variables);

  static double get_presel_effy(DataChain* data_chain, std::string preselection, Variable* var,
																									       std::vector<Variable*>* variables);

  static TGraph* parked_data_point(DataChain* signal, DataChain* bg, std::string preselection, Variable* var,
  																										       std::vector<Variable*>* variables);
  static TH1F* histo(DataChain* data, Variable* variable, std::string preselection);

  static TH1F* histo2(DataChain* data, Variable* variable, std::string preselection);
};

#endif