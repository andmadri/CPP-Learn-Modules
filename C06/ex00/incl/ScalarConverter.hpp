#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cctype>
#include <iomanip>

class ScalarConverter{
private:
    ScalarConverter() = default;
    ScalarConverter(const ScalarConverter& other) = delete;
    ScalarConverter& operator=(const ScalarConverter& other) = delete;
    ~ScalarConverter() = default;

public:
    static void convert(const std::string& literal);
};

#endif