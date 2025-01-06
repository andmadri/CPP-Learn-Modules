#include "../incl/ScalarConverter.hpp"
#include <stdexcept>

static bool isSpecial(const std::string& literal){
  return (literal == "-inff" || literal == "-inf" || literal == "+inff" || literal == "+inf" || literal == "nan");
}

static bool isChar(const std::string& literal){
  return (literal.length() == 3 && literal.at(0) == '\'' && literal.back() == '\'' && std::isprint(literal[1]));
}

static bool isInt(const std::string& literal){
  for (const char& c : literal) {
    if (c == 'f' || c == '.') {
      return false;
    }
  }
  try {
    std::stoi(literal);
    return true;
  } catch (...) {
    return false;
  }
}

static bool isFloat(const std::string& literal){
  bool d_found = false;

  for (size_t i = 0; i < literal.length(); ++i) {
    if (literal[i] == 'f' && i != literal.length() - 1) {
      return false;
    }
    if (literal[i] != 'f' && !std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != '-') {
      return false;
    }
    if (literal[i] == '.') {
      if (d_found) {
        return false;
      }
      d_found = true;
    }
  }
  if (!d_found)
    return false;
  if (d_found && literal.find('f') == std::string::npos)
    return false;
  try {
    std::stof(literal);
    return true;
  } catch (...) {
    return false;
  }
}

static bool isDouble(const std::string& literal){
  bool d_found = false;

  for (size_t i = 0; i < literal.length(); ++i) {
    if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != '-') {
      return false;
    }
    if (literal[i] == '.') {
      if (d_found) {
        return false;
      }
      d_found = true;
      if (literal[i] == '.' && i == literal.length() - 1) {
        return false;
      }
    }
  }
  try {
    std::stod(literal);
    return true;
  } catch (...) {
    return false;
  }
}

void ScalarConverter::convert(const std::string& literal){
  if (isSpecial(literal)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      if (literal == "+inff" || literal == "-inff") {
      std::cout << "float: " << literal << std::endl;
      } else {
      std::cout << "float: " << literal << "f" << std::endl;
      }
      if (literal == "+inff" || literal == "-inff") {
      std::string outlit = literal;
      outlit.pop_back();
      std::cout << "double: " << outlit << std::endl;
      } else {
      std::cout << "double: " << literal << std::endl;
      }
  }
  else if (isChar(literal)) {
      std::cout << "char: '" << literal[1] << "'" << std::endl;
      std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
      std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[1]) << "f" << std::endl;
      std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[1]) << std::endl;
  }
  else if (isInt(literal)) {
      int i = std::stoi(literal);
      std::cout << "char: " << (i >= 32 && i <= 126 ? "\'" + std::string(1, static_cast<char>(i)) + "\'" : "Non displayable") << std::endl;
      std::cout << "int: " << i << std::endl;
      std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
      std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
  }
  else if (isFloat(literal)) {
      float f = std::stof(literal);
      std::cout << "char: " << (f >= 32 && f <= 126 ? "\'" + std::string(1, static_cast<char>(f)) + "\'" : "Non displayable") << std::endl;
      std::cout << "int: " << (f > 2147483647.0 || f < -2147483648.0 ? "out of range" : std::to_string(static_cast<int>(f))) << std::endl;
      std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
      std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
  }
  else if (isDouble(literal)) {
      double d = std::stod(literal);
      std::cout << "char: " << (d >= 32 && d <= 126 ? "\'" + std::string(1, static_cast<char>(d)) + "\'" : "Non displayable") << std::endl;
      std::cout << "int: " << (d > 2147483647.0 || d < -2147483648.0 ? "out of range" : std::to_string(static_cast<int>(d))) << std::endl;
      if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::lowest()) {
        std::cout << "float: out of range" << std::endl;
      } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
      }
      std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
  }
}