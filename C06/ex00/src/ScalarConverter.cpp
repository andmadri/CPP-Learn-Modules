#include "../incl/ScalarConverter.hpp"


//use try catch blocks for exceptions 
//stof() convert string to float
//stod() for string to double

static char convertChar(const std::string& literal){
  try {
    int n = std::stoi(literal);
    if (n >= CHAR_MIN && n <= CHAR_MAX){
      return static_cast<char>(n);
    }
  }
}

static float convertFloat(const std::string& literal){
  for()
}

void ScalarConverter::convert(const std::string& literal){
  if (literal.length() == 1 || )
    convertChar(literal);
  try {
    std::stoi(literal);
    //return 
  } catch (...) {}
  try {
    std::stof(literal);
    //return
  } catch (...) {}
  try {
    std::stod(literal);
    //return
  } catch(...) {}
}