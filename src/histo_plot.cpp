#include "../include/histo_plot.h"
#include <algorithm>

void HistoPlot::draw_plot(Variable* var, std::vector<DataChain*> bg_chains,
                          DataChain* signal_chain, DataChain* data, bool with_cut,
                          std::vector<Variable*>* variables, bool plot_data, bool is_control_region,
 			  std::string file_name, std::string mc_selection,std::string mva_cut_str)
{
//std::cout<<"mva selection:"<<mva_cut_str<<"."<<"\n";

//step 1 declare canvas, pads and legends
/////////////////////////////////////////
  TCanvas* c1     = new TCanvas("c1", var->name_styled, 800, 800);
  TPad* p1        = new TPad("p1", "p1", 0.0, 0.95, 1.0, 1.0);
  TPad* p2        = new TPad("p2", "p2", 0.0, 0.2, 1.0, 0.95);
  TPad* p3        = new TPad("p3", "p3", 0.0, 0.0, 1.0, 0.2);
  TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);

//step 2 set size of margins and draw pads
/////////////////////////////////////////

  p1->SetLeftMargin(0.102);
  p2->SetBottomMargin(0.012);
  p2->SetLeftMargin(0.105);
  p3->SetBottomMargin(0.3);
  p3->SetLeftMargin(0.102);

  p1->Draw();
  p2->Draw();
  p3->Draw();
  p2->cd();

//step 3 create mc weights vector
/////////////////////////////////////////
std::cout<<"creating mc weights vector"<<"\n";
 
  double arr[bg_chains.size()];

if (is_control_region){
  std::fill_n(arr, bg_chains.size(), 1);
  std::cout<<"we better not be in the control region loop- oh dear we are...\n";
}

  std::vector<double> mc_weights_vector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

   mc_weights_vector = mc_weights(data, bg_chains, var, with_cut, variables, mva_cut_str);

for (int i=0;i<bg_chains.size();i++)
{
std::cout<<"mc_weights no: "<<i<<"= "<<mc_weights_vector[i]<<"\n";
}


//step 4 plot signal, data and background histos
/////////////////////////////////////////

  THStack stack      = draw_stacked_histo(legend, var, bg_chains, with_cut,mc_weights_vector, variables, data, mc_selection, mva_cut_str);
  TH1F* signal_histo = draw_signal(signal_chain, var, with_cut, legend, variables,mc_selection, mva_cut_str);

std::cout<<"signal done"<<"\n";
  TH1F* data_histo;   
  if(plot_data){ data_histo   = draw_data(data, var, with_cut, legend, variables,mc_selection, mva_cut_str);}

  if(!plot_data){data_histo = NULL;}
std::cout<<"data drawn"<<"\n";

//step 5 draw signal, background and data histograms on canvas
/////////////////////////////////////////

  stack.Draw();
  signal_histo->Draw("SAME");
  if(plot_data){data_histo->Draw("SAME");}
std::cout<<"data done"<<"\n";

  style_stacked_histo(&stack, var->name_styled);
std::cout<<"style done"<<"\n";

//step 6 find maximum histogram height and set legend position away from maximum-checked and draw subtitles
/////////////////////////////////////////
/*TH1F* plot_histos_no_data[2] = {(TH1F*)(stack.GetStack()->Last()), signal_histo};
TH1F* plot_histos_with_data[3] = {(TH1F*)(stack.GetStack()->Last()), signal_histo, data_histo};
TH1F* max_histo;
if (plot_data)
{
  std::vector<TH1F*> plot_histos_vector (plot_histos_with_data, plot_histos_with_data + sizeof(plot_histos_with_data) / sizeof(  plot_histos_with_data[0]));
  max_histo      = HistoPlot::get_max_histo(plot_histos_vector);
}
else 
{
  std::vector<TH1F*> plot_histos_vector (plot_histos_no_data, plot_histos_no_data + sizeof(plot_histos_no_data) / sizeof(plot_histos_no_data[0]));
  max_histo      = HistoPlot::get_max_histo(plot_histos_vector);
}
std::cout<<"got max histo"<<"\n";
//std::cout<<"set max histo:"<<get_histo_y_max(max_histo)<<"\n";

//  stack.SetMaximum(get_histo_y_max(max_histo)*1.15);

  build_legend(legend, max_histo, var, with_cut);
std::cout<<"about to call subtitles"<<"\n";
  draw_subtitle(var, variables, with_cut, data,mva_cut_str);
*/
//step 7 draw ratio of signal/background or signal/data histogram -testing...
/////////////////////////////////////////
std::cout<<"about o call ratio histo func"<<"\n";

  p3->cd();
  TH1F* data_bg_ratio_histo;
  if (plot_data)
  {
    data_bg_ratio_histo = data_to_bg_ratio_histo(data_histo, (TH1F*)(stack.GetStack()->Last())/*plot_histos_with_data[0]*/);// plot signal to bg
  }
  else
  {
    data_bg_ratio_histo = data_to_bg_ratio_histo(signal_histo, (TH1F*)(stack.GetStack()->Last())/*plot_histos_no_data[0]*/);
  }
