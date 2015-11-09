#include "data_tree.h"
#include "plotting_style.h"

class Histo1D {

};

class Plot {
  TTree* tree;
  Long64_t nentries;

public:
  Plot(TTree* data) {
    tree = data;
    nentries = tree->GetEntries();
  }

  void plot_lumi() {
    UInt_t lumi;
    UInt_t event;

    tree->SetBranchAddress("lumi", &lumi);
    tree->SetBranchAddress("event", &event);

    TH2D* histo2D = new TH2D("lumi vs event","Luminosity vs Events", 180,0,1800, 1000,0,1000000000);

    for(int i = 0; i < nentries; i++) {
      tree->GetEntry(i);
      histo2D->Fill(lumi, event);
    }

    TCanvas *c2 = new TCanvas("c2","lumi plot");
    Set1DHistoStyle(histo2D, 2, 3, 2);
    histo2D->Draw();
    c2->Update();
  }
};

int main(int argc, char** argv) {
  TApplication theApp("tapp", &argc, argv);
  TFile* f = new TFile("docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-0.root");
  TTree* t = (TTree*) f->Get("LightTree");
  Plot* plot = new Plot(t);
  
  plot->plot_lumi();
  theApp.Run();
  
  return 0;
};