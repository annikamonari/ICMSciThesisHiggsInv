#include "data_chain.h"
#include <cmath>
#include <sstream>


DataChain::DataChain(std::vector<const char*> file_paths, const char* data_label, const char* data_legend) {
  label = data_label;
  legend = data_legend;
  vars = new LeafVariables();
  chain = new TChain("LightTree");

    //vars->set_branch_addresses(chain);
    //get_data();

  for(int i = 0; i < file_paths.size(); i++) {
    chain->Add(file_paths[i]);
  }
}

void DataChain::get_data() {
  UInt_t nentries = chain->GetEntries();

  for(int i = 0; i < nentries; i++) {
    chain -> GetEntry(i);
  }
}

TH1F* DataChain::histo_for_stack(bool is_signal, const char* variable_name, const char* selection, const char* bins, const char* x_min, const char* x_max, int fill_colour, bool is_cut,const char* x_minc_nocut, const char* x_maxc_nocut) {
const char *scaled_bins= scale_bins_for_cut(bins, x_minc_nocut, x_maxc_nocut, x_min, x_max);
char buffer;//= (char*) malloc(128*sizeof(char));
buffer= *scaled_bins;

  std::string draw_histo(variable_name);
  draw_histo.append(">>");
  draw_histo.append(label);
  draw_histo.append("(");
  draw_histo+=buffer;
  //std::cout << "buffer =  " << buffer << "\n";
  draw_histo.append(",");
  draw_histo.append(x_min);
  draw_histo.append(",");
  draw_histo.append(x_max);
  draw_histo.append(")");
  const char* histo_id = draw_histo.c_str();
// std::cout << "histo_id "<< histo_id <<"+"<< *histo_id<<"\n";

  set_histo_style(is_signal, fill_colour);


  //double x_minn = atof(x_min);
  //double x_maxx = atof(x_max);

  chain->Draw(histo_id, selection, "goff"); 
  TH1F* histo = (TH1F*)gDirectory->Get(label); // get histo from current directory
 
 //histo->GetXaxis()->SetRange(x_min, x_max);
  if (histo) {
    //std::cout << "histo generated fine" << std::endl;
  }
  else {
    std::cout << "error in histoplot" << std::endl;
  }
  return histo;
}

TH1F* DataChain::draw_data(const char* variable_name, const char* selection, const char* bins, const char* x_min, const char* x_max, const char* x_minc_nocut, const char* x_maxc_nocut) {
  const char* scaled_bins= scale_bins_for_cut(bins, x_minc_nocut, x_maxc_nocut, x_min, x_max);
	
  std::string draw_histo(variable_name);
  draw_histo.append(">>");
  draw_histo.append(label);
  draw_histo.append("(");
  std::string bins_str = std::string(scaled_bins);
  draw_histo.append(bins_str);
  draw_histo.append(",");
  draw_histo.append(x_min);
  draw_histo.append(",");
  draw_histo.append(x_max);
  draw_histo.append(")");

  const char* histo_id = draw_histo.c_str();
  std::cout << "histo_id =" << histo_id;
  chain->Draw(histo_id, selection, "E1"); 
  std::cout << "i have done Draw data"<<"\n";
  chain->SetMarkerStyle(7);
  chain->SetMarkerColor(1);
  chain->SetLineColor(1);
  gROOT->ForceStyle();
  TH1F* histo = (TH1F*)gDirectory->Get(label);
  set_error_bars(histo);

  if (histo) {
    std::cout << "histo generated fine" << std::endl;
  }
  else {
    std::cout << "error in adding data signal" << std::endl;
  }

  return histo;
}

void DataChain::set_histo_style(bool is_signal, int fill_colour) {
  if(is_signal) {
    chain->SetLineColor(2);
    chain->SetLineWidth(3);
    //chain->SetFillColorAlpha(0, 0);
  } 
  else {
    chain->SetLineColor(1);
    chain->SetFillColor(fill_colour);
  }

}

const char* DataChain::scale_bins_for_cut(const char* bins, const char* x_minc_nocut, const char* x_maxc_nocut, const char* x_minc_cut, const char* x_maxc_cut) {
  //std::cout << "raw bins in scale bin funct=" << bins << "\n";
  double x_min_nocut = atof(x_minc_nocut);
  double x_max_nocut = atof(x_maxc_nocut);
  double x_min_cut = atof(x_minc_cut);
  double x_max_cut = atof(x_maxc_cut);
  double fraction = (x_max_cut - x_min_cut)/(x_max_nocut - x_min_nocut);
  double bins1 = atof(bins);
  double nbins = (bins1) * fraction;
  nbins = nbins + 0.5;
  int nbins_int = (int) nbins;
  if (nbins_int==0){
	nbins_int=1;
  }

std::string sbs;
std::ostringstream oss;
oss << nbins_int;
sbs =oss.str();
const char* scbin_ptr = sbs.c_str();
//std::cout << "scaled bins=" << scbin_ptr << "\n";
return scbin_ptr;//scaled_bins;
}


TH1F* DataChain::set_error_bars(TH1F* hist) {
  int nbins = hist->GetNbinsX();
  
  for(int i = 0; i < nbins; i++) {
    double error_val = get_data_error(hist, i);
    hist->SetBinError(i, error_val);
  }
  return hist;
}

double DataChain::get_data_error(TH1F* hist, int bin) {
  double integral = hist->Integral(bin, bin + 1);
  return std::pow(integral, 0.5);
}

const char* DataChain::build_var_string(const char* variable_name, const char* x_min, const char* x_max) {
  std::string var_string(variable_name);
  var_string += ">>";
  var_string.append(label);
  var_string += "(";
  
  return var_string.c_str();
}


