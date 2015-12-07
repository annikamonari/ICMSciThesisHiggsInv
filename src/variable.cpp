#include "../include/variable.h"

Variable::Variable(const char* var_name, const char* var_name_styled, const char* x_min,
																			const char* x_max, const char* x_min_c, const char* x_max_c,
																			const char* nbins, const char* xsignal, bool abs_val_for_cuts)
{
  name              = var_name;
  name_styled       = var_name_styled;
  signal_multiplier = xsignal;
  bins_nocut        = nbins;
  x_min_nocut       = x_min;
  x_max_nocut       = x_max;
  x_min_cut         = x_min_c;
  x_max_cut         = x_max_c;
  abs_for_cut							= abs_val_for_cuts;
  bins_cut          = scale_bins_for_cut();
}

std::string Variable::scale_bins_for_cut()
{
  double x_min_nocut_d = atof(x_min_nocut);
  double x_max_nocut_d = atof(x_max_nocut);
  double x_min_cut_d   = atof(x_min_cut);
  double x_max_cut_d 		= 0.0;

  if (strcmp(x_max_cut, ""))
  {
  		x_max_cut_d = atof(x_max_cut);
  }
  else
  {
  		x_max_cut_d = atof(x_max_nocut);
  }

  double  fraction  = (x_max_cut_d - x_min_cut_d) / (x_max_nocut_d - x_min_nocut_d);
  const double bins = atof(bins_nocut);
  double bins_cut   = bins * fraction;
  bins_cut          = bins_cut + 0.5;
  int bins_cut_int  = (int) bins_cut;

  if (bins_cut_int == 0)
  {
  		bins_cut_int += 1;
  }

  std::stringstream scaled_bins_ss;
  scaled_bins_ss << bins_cut_int;
  std::string scaled_bins_str = scaled_bins_ss.str();

  return scaled_bins_str;
}

std::string Variable::build_var_string(const char* label, bool with_cut) 
{
  std::string var_string(name);
  var_string += ">>";
  var_string.append(label);
  var_string += "(";

  if (with_cut)
  {
    var_string += bins_cut;
    var_string += ",";
    var_string.append(x_min_cut);
    var_string += ",";

    if (strcmp(x_max_cut, ""))
    {
    		var_string.append(x_max_cut);
    }
    else
    {
    		var_string.append(x_max_nocut);
    }
    var_string += ")";
  }
  else
  {
    var_string.append(bins_nocut);
    var_string += ",";
    var_string.append(x_min_nocut);
    var_string += ",";
    var_string.append(x_max_nocut);
    var_string += ")";
  }

  return var_string;
}

std::string Variable::build_multicut_selection(bool is_signal, std::vector<Variable*>* variables, std::string lepton_sel)
{
		std::string sel_string = build_selection_string(true, is_signal, lepton_sel);
		int insert_pos 								= sel_string.find("(") + 1;

		for (int i = 0; i < variables->size(); i++)
		{
				if (((*variables)[i]->name) != name)
				{
						std::string var_sel = build_selection((*variables)[i]->name, (*variables)[i]->x_min_cut,
																																												(*variables)[i]->x_max_cut, (*variables)[i]->abs_for_cut);
						sel_string.insert(insert_pos, var_sel + "&&");
				}
		}

		return sel_string;
}

std::string Variable::build_selection_string(bool with_cut, bool is_signal, std::string lepton_sel)
{
  std::string sel_string("total_weight_lepveto*");
  sel_string += lepton_sel; //lepton_sel syntax must have an open ( at the front, or if MC weight applied between this and the lepton_sel part

  if (with_cut)
  {
  		sel_string += "&&" + build_selection(name, x_min_cut, x_max_nocut, abs_for_cut);
  }

  sel_string += ")";

  if(is_signal) {
    sel_string += "*";
    sel_string.append(signal_multiplier);
  }
  return sel_string;
}

std::string Variable::build_selection(const char* var_name, const char* x_min_cut,
																																						const char* x_max_cut, bool abs_for_cut)
{
		std::string sel_str;
		sel_str += build_single_selection(var_name, ">", x_min_cut, abs_for_cut);

		if (strcmp(x_max_cut, ""))
		{
				sel_str += "&&";
				sel_str += build_single_selection(var_name, "<", x_max_cut, abs_for_cut);
		}

	 return sel_str;
}

std::string Variable::build_single_selection(const char* var_name, const char* op, const char* val, bool abs_for_cut)
{
	 std::string var_str;
	 var_str += "(";
	 if (abs_for_cut)
	 {
	 		var_str += "abs(";
	 		var_str.append(var_name);
	 		var_str += ")";
	 }
	 else
	 {
	 		var_str.append(var_name);
	 }
	 var_str.append(op);
	 var_str.append(val);
	 var_str += ")";

	 return var_str;
}

double Variable::get_graph_dx(bool with_cut)
{
  return (get_x_max(with_cut) - get_x_min(with_cut));
}

double Variable::get_x_min(bool with_cut)
{
  if (with_cut)
  {
    return atof(x_min_cut);
  }
  else
  {
    return atof(x_min_nocut);
  }
}

double Variable::get_x_max(bool with_cut)
{
  if (with_cut && strcmp(x_max_cut, ""))
  {
    return atof(x_max_cut);
  }
  else
  {
    return atof(x_max_nocut);
  }
}

double Variable::get_bins(bool with_cut)
{
  if (with_cut)
  {
    return atof(bins_cut.c_str());
  }
  else
  {
    return atof(bins_nocut);
  }
}

