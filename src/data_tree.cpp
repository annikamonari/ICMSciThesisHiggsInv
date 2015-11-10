#include "data_tree.h"

DataTree::DataTree(TFile* data_file, char* tree_name) {
    file = data_file;
    label = tree_name;
    tree = (TTree*) file -> Get("LightTree");
    vars = new LeafVariables();

    //vars->set_branch_addresses(tree);
    //get_data();
}

void DataTree::get_data() {
    UInt_t nentries = tree->GetEntries();

    for(int i = 0; i < nentries; i++) {
      tree -> GetEntry(i);
  }
}

TH1F* DataTree::create_histo_for_stack(int fill_color, char* variable_name, char* selection) {
    tree->SetLineColor(1);
    tree->SetFillColor(fill_color);
    
    std::string draw_histo(variable_name);
    draw_histo.append(">>");
    draw_histo.append(label);

    // draw histogram and fill histo with it
    const char* draw_histo_str = draw_histo.c_str();

    if(selection == NULL) {
        tree->Draw(draw_histo_str);
    } 
    else {
        tree->Draw(draw_histo_str, selection);
    }
    // get histo from current directory
    TH1F* histo = (TH1F*)gDirectory->Get(label);
    return histo;
    
}


