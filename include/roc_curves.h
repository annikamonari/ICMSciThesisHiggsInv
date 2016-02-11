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
  static TH1D* plot_rejBvsS(TFile* training_output, std::string method_name);

  static void get_rocs(std::vector<TFile*> training_outputs, DataChain* signal,
																													DataChain* bg, SuperVars* super_vars, std::string method_name, std::string dir);

  static void plot_all_rejBvsS(std::vector<TFile*> training_outputs, DataChain* signal,
																																										DataChain* bg, std::string preselection, Variable* var, std::vector<Variable*>* variables,
																																										std::string method_name, std::string dir);

  static double get_presel_effy(DataChain* data_chain, std::string preselection, Variable* var,
																									       std::vector<Variable*>* variables);

  static TGraph* parked_data_point(DataChain* signal, DataChain* bg, std::string preselection, Variable* var,
  																										       std::vector<Variable*>* variables, TLegend* legend);
  static TH1F* histo(DataChain* data, Variable* variable, std::string preselection);

  static void style_legend(TLegend* legend);
};

#endif
