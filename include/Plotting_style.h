#ifndef Plotting_Style_h
#define Plotting_Style_h

#include <TStyle.h>
#include "TROOT.h"
#include <stdio.h>

// Set style for 1D histogram
void Set1DHistoStyle();

// Set style for 1 part of stacked histogram, supply fill colour
void SetStackedHistStyle(int fillColour);

void Set1DHistoStyle() {
  gROOT->SetLineColor(4);
  gROOT->SetLineWidth(2);
  gROOT->ForceStyle();
}

void Set1DStackedHistStyle(int fillColour) {
  gROOT->SetLineColor(1);
  gROOT->SetFillColor(fillColour);
  gROOT->SetLineWidth(2);
  gROOT->ForceStyle();
}

#endif