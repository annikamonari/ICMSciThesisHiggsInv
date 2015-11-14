#include "data_chain.h"



DataChain::DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend) {
  label = data_label;
  legend = data_legend;
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

TH1F* DataChain::histo_for_stack(bool is_signal, const char* variable_name, const char* selection, const char* x_min, const char* x_max, int fill_colour) {
  //const char* histo_id = build_string({variable_name, ">>hnew"});

  std::string draw_histo(variable_name);
  draw_histo.append(">>");
  draw_histo.append(label);
  draw_histo.append("(100,");
  draw_histo.append(x_min);
  draw_histo.append(",");
  draw_histo.append(x_max);
  draw_histo.append(")");
  const char* histo_id = draw_histo.c_str();

  set_histo_style(is_signal, fill_colour);

  chain->Draw(histo_id, selection); 

  TH1F* histo = (TH1F*)gDirectory->Get(label); // get histo from current directory
  //histo->GetXaxis()->SetRange(x_min, x_max);
  if (histo) {
    std::cout << "histo generated fine" << std::endl;
  }
  else {
    std::cout << "error in histoplot" << std::endl;
  }
  return histo;
}

TH1F* DataChain::draw_data(const char* variable_name, const char* selection, const char* x_min, const char* x_max) {
  //const char* histo_id = build_string({variable_name, ">>", label});
  std::string draw_histo(variable_name);
  draw_histo.append(">>");
  draw_histo.append(label);
  draw_histo.append("(100,");
  draw_histo.append(x_min);
  draw_histo.append(",");
  draw_histo.append(x_max);
  draw_histo.append(")");
  const char* histo_id = draw_histo.c_str();

  chain->Draw(histo_id, selection, "E1"); 
  chain->SetMarkerStyle(20);
  chain->SetMarkerColor(1);
  gROOT->ForceStyle();

  TH1F* histo = (TH1F*)gDirectory->Get(label);

  if (histo) {
    std::cout << "histo generated fine" << std::endl;
  }
  else {
    std::cout << "error in adding data signal" << std::endl;
  }
  return histo;
}

void DataChain::set_histo_style(bool is_signal, int fill_colour) {
  if(is_signal) {
    chain->SetLineColor(2);
    chain->SetLineWidth(2);
    //chain->SetFillColorAlpha(0, 0);
  }
  else {
    chain->SetLineColor(1);
    chain->SetFillColor(fill_colour);
  }

}

const char* build_string(std::vector<const char*> pchars) {
  std::string str_from_pchars;

  for(int i = 0; i < pchars.size(); i++) {
    str_from_pchars.append(pchars[i]);
  }
  std::cout << "word parsed fine:" << str_from_pchars << std::endl;
  return str_from_pchars.c_str();
}