std::cout<<"about to draw ratio histo \n";
  data_bg_ratio_histo->Draw("e1");
  style_ratio_histo(data_bg_ratio_histo, var->name_styled,plot_data);
  draw_yline_on_plot(var, with_cut, 1.0);

//step 8 draw title, create file name and save and close image
/////////////////////////////////////////
p1->cd();
HistoPlot::draw_title(var->name_styled);

  std::string img_name;
  if (file_name == "")
  {
  		img_name = build_file_name(var, with_cut);
  }
  else
  {
  		img_name = file_name;
  }
  p1->cd();
  c1->SaveAs(img_name.c_str());
  c1->Close();

}

/////////////////////end////////////////////
///////////////////////////////////////////
///////////////////////////////////////////


std::string HistoPlot::get_mva_name(std::string img_name, std::string var_name, std::string mva_cut_str)
{
  var_name.append(mva_cut_str);
  img_name.insert(img_name.find(".png"), var_name);
  return img_name;
}

void HistoPlot::draw_yline_on_plot(Variable* var, bool with_cut, double y)
{
  double x_min = 0.0;
  double x_max = 1.0;

  if (with_cut)
  {
    x_min = atof(var->x_min_cut);
    x_max = atof(var->x_max_cut);
  }
  else
  {
    x_min = atof(var->x_min_nocut);
    x_max = atof(var->x_max_nocut);
  }

  TLine *line = new TLine(x_min, y, x_max, y);
  line->SetLineColor(13);
  line->SetLineStyle(2);
  line->Draw("SAME");
}

void HistoPlot::draw_title(const char* title)
{
  TPaveText* pt = new TPaveText(0.1, 0.1, 0.9, 1.0, "blNDC");
  pt->SetBorderSize(0);
  pt->SetFillColor(0);
  pt->AddText(title);
  pt->SetAllWith(title, "size", 0.8);
  pt->Draw();
}

std::string HistoPlot::get_selection(Variable* variable, std::vector<Variable*>* variables,
                                     bool with_cut, bool is_signal, DataChain* bg_chain, double mc_weight, std::string mva_cut_str)
{
  std::string selection;

  if ((variables != NULL) && (with_cut))
  {
    selection = variable->build_multicut_selection(is_signal, variables);
  }
  else
  {
    selection = variable->build_selection_string(with_cut, is_signal);
  }

  selection.insert(selection.find("(") + 1, lep_sel_default());
  std::string selection_with_mc;
 
  selection_with_mc = add_mc_to_selection(bg_chain, variable, selection, mc_weight);
  std::string selection_with_mva;
  selection_with_mva = add_mva_cut_to_selection(selection_with_mc, mva_cut_str);

  return selection_with_mva;
}

std::string HistoPlot::add_mc_to_selection(DataChain* bg_chain, Variable* variable, std::string selection, double mc_weight)
{
  std::string mc_weight_str = get_string_from_double(mc_weight);
  std::string sel_new = selection += "*" + mc_weight_str; //selection.insert(selection.find("*") + 1, mc_weight_str + "*");
  //std::cout << sel_new << std::endl;
  return sel_new;
}

