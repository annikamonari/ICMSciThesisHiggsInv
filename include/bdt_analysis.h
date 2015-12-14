#ifndef Bdt_Analysis_h
#define Bdt_Analysis_h

#include "../include/histo_plot.h"
#include "../include/mc_weights.h"

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

class BDTAnalysis
{
 public:
	 static void create_BDT(DataChain* bg_chain, DataChain* signal_chain, std::vector<Variable*>* variables);
};








#endif
