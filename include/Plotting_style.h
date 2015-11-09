#ifndef Plotting_Style_h
#define Plotting_Style_h

#include <TROOT.h>
#include <TStyle.h>
#include <TH2.h>

// Set style for 1D histogram

void Set1DHistoStyle(TH2D* histo1d, int lineColour = 1, int lineWidth = 1, int fillColour = 0) {
  histo1d->SetLineColor(lineColour);
  histo1d->SetLineWidth(lineWidth);
  histo1d->SetFillColor(fillColour);
  gROOT->ForceStyle();
}

#endif