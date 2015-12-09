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
#include <map>


class DataChain 
{
 public:
  const char* label;
  const char* legend;
  TreeLeaves* leaves;
  TChain* chain;
  std::string lep_sel;
  std::map<const char*, double> mc_weights;

  DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend, std::string lep_selection = "");

  void get_data();

  void set_mc_weights(std::map<const char*, double> weight_map);
};

#endif
