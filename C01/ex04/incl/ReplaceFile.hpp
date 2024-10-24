#pragma once
#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

class Replace{

public:

  Replace(char **argv);
  ~Replace();
  int ifStreamCheck();
  int ofStreamCheck();
  void replaceStrings();


private:

  std::string in_name;
  std::string out_name;
  std::string s1;
  std::string s2;
  std::ifstream infile;
  std::ofstream outfile;

  bool isRegularFile();

};

#endif