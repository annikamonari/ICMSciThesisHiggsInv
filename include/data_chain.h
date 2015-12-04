#ifndef Data_Chain_h
#define Data_Chain_h

#include "../include/tree_leaves.h"
#include <TCanvas.h>
#include <TROOT.h>
#include <TFile.h>
#include <TApplication.h>
#include <TChain.h>
#include <TCut.h>
#include <TH2.h>
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
  TChain* chain;
  const char* lepton_selection; // lepton_sel syntax must have an open ( at the front
  // TreeLeaves* leaves;

  DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend,
												const char* control_region_selection="");

  void get_data();
};

#endif
