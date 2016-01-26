#include "../include/data_chain.h"
#include <cmath>

DataChain::DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend, std::string lep_selection, TChain* tchain) {
  label = data_label;
  legend = data_legend;
  leaves = new TreeLeaves();
  lep_sel = lep_selection;
  mc_weights = std::map<const char*, double>();
  //leaves->set_branch_addresses(chain);
  //get_data();
  if (tchain != NULL)
  {
    chain = tchain;
  }
  else
  {
  		chain = new TChain("LightTree");

  		for(int i = 0; i < file_paths.size(); i++)
  		{
  		  chain->Add(file_paths[i]);
  		}
  }
}

void DataChain::get_data() {
  UInt_t nentries = chain->GetEntries();

  for(int i = 0; i < nentries; i++) {
    chain -> GetEntry(i);
  }
}

void DataChain::set_mc_weights(std::map<const char*, double> weight_map)
{
  mc_weights = weight_map;
}


