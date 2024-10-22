#include <iostream>
#include <sstream>
#include <string>

std::string appendStrings(int argc, char *argv[]) {
  std::string result;

  for (int i = 1; i < argc; i++) {
    result += argv[i];
    if (i < argc - 1) {
      result += " ";
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  std::string str = "*LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
  if (argc >= 2) {
     str = appendStrings(argc, argv);
    for (char &chr : str) {
      chr = static_cast<char>(std::toupper(chr));
     }
     str += "\n";
    }
  std::cout << str;
  return 0;
}