std::string HistoPlot::add_mva_cut_to_selection(std::string selection, std::string mva_cut_str)
{
  if(mva_cut_str!=""){
    std::string mva_cut = "(";
    mva_cut.append(mva_cut_str);
    mva_cut.append(")&&");
    //std::cout<<"mva cut in add_mva_cut_to_selection: "<<mva_cut<<"\n";
    selection.insert(selection.find("(") + 1, mva_cut);
  }
  return selection;
}
std::vector<double> HistoPlot::mc_weights(DataChain* data, std::vector<DataChain*> bg_chains,
                                          Variable* var, bool with_cut, std::vector<Variable*>* variables,std::string mva_cut_str)
{
  double mc_weight[bg_chains.size()];
  double zll_weight;

  for(int i=0; i<bg_chains.size();i++)
  {
    mc_weight[i] = 1;

    if (bg_chains[i]->lep_sel != "")
    {

      mc_weight[i] = MCWeights::calc_mc_weight(data, bg_chains, bg_chains[i], (*variables)[0], with_cut, 
variables, mva_cut_str);
	     if(!strcmp(bg_chains[i]->label, "bg_zll"))
	     {
	     		zll_weight = mc_weight[i];
	     }
    }

    if (!strcmp(bg_chains[i]->label, "bg_zjets_vv"))
    {
    	 mc_weight[i] = zll_weight* 5.651 * 1.513;
    }
    //std::cout<<i<<": "<<mc_weight[i]<<"\n";
  }
  std::vector<double> mc_weights_vector (mc_weight, mc_weight + sizeof(mc_weight) / sizeof(mc_weight[0]));

  return mc_weights_vector;
}

// new function written ust like the one above: HistoPlot::mc_weights, which calculates the right error for the bgs without a control
// region (its just sqrt(unweighted mc events in signal) / unweighted mc events in signal)
std::vector<double> HistoPlot::get_mc_weight_errors(DataChain* data, std::vector<DataChain*> bg_chains, Variable* var, bool with_cut,
																																																				std::vector<Variable*>* variables, std::vector<double> bg_mc_weights, std::string mva_cut_str)

{
std::string mc_selection;
  double mc_weight_errors[bg_chains.size()];
	 double zll_weight_error;
//if (var->name_styled = "MVA Output"){std::cout<<"created var \n";}

	 for(int i = 0; i < bg_chains.size();i++)
	 {
 		mc_selection= MCWeights::get_mc_selection_str(bg_chains[i], var, variables, mva_cut_str);
		//if (var->name_styled = "MVA Output"){std::cout<<"got mc selection str\n";}

	   TH1F* histo = build_1d_histo(bg_chains[i], var,with_cut, false, "goff", variables, mc_selection, mva_cut_str);
		//if (var->name_styled = "MVA Output"){std::cout<<"got histo\n";}

	   double integral = get_histo_integral(histo, with_cut, var);
//if (var->name_styled = "MVA Output"){std::cout<<"got integral\n";}

	 		mc_weight_errors[i] = std::pow(integral, 0.5);
//if (var->name_styled = "MVA Output"){std::cout<<"prelim mc weight errors\n";}

	   if (bg_chains[i]->lep_sel != "")
	   {
	     mc_weight_errors[i] = single_bg_error(data, bg_chains, bg_chains[i], var, with_cut, variables, bg_mc_weights[i], mc_selection, mva_cut_str);

//if (var->name_styled = "MVA Output"){std::cout<<"got single bg errors\n";}
		    if(!strcmp(bg_chains[i]->label, "bg_zll"))
		    {
		     	zll_weight_error = mc_weight_errors[i];
		    }
	   }

	   if (!strcmp(bg_chains[i]->label, "bg_zjets_vv"))
	   {
	     mc_weight_errors[i] = zll_weight_error * 5.651 * 1.513;
	   }
	//if (var->name_styled = "MVA Output"){std::cout<<"created mc_weight error for :"<<bg_chains[i]->label<<"\n";}

	 }
	 std::vector<double> mc_weights_vector (mc_weight_errors, mc_weight_errors + sizeof(mc_weight_errors) / sizeof(mc_weight_errors[0]));
//if (var->name_styled = "MVA Output"){std::cout<<"created mc_weight error vector \n";}


	 return mc_weights_vector;
}

