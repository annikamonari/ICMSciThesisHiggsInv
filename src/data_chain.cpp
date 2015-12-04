#include "../include/data_chain.h"

DataChain::DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend,
																					SuperVars* super_vars, const char* control_region_selection)
{
  label = data_label;
  legend = data_legend;
  chain = new TChain("LightTree");
  lepton_selection = control_region_selection;

  /*
  -- For getting individual entries in a TChain: --
  leaves = new TreeLeaves();
  leaves->set_branch_addresses(chain);
  get_data();
  */

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




