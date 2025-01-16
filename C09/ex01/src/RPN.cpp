#include "../incl/RPN.hpp"

bool validCharacters(const char c) {
    return (c == ' ' || c == '*' || c == '+' || c == '-' || c == '\\' || (c >= 48 && c <= 57));
}

bool validateString(const std::string& str) {
    for (const char& c : str) {
        if (!validCharacters(c)) {
            std::cerr << "Error: not a valid string" << std::endl;
            return false;
        }
    }
    return true;
}