// problem: TH1F* bg doesn't plot with the mc weight? in the function above this, whenever we call this we pass through
// the mc weight (see last arg: double weight), so if you realise we need it then just put it onto the end of the build_1d_histo call
double HistoPlot::single_bg_error(DataChain* data, std::vector<DataChain*> bg_chains, DataChain* bg_chain,
                                 Variable* var, bool with_cut, std::vector<Variable*>* variables, double weight, std::string mc_selection, std::string mva_cut_str)
{
//if (var->name_styled = "MVA Output"){std::cout<<"in single bg error\n";}

  TH1F* bg = build_1d_histo(bg_chain, var, with_cut, false, "goff", variables, mc_selection, mva_cut_str);
//if (var->name_styled = "MVA Output"){std::cout<<"got histo\n";}

  double MC_N_S = get_histo_integral(bg, with_cut, var);
//if (var->name_styled = "MVA Output"){std::cout<<"got histo integral\n";}

  double sigma_N = std::pow(MC_N_S, 0.5);
  double sigma_w = MCWeights::calc_weight_error(data, bg_chains, bg_chain, var, with_cut, variables, mva_cut_str);

//if (var->name_styled = "MVA Output"){std::cout<<"got mc weight error\n";}

  double sigma_total_sq = std::pow(sigma_w*MC_N_S,2)+std::pow(sigma_N*weight,2);
  double sigma_total = std::pow(sigma_total_sq,0.5);
  //std::cout << bg_chain->label << " - single bg error: " << sigma_total << std::endl;
  return sigma_total;
}

std::string HistoPlot::get_string_from_double(double num)
{
  std::ostringstream num_ss;
  num_ss << num;
  std::string num_str(num_ss.str());

  return num_str;
}

double HistoPlot::sig_to_bg_ratio(Variable* var, TH1F* bg,
                                  TH1F* signal_histo, bool with_cut)
{
  double bg_integral  = get_histo_integral(bg, with_cut, var);
  double sig_integral = get_histo_integral(signal_histo, with_cut, var);
  float signal_mult   = atof(var->signal_multiplier);
  float sig_to_bg     = sig_integral / bg_integral / signal_mult;

  return sig_to_bg;
}

double HistoPlot::get_histo_integral(TH1F* histo, bool with_cut, Variable* var)
{
//std::cout<<var->name_styled<<"\n";
  int nbins;
  if (with_cut)
  {
    nbins = (int) (atof(var->bins_cut.c_str()) + 0.5);
//if (var->name_styled = "MVA Output"){std::cout<<"got nbins\n";}
  }
  else
  {
    nbins = (int) (atof(var->bins_nocut) + 0.5);
  }
  double integral = histo->Integral(0, nbins + 1);
//std::cout<<"got integral\n";
  return integral;
}

std::string HistoPlot::replace_all(std::string str, const std::string& from, const std::string& to)
{

  size_t start_pos = 0;

  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }
  return str;
}

std::string HistoPlot::style_selection(std::string selection)
{

  std::string sele = replace_all(replace_all(replace_all(replace_all(selection, ")", ""), ">", " > "), "==", " = "), "&&", ", ");

  return replace_all(replace_all(replace_all(replace_all(replace_all(sele, "_", " "), "))", ""), "(", ""), "((", ""), "<", " < ");
}

void HistoPlot::draw_subtitle(Variable* variable, std::vector<Variable*>* variables,
                              bool with_cut, DataChain* data, std::string supervar_selection,std::string mva_cut_str)
{
  std::string sel;
	 if (variables == NULL)
  {
    sel = supervar_selection;
  }
	 else
	 {

			 sel = style_selection(get_selection(variable, variables, with_cut, false, data,1.0,mva_cut_str));
	 }

	 std::string selection = "Selection:" + sel;
  std::string l1        = "#font[12]{" + selection.substr(0, 90) + "-}";
  std::string l2        = "#font[12]{" + selection.substr(88, 90) + "-}";
  std::string l3        = "#font[12]{" + selection.substr(178, 88) + "}";
  std::string l4        = "#font[12]{" + selection.substr(266, selection.length()-266) + "}";

  TPaveText* pts        = new TPaveText(0.1, 1.0, 0.9, 0.9, "blNDC");

  pts->SetBorderSize(0);
  pts->SetFillColor(0);
  pts->AddText(l1.c_str());
  pts->AddText(l2.c_str());
  pts->AddText(l3.c_str());
  pts->AddText(l4.c_str());


  pts->SetAllWith(l1.c_str(), "size", 0.03);
  pts->SetAllWith(l2.c_str(), "size", 0.03);
  pts->SetAllWith(l3.c_str(), "size", 0.03);
  pts->SetAllWith(l4.c_str(), "size", 0.03);

  pts->Draw();
}


