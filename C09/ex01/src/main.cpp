#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error:: the number of arguments is invalid" << std::endl;
    }
    if (!validateString(argv[1]))
    {
        return (1);
    }
    RPN(argv[1]);
}