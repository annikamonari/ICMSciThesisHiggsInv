
#include <iostream>

#include <TPrincipal.h>

using namespace std;
void principal(Int_t n=10, Int_t m=10000)
{
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

  Int_t c = n / 5 + 1;

  cout << "*************************************************" << endl;
  cout << "*         Principal Component Analysis          *" << endl;
  cout << "*                                               *" << endl;
  cout << "*  Number of variables:           " << n
       << "          *" << endl;
  cout << "*  Number of data points:         " << m
       << "      *" << endl;
  cout << "*  Number of dependent variables: " << c
       << "          *" << endl;
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
  Double_t* data = new Double_t[n];
//________________________________________________________________________________________________
  TChain* data_chain = bg_chain->chain; 
/*
  data_chain->SetBranchAddress("dijet_deta", &dijet_deta);
  data_chain->SetBranchAddress("forward_tag_eta", &forward_tag_eta);
  data_chain->SetBranchAddress("metnomu_significance", &metnomu_significance);
  data_chain->SetBranchAddress("sqrt_ht", &sqrt_ht);
  data_chain->SetBranchAddress("alljetsmetnomu_mindphi", &alljetsmetnomu_mindphi);
  data_chain->SetBranchAddress("dijet_M", &dijet_M);
  data_chain->SetBranchAddress("metnomuons", &metnomuons);
  data_chain->SetBranchAddress("jet1_pt", &jet1_pt);
  data_chain->SetBranchAddress("jet2_pt", &jet2_pt);
  data_chain->SetBranchAddress("jet1_E", &jet1_E);
  data_chain->SetBranchAddress("jet2_E", &jet2_E);
  data_chain->SetBranchAddress("jet1_eta", &jet1_eta);
  data_chain->SetBranchAddress("jet2_eta", &jet2_eta);
  data_chain->SetBranchAddress("jet1_phi", &jet1_phi);
  data_chain->SetBranchAddress("jet2_phi", &jet2_phi);
  data_chain->SetBranchAddress("jet_csv1", &jet_csv1);
  data_chain->SetBranchAddress("jet_csv2", &jet_csv2);
  data_chain->SetBranchAddress("dijet_dphi", &dijet_dphi);
  data_chain->SetBranchAddress("metnomu_x", &metnomu_x);
  data_chain->SetBranchAddress("metnomu_y", &metnomu_y);
  data_chain->SetBranchAddress("sumet", &sumet);
  data_chain->SetBranchAddress("mht", &mht);
  data_chain->SetBranchAddress("unclustered_et", &unclustered_et);
  data_chain->SetBranchAddress("jetmet_mindphi", &jetmet_mindphi);
  data_chain->SetBranchAddress("jetmetnomu_mindphi", &jetmetnomu_mindphi);
  data_chain->SetBranchAddress("jetunclet_mindphi", &jetunclet_mindphi);
  data_chain->SetBranchAddress("metnomuunclet_dphi", &metnomuunclet_dphi);
  data_chain->SetBranchAddress("dijetmetnomu_vectorialSum_pt", &dijetmetnomu_vectorialSum_pt);
  data_chain->SetBranchAddress("dijetmetnomu_ptfraction", &dijetmetnomu_ptfraction);
  data_chain->SetBranchAddress("jet1metnomu_scalarprod", &jet1metnomu_scalarprod);
  data_chain->SetBranchAddress("jet2metnomu_scalarprod", &jet2metnomu_scalarprod);
  data_chain->SetBranchAddress("n_jets_cjv_30", &n_jets_cjv_30);
  data_chain->SetBranchAddress("n_jets_cjv_20EB_30EE", &n_jets_cjv_20EB_30EE);
  data_chain->SetBranchAddress("n_jets_15", &n_jets_15);
  data_chain->SetBranchAddress("n_jets_30", &n_jets_30);
  data_chain->SetBranchAddress("cjvjetpt", &cjvjetpt);
  data_chain->SetBranchAddress("l1met", &l1met);
  data_chain->SetBranchAddress("n_vertices", &n_vertices);
*/
//________________________________________________________________________________________________


TObjArray* leaves  = data_chain->GetListOfLeaves();
Int_t nleaves = leaves->GetEntriesFast();
TLeaf* leaf;
Int_t ret;
  for (Int_t i = 0; i < m; i++) {
    ret = LoadTree(m);
    if (ret == -2) 
    {
      Error("Show()", "Cannot read entry %lld (entry does not exist)", entry);
      return;
    } else if (ret == -1) 
    {
      Error("Show()", "Cannot read entry %lld (I/O error)", entry);
      return;
    }
    ret = GetEntry(entry);
    if (ret == -1) {
      Error("Show()", "Cannot read entry %lld (I/O error)", entry);
      return;
     } else if (ret == 0) {
      Error("Show()", "Cannot read entry %lld (no data read)", entry);
      return;
     }
    // First we create the un-correlated, random variables, according
    // to one of three distributions
    for (Int_t j = 0; j < n ; j++) {
      leaf = (TLeaf*) leaves->UncheckedAt(j);
      data[j] = leaf->GetValue(i);//return value of variable j in event i  
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
  TBrowser* b = new TBrowser("principalBrowser", principal);

}