THStack HistoPlot::draw_stacked_histo(TLegend* legend, Variable* var, std::vector<DataChain*> bg_chains,
                                      bool with_cut, std::vector<double> mc_weights_vector, std::vector<Variable*>* variables, 
                                      DataChain* data,std::string mc_selection, std::string mva_cut_str)
{
  THStack stack(var->name_styled, "");
  
  for(int i = 0; i < bg_chains.size(); i++) {
//std::cout<<"background: "<<bg_chains[i]->label<<"\n";

    TH1F* single_bg_histo = draw_background(bg_chains[i], var, colours()[i], with_cut, variables,mc_selection, mva_cut_str, mc_weights_vector[i]);
//std::cout<<"background drawn about to add to stack: "<<"\n";

    stack.Add(single_bg_histo);
    std::string legend_str(bg_chains[i]->legend);
    legend_str += (" #font[12]{(MC weight: " + get_string_from_double(mc_weights_vector[i]) + ")}");
    legend->AddEntry(single_bg_histo, legend_str.c_str(), "f");

  }
  return stack;
}

TH1F* HistoPlot::get_max_histo(std::vector<TH1F*> plot_histos)
{
  double plot_max = 0.0;
  TH1F* histo_max = NULL;
  for (int i = 0; i < plot_histos.size(); i++)
  {
    if (plot_histos[i] != NULL)
    {
					double y_max = get_histo_y_max(plot_histos[i]);

					if (y_max > plot_max)
					{
							plot_max = y_max;
							histo_max = plot_histos[i];
					}
    }
  }

  return histo_max;
}

double HistoPlot::get_histo_y_max(TH1F* histo)
{
std::cout<<"max bin: "<< histo->GetMaximumBin()<<"\n";
  return histo->GetBinContent(histo->GetMaximumBin());
}

void HistoPlot::build_legend(TLegend* legend, TH1F* max_histo, Variable* var, bool with_cut)
{
  double x1 = position_legend_x1(max_histo, var, with_cut);
  double x2 = x1 + 0.26;

  style_legend(legend);

  legend->SetX1(x1);
  legend->SetX2(x2);
  legend->Draw();

}

double HistoPlot::position_legend_x1(TH1F* max_histo, Variable* var, bool with_cut)
{
  int max_bin         = max_histo->GetMaximumBin();
  double nbins        = var->get_bins(with_cut);
  double max_bin_x1   = get_x1_from_bin(max_bin, nbins);

  if (max_bin_x1 > 0.5)
  {
    return 0.12;
  }
  else
  {
    return 0.56;
  }
}

double HistoPlot::get_x1_from_bin(double max_bin, double nbins)
{
  return max_bin * 0.8 / nbins + 0.1;
}

void HistoPlot::style_stacked_histo(THStack* hs, const char* x_label)
{
  hs->GetYaxis()->SetTitle("Events");
  hs->GetYaxis()->SetLabelSize(0.035);
  hs->GetYaxis()->SetTitleOffset(1.55);
  hs->GetXaxis()->SetLabelSize(0);
}

