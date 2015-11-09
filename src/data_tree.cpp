#include "data_tree.h"

class DataTree {
public:
  TFile* file;
  char* label;
  TTree* tree;
  LeafVariables* vars;

  void get_data() {
    UInt_t nentries = tree->GetEntries();

    for(int i = 0; i < nentries; i++) {
      tree -> GetEntry(i);
    }
  }

  DataTree(TFile* data_file, char* tree_name) {
    file = data_file;
    label = tree_name;
    tree = (TTree*) file -> Get("LightTree");
    vars = new LeafVariables();

    vars->set_branch_addresses(tree);
    get_data();
  }

  void create_histo_for_stack(int fill_color, char* variable_name) {

  }


  // pass in &var_name e.g. &n_vertices - TODO: make same method for UInt_t
  void create_1d_plot(Double_t* var_name, int bins, int x_min, int x_max) {
    TH1D* histo1 = new TH1D(label, label, bins, x_min, x_max);
  }



};
