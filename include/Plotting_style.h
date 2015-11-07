#ifndef Plotting_Style_h
#define Plotting_Style_h

#include <TROOT.h>
#include <TStyle.h>

// Set style for 1D histogram
void Set1DHistoStyle(int lineColour = 1, int lineWidth = 1, int fillColour = 0);

void Set1DHistoStyle(int lineColour, int lineWidth, int fillColour) {
  gStyle->SetLineColor(lineColour);
  gStyle->SetLineWidth(lineWidth);
  gStyle->SetFillColor(fillColour);
  gROOT->ForceStyle();
}

#endif