void HistoPlot::style_ratio_histo(TH1F* single_histo, const char* x_label, bool plot_data)
{
  if (plot_data)
  {
   single_histo->GetYaxis()->SetTitle("Signal/Data");
  }
  else{
  single_histo->GetYaxis()->SetTitle("Signal/Background"); //when not tmva was data/MC
  }
  single_histo->GetYaxis()->SetLabelSize(0.12);
  single_histo->GetYaxis()->SetTitleOffset(0.45);
  single_histo->GetYaxis()->SetTitleSize(0.12);
  single_histo->GetXaxis()->SetLabelSize(0.12);
  single_histo->GetXaxis()->SetTitle(x_label);
  single_histo->GetXaxis()->SetTitleSize(0.12);
  single_histo->GetXaxis()->SetTitleOffset(1.1);

  single_histo->SetTitle("");
  single_histo->SetStats(false);
  single_histo->GetYaxis()->SetNdivisions(5, 5, 0);
}

void HistoPlot::style_legend(TLegend* legend)
{
  legend->SetTextSize(0.025);
  legend->SetBorderSize(0);
  legend->SetFillStyle(0);
}

TH1F* HistoPlot::build_1d_histo(DataChain* data_chain, Variable* variable, bool with_cut, bool is_signal,
                                const char* option, std::vector<Variable*>* variables, std::string mc_selection, std::string mva_cut_str, double mc_weight)
{
  std::string var_arg = variable->build_var_string(data_chain->label, with_cut);
  std::string selection_str;

  if (mc_selection == "")
  {

    selection_str = get_selection(variable, variables, with_cut, is_signal, data_chain, mc_weight, mva_cut_str);
  }
  else
  {
    selection_str = mc_selection;
  }

  //std::cout << "selection - " << selection_str << std::endl;
  //std::cout << "var arg - " << var_arg << std::endl;
  data_chain->chain->Draw(var_arg.c_str(), selection_str.c_str(), option);

  TH1F* histo = (TH1F*)gDirectory->Get(data_chain->label);

  return histo;
}

TH1F* HistoPlot::draw_data(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
                           std::vector<Variable*>* variables,std::string mc_selection, std::string mva_cut_str)
{
  data_chain->chain->SetMarkerStyle(7);
  data_chain->chain->SetMarkerColor(1);
  data_chain->chain->SetLineColor(1);
//std::cout<<"HistoPlot::draw_data about to creeat th1d"<<"\n";
  TH1F* data_histo = set_error_bars(build_1d_histo(data_chain, variable, with_cut, false, "E1", variables,mc_selection,mva_cut_str));
  legend->AddEntry(data_histo, data_chain->legend, "lep");

  return data_histo;
}

TH1F* HistoPlot::draw_signal(DataChain* data_chain, Variable* variable, bool with_cut, TLegend* legend,
                             std::vector<Variable*>* variables,std::string mc_selection, std::string mva_cut_str)
{
  data_chain->chain->SetLineColor(2);
  data_chain->chain->SetLineWidth(3);
  data_chain->chain->SetFillColor(0);
  TH1F* signal_histo = build_1d_histo(data_chain, variable, with_cut, true, "goff", variables,mc_selection, mva_cut_str);
  legend->AddEntry(signal_histo, (build_signal_leg_entry(variable, data_chain)).c_str(), "l");

  return signal_histo;
}

TH1F* HistoPlot::draw_background(DataChain* data_chain, Variable* variable, 
                                 int fill_colour, bool with_cut, std::vector<Variable*>* variables,std::string mc_selection, std::string mva_cut_str, double mc_weight)
{
  data_chain->chain->SetLineColor(1);
  data_chain->chain->SetFillColor(fill_colour);

  return build_1d_histo(data_chain, variable, with_cut, false, "goff", variables, mc_selection, mva_cut_str, mc_weight);
}

TH1F* HistoPlot::data_to_bg_ratio_histo(TH1F* data_histo, TH1F* bg_histo)
{
  TH1F* ratio_histo = (TH1F*) data_histo->Clone();
  ratio_histo->Divide(bg_histo);
  ratio_histo->SetMarkerColor(1);

  return set_ratio_error_bars(ratio_histo, data_histo, bg_histo);
}

TH1F* HistoPlot::set_ratio_error_bars(TH1F* ratio_histo, TH1F* data_histo, TH1F* bg_histo)
{
  int nbins = ratio_histo->GetNbinsX();

  for(int i = 0; i < nbins; i++) 
  {
    double error_val = std::pow(get_data_error(data_histo, i), 0.5) / get_data_error(bg_histo, i);
    ratio_histo->SetBinError(i, error_val);
  }

  return ratio_histo;
}

