#ifndef Plotting_Style_h
#define Plotting_Style_h

#include <TROOT.h>
#include <TStyle.h>

// Set style for 1D histogram
void Set1DHistoStyle();

// Set style for 1 part of stacked histogram, supply fill colour
void SetStackedHistStyle(int fillColour);

void Set1DHistoStyle() {
  gStyle->SetLineColor(4);
  gStyle->SetLineWidth(2);
  gROOT->ForceStyle();
}

void Set1DStackedHistStyle(int fillColour) {
  gStyle->SetLineColor(1);
  gStyle->SetFillColor(fillColour);
  gStyle->SetLineWidth(2);
  gROOT->ForceStyle();
}

#endif