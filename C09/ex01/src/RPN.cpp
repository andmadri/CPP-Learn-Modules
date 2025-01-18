#include "RPN.hpp"

bool isOperator(const char c)
{
    return (c == '*' || c == '+' || c == '-' || c == '/');
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

bool validateString(const std::string &str)
{
    if (str.begin() == str.end()) {
        std::cerr << "Error: empty string" << std::endl;
        return false;
    }
    int i = 0;
    for (const char &c : str)
    {
        if (i % 2 != 0 && c != ' ' && i != 0) {
            std::cerr << "Error: not a valid string" << std::endl;
            return false;
        }
        if (!isOperator(c) && !isDigit(c) && c != ' ')
        {
            std::cerr << "Error: not a valid string" << std::endl;
            return false;
        }
        i++;
    }
    return true;
}

void executeOperator(char c, std::stack<int> &stack)
{

    if (stack.size() < 2)
    {
        std::cerr << "Error: input string is not correct" << std::endl;
        exit(1);
    }
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();

    switch (c)
    {
    case '+':
        stack.push(b + a);
        break;
    case '-':
        stack.push(b - a);
        break;
    case '*':
        stack.push(b * a);
        break;
    case '/':
        stack.push(b / a);
        break;
    }
}

void RPN(const std::string &str)
{
    std::stack<int> stack;
    for (const char &c : str)
    {
        if (isDigit(c))
        {
            stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            executeOperator(c, stack);
        }
    }
    std::cout << stack.top() << std::endl;
}