TH1F* HistoPlot::set_error_bars(TH1F* histo) 
{
  int nbins = histo->GetNbinsX();
  for(int i = 0; i < nbins; i++) {
    double error_val = std::pow(get_data_error(histo, i), 0.5);
    histo->SetBinError(i, error_val);
  }

  return histo;
}

void HistoPlot::set_th1d_error_bars(TH1D* histo)
{
  int nbins = histo->GetNbinsX();

  for(int i = 0; i < nbins; i++) {
    double error_val = std::pow(get_th1d_data_error(histo, i), 0.5);
    histo->SetBinError(i, error_val);
  }
}

float HistoPlot::get_data_error(TH1F* histo, int bin) 
{

  return histo->Integral(bin, bin + 1);
}

double HistoPlot::get_th1d_data_error(TH1D* histo, int bin)
{
  return histo->Integral(bin, bin + 1);
}

std::string HistoPlot::build_file_name(Variable* variable, bool with_cut) 
{
  std::string file_name(variable->name);

  if (with_cut)
  {
    file_name += "_cut_";
    file_name.append((variable->bins_cut).c_str());
    file_name += "_";
    file_name.append(variable->x_min_cut);
    file_name += "_";
    file_name.append(variable->x_max_cut);
  }
  else
  {
    file_name += "_nocut_";
    file_name.append(variable->bins_nocut);
    file_name += "_";
    file_name.append(variable->x_min_nocut);
    file_name += "_";
    file_name.append(variable->x_max_nocut);
  }
  file_name += ".png";

  return file_name;
}

std::string HistoPlot::build_signal_leg_entry(Variable* var, DataChain* signal_chain)
{
  std::string signal_leg_str(signal_chain->legend);
  signal_leg_str += " (x";
  signal_leg_str.append(var->signal_multiplier);
  signal_leg_str += ")";

  return signal_leg_str;
}

void HistoPlot::plot_control_region(  DataChain* data,DataChain* signal_chain,DataChain* single_bg_chain, 
std::vector<DataChain*> bg_chains, 
Variable* var, std::vector<Variable*>* variables, std::string mva_cut_str)
{
   bool with_cut=true;
 bool is_signal=true;
  bool plot_data=false;
  //TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);
  std::string mc_selection = MCWeights::get_mc_selection_str(single_bg_chain, var, variables,mva_cut_str);
int b_pos= mc_selection.find("(")+1;

//std::cout<<"selection: "<<mc_selection<<"\n";
draw_plot(var, bg_chains, signal_chain,  data, with_cut,variables, plot_data,true,"", mc_selection, mva_cut_str);

}

