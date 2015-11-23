#include "../include/data_chain.h"
#include <cmath>

DataChain::DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend) {
  label = data_label;
  legend = data_legend;
  leaves = new TreeLeaves();
  chain = new TChain("LightTree");

  leaves->set_branch_addresses(chain);
  get_data();

  for(int i = 0; i < file_paths.size(); i++) {
    chain->Add(file_paths[i]);
  }
}

void DataChain::get_data() {
  UInt_t nentries = chain->GetEntries();

  for(int i = 0; i < nentries; i++) {
    chain -> GetEntry(i);
  }
}


