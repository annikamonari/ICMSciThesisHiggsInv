#include "data_chain.h"

DataChain::DataChain(std::vector<char*> file_paths, char* data_label) {
  label = data_label;
  vars = new LeafVariables();
  chain = new TChain("LightTree");

    //vars->set_branch_addresses(chain);
    //get_data();

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

TH1F* DataChain::histo_for_stack(bool is_signal, char* variable_name, char* selection, float x_min, float x_max, int fill_colour) {
  const char* histo_id = build_string({variable_name, " >> ", label});

  set_histo_style(is_signal, fill_colour);
  chain->Draw(histo_id, selection); 

  TH1F* histo = (TH1F*)gDirectory->Get(label); // get histo from current directory
  //histo->GetXaxis()->SetRange(x_min, x_max);

  return histo;
}

void DataChain::set_histo_style(bool is_signal, int fill_colour) {
  if(is_signal) {
    chain->SetLineColor(2);
    chain->SetLineWidth(2);
    chain->SetFillColorAlpha(0, 0);
  }
  else {
    chain->SetLineColor(1);
    chain->SetFillColor(fill_colour);
  }

}

const char* build_string(std::vector<char*> pchars) {
  std::string str_from_pchars;

  for(int i = 0; i < pchars.size(); i++) {
    str_from_pchars.append(pchars[i]);
  }

  return str_from_pchars.c_str();
}

const char* build_title(std::vector<char*> words) {
  words[0][0] = toupper(words[0][0]);
  const char* title = build_string(words);
  return title;
}