//DEBUG DRAW_PLOT==========================
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
/*bool with_cut = true;
bool plot_data = false;
//step 1 declare canvas, pads and legends
/////////////////////////////////////////
TCanvas* c1     = new TCanvas("c1", vars2[6]->name_styled, 800, 800);
TPad* p1        = new TPad("p1", "p1", 0.0, 0.95, 1.0, 1.0);
TPad* p2        = new TPad("p2", "p2", 0.0, 0.2, 1.0, 0.95);
  TPad* p3        = new TPad("p3", "p3", 0.0, 0.0, 1.0, 0.2);


TLegend* legend = new TLegend(0.0, 0.5, 0.0, 0.88);
//step 2 set size of margins
 p1->SetLeftMargin(0.102);
p2->SetBottomMargin(0.012);
  p2->SetLeftMargin(0.105);
p3->SetBottomMargin(0.3);
  p3->SetLeftMargin(0.102);
 p1->Draw();
  p2->Draw();
  p3->Draw();

  p2->cd();
//step 3 create mc weights vector
double arr[output_bg_chains.size()];
std::fill_n(arr, output_bg_chains.size(), 1);

std::vector<double> mc_weights_vector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

//std::vector<double> mc_weights_vector = HistoPlot::mc_weights(data_chain, output_bg_chains, vars2[6], true, &vars2);


//step 4 plot signal, data and background histos
TH1F* signal_histo = HistoPlot::draw_signal(output_signal_chain, vars2[6], true, legend, &vars2,"", mva_cut_str);
TH1F* data_histo;

//THStack stack      = HistoPlot::draw_stacked_histo(legend, vars2[6], output_bg_chains,true,mc_weights_vector, &vars2, data_chain, "", mva_cut_str);
int ret[8] = {40, 41, 42, 30, 38, 28, 15, 49}; // colour array
 THStack stack(vars2[6]->name_styled, "");

  for(int i = 0; i < bg_chains.size(); i++) {
std::cout<<"background: "<<bg_chains[i]->label<<"\n";
    TH1F* single_bg_histo = HistoPlot::draw_background(output_bg_chains[i], vars2[6], ret[i], true, &vars,"", mva_cut_str, mc_weights_vector[i]);
//std::cout<<"background drawn about to add to stack: "<<"\n";

    stack.Add(single_bg_histo);
    std::string legend_str(bg_chains[i]->legend);
    legend_str += (" #font[12]{(MC weight: " + HistoPlot::get_string_from_double(mc_weights_vector[i]) + ")}");
    legend->AddEntry(single_bg_histo, legend_str.c_str(), "f");

  }
//step 5 draw signal, background and data histograms
stack.Draw();
signal_histo->Draw("SAME");
HistoPlot::style_stacked_histo(&stack, vars2[6]->name_styled);

//step 6 find maximum histogram height and set legend position away from maximum-checked
TH1F* plot_histos_no_data[2] = {(TH1F*)(stack.GetStack()->Last()), signal_histo};
TH1F* plot_histos_with_data[3] = {(TH1F*)(stack.GetStack()->Last()), signal_histo, data_histo};
TH1F* max_histo;
if (plot_data)
{
  std::cout<<"im in the wrong place\n";
  std::vector<TH1F*> plot_histos_vector (plot_histos_with_data, plot_histos_with_data + sizeof(plot_histos_with_data) / sizeof(  plot_histos_with_data[0]));
  max_histo      = HistoPlot::get_max_histo(plot_histos_vector);
}
else 
{
  std::cout<<"im in the right place\n";
  std::vector<TH1F*> plot_histos_vector (plot_histos_no_data, plot_histos_no_data + sizeof(plot_histos_no_data) / sizeof(plot_histos_no_data[0]));
  max_histo      = HistoPlot::get_max_histo(plot_histos_vector);
}
  
  stack.SetMaximum(HistoPlot::get_histo_y_max(max_histo)*1.15);

  HistoPlot::build_legend(legend, max_histo, vars2[6], with_cut);
   HistoPlot::draw_subtitle(vars2[6], &vars2, with_cut, data_chain,mva_cut_str); 

//step 7 draw ratio of signal/background or signal/data histogram -testing...

  p3->cd();
  TH1F* data_bg_ratio_histo;
  if (plot_data)
  {
    data_bg_ratio_histo = HistoPlot::data_to_bg_ratio_histo(plot_histos_with_data[2], plot_histos_with_data[0]);// plot signal to bg
  }
  else
  {
    data_bg_ratio_histo = HistoPlot::data_to_bg_ratio_histo(plot_histos_no_data[1], plot_histos_no_data[0]);
  }
std::cout<<"about to draw ratio histo \n";
  data_bg_ratio_histo->Draw("e1");
  HistoPlot::style_ratio_histo(data_bg_ratio_histo, vars2[6]->name_styled, plot_data);
  HistoPlot::draw_yline_on_plot(vars2[6], with_cut, 1.0);


//step 9 create file name and save and close image
//
p1->cd();

HistoPlot::draw_title(vars2[6]->name_styled);

std::string img_name = "debug-stack-nocut.png";
c1->SaveAs(img_name.c_str());
c1->Close();*/

// std::string var_arg = vars2[6]->build_var_string(output_signal_chain->label, true);
//selection_str = HistoPlot::get_selection(vars2[6], &vars2, true, true, output_signal_chain, 1, mva_cut_str);

//output_bg_chains[0]->chain->Draw(var_arg.c_str(), selection_str.c_str());
//output_signal_chain->chain->Draw(var_arg.c_str(), selection_str.c_str());

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

