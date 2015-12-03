#ifndef Data_Chain_h
#define Data_Chain_h

#include <TCanvas.h>
#include <TROOT.h>
#include <TFile.h>
#include <TApplication.h>
#include <TChain.h>
#include <TCut.h>
#include <TH2.h>
#include "tree_leaves.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>


class DataChain {
public:
  const char* label;
  const char* legend;
  TreeLeaves* leaves;
  TChain* chain;
  const char* control_selection;
  double mc_normaliser;

  DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend, const char* control_region_selection="");

  void get_data();
};

#endif
