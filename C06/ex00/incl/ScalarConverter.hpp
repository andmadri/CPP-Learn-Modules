#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <limits.h>

class ScalarConverter{
private:
    ScalarConverter() = default;

public:
    static void convert(const std::string& literal);
};

enum class ScalarType{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NONE
};

#endif