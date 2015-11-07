#include "plotting_style.h"
#include "standard_headers.h"
#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>

class Plot {
  TTree* tree;
  Long64_t nentries;

  Plot(TTree* data) {
    tree = data;
    nentries = tree->GetEntries();
  }

  void plot_lumi_vs_events() {
    Double_t lumi;
    Double_t event;

    tree->SetBranchAddress("lumi", &lumi);
    tree->SetBranchAddress("event", &event);

    Set1DHistoStyle(4, 2);
    TH2D* histo2D = new TH2D("eventvslumi","Events vs Luminosity", 500,0,500, 1000,0,10000000);

    for(int i = 0; i < nentries; i++) {
      tree->GetEntry(i);
      histo2D->Fill(event, lumi);
    }

    TCanvas *c2 = new TCanvas("c2","event vs lumi plot");
    histo2D->Draw();
  }
};

int main(void) {
  TFile* f = new TFile("../docs/PARKED_VBF-Parked-2012B-22Jan2013-v1-1.root");
  TTree* t = (TTree*) f->Get("LightTree");
  Plot plot = new Plot(t);
};