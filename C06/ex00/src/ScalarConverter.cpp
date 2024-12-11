#include "../incl/ScalarConverter.hpp"

bool iscontrolchar(const std::string& literal){
    if (literal.length() == 2){
        if (literal[0] == '\\' && (literal[1] == 'n' || literal[1] == 't' || literal[1] == 'r' || literal[1] == 'v'))
    }
}

static ScalarType determineScalarType(const std::string& literal){
    if (iscontrolchar(literal) || (literal.length() == 1 && std::isprint(literal[0]))
        return ScalarType::CHAR;
}

void ScalarConverter::convert(const std::string& literal){
    determineScalarType(literal);
}