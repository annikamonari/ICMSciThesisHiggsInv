#include "../include/variable.h"

Variable::Variable(const char* var_name, const char* var_name_styled, const char* nbins, 
                   const char* x_min, const char* x_max, const char* x_min_c, 
                   const char* x_max_c, const char* xsignal)
{
  name              = var_name;
  name_styled       = var_name_styled;
  signal_multiplier = xsignal;
  bins_nocut        = nbins;
  x_min_nocut       = x_min;
  x_max_nocut       = x_max;
  x_min_cut         = x_min_c;
  x_max_cut         = x_max_c;
  bins_cut          = scale_bins_for_cut();
}

const char* Variable::scale_bins_for_cut() 
{
  const double x_min_nocut_d = atof(x_min_nocut);
  const double x_max_nocut_d = atof(x_max_nocut);
  const double x_min_cut_d   = atof(x_min_cut);
  const double x_max_cut_d   = atof(x_max_cut);
  double fraction      = (x_max_cut_d - x_min_cut_d) / (x_max_nocut_d - x_min_nocut_d);
  const double bins          = atof(bins_nocut);
  double bins_cut      = bins * fraction;
   
  bins_cut           = bins_cut + 0.5;

  int bins_cut_int   = (int) bins_cut;

  return "0";
  std::stringstream scaled_bins_ss;
  scaled_bins_ss << bins_cut_int;

  std::string scaled_bins_str = scaled_bins_ss.str();

  return scaled_bins_str.c_str();
}

std::string Variable::build_var_string(const char* label, bool with_cut) 
{
  std::string var_string(name);
  var_string += ">>";
  var_string.append(label);
  var_string += "(";

  if (with_cut) {
    var_string.append(bins_cut);
    var_string += ",";
    var_string.append(x_min_cut);
    var_string += ",";
    var_string.append(x_max_cut);
    var_string += ")";
  }
  else {
    var_string.append(bins_nocut);
    var_string += ",";
    var_string.append(x_min_nocut);
    var_string += ",";
    var_string.append(x_max_nocut);
    var_string += ")";
  } 
  return var_string;
}

std::string Variable::build_selection_string(bool with_cut, bool is_signal) 
{
  std::string sel_string("");

  if (with_cut) {
    sel_string += "((";
    sel_string.append(name);
    sel_string += ">";
    sel_string.append(x_min_cut);
    sel_string += ")&&(";
    sel_string.append(name);
    sel_string += "<";
    sel_string.append(x_max_cut);
    sel_string += "))*";
  } 

  sel_string += "total_weight_lepveto";

  if(is_signal) {
    sel_string += "*";
    sel_string.append(signal_multiplier);
  }
  
  return sel_string;
}
