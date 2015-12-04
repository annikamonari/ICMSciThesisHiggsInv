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
#include <map>

class SuperVars;

class DataChain {
public:
  const char* label;
  const char* legend;
  TreeLeaves* leaves;
  TChain* chain;
  //lepton_sel syntax must have an open ( at the front
  const char* lepton_selection;
  std::map<char*, double> mc_weights;

  DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend,
												SuperVars* super_vars, const char* control_region_selection="");

  void get_data();
};

#endif
