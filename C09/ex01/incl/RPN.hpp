#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

bool isOperator(const char c);
bool isDigit(const char c);
bool validateString(const std::string &str);
void executeOperator(char c, std::stack<int> &stack);
void RPN(const std::string &str);

#endif