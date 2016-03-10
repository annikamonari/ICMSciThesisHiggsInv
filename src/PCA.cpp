#include <initializer_list>
#include <cmath>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TPrincipal.h"

#include "../include/mva_analysis.h"
#include "../include/PCA.h"

using namespace std;
void PCA::principal(Int_t n, Int_t m, DataChain* d_chain)
{
//________________________________________________________________________________________________
  TChain* data_chain = d_chain->chain; 
  TObjArray* branches_list  = data_chain->GetListOfBranches();
  Int_t nBranches = branches_list->GetEntries();
  cout<<"number of events"<<data_chain->GetEntriesFast()<<"\n";

  Double_t val;
  TBranch* branch;
  TLeaf* leaf;

  //n = nBranches;

  //
  // Principal Components Analysis (PCA) example
  //
  // Example of using TPrincipal as a stand alone class.
  //
  // We create n-dimensional data points, where c = trunc(n / 5) + 1
  // are  correlated with the rest n - c randomly distributed variables.
  //
  // End_Html
  //Authors: Rene Brun, Christian Holm Christensen

  
  cout << "*************************************************" << endl;
  cout << "*         Principal Component Analysis          *" << endl;
  cout << "*                                               *" << endl;
  cout << "*  Number of variables:           " << n
       << "          *" << endl;
  cout << "*  Number of data points:         " << m
       << "      *" << endl;
  cout << "*                                               *" << endl;
  cout << "*************************************************" << endl;


  // Initilase the TPrincipal object. Use the empty string for the
  // final argument, if you don't wan't the covariance
  // matrix. Normalising the covariance matrix is a good idea if your
  // variables have different orders of magnitude.
  TPrincipal* principal = new TPrincipal(n,"ND");

  // Use a pseudo-random number generator
  TRandom* random = new TRandom;

  // Make the m data-points
  // Make a variable to hold our data
  // Allocate memory for the data point
  Double_t* data = new Double_t[nBranches];
//________________________________________________________________________________________________
//

  for (Int_t i = 0; i < m; i++) {

    for (Int_t j = 0; j < nBranches-50 ; j++) {
      const char* branch_name = branches_list->At(j+10)->GetName();

      branch = data_chain->GetBranch(branch_name);
      //leaf = branch->GetLeaf(branch_name);
      branch->GetEntry(i);
      //val=leaf->GetValue();
      //val = branch->GetLeaf(branch_name)->GetValue(i); 
      cout<<"value at entry: "<<i<<", variable number: "<<j<<" = "<<val<<"\n";
      data[j] = val;//return value of variable j in event i

    }

    // Finally we're ready to add this datapoint to the PCA
    principal->AddRow(data);
  }

  // We delete the data after use, since TPrincipal got it by now.
  delete [] data;

  // Do the actual analysis
  principal->MakePrincipals();

  // Print out the result on
  principal->Print();

  // Test the PCA
  principal->Test();

  // Make some histograms of the orginal, principal, residue, etc data
  principal->MakeHistograms();

  // Make two functions to map between feature and pattern space
  principal->MakeCode();

  // Start a browser, so that we may browse the histograms generated
  // above
  //TBrowser* b = new TBrowser("principalBrowser", principal);

}

