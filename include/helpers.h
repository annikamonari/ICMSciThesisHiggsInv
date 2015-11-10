#ifndef Helpers_h
#define Helpers_h

#include <stdio.h>
#include <string.h>

char* build_string(std::vector<char*> pchars) {
  std::string str_from_pchars;

  for(int i = 0; i < pchars.size(); i++) {
    str_from_pchars.append(pchars[i]);
  }

  return str_from_pchars.c_str();
}

char* build_title(std::vector<char*> words) {
  char* title = build_string(words);
  title[0] = toupper(title[0]);
  return title;
}

#endif