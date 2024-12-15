#include "../incl/iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void printElement(const T& elem){
    std::cout << elem;
}

template<typename T>
void add(T& elem){
    elem += 1;
}


int main() {
    char array_i[] = "hello world";
    size_t array_i_len = 11;

    std::cout << "Printing Char Array: ";
    iter(array_i, array_i_len, printElement<char>);
    std::cout << std::endl;
    std::cout << "Adding to it: ";
    iter(array_i, array_i_len, add<char>);
    iter(array_i, array_i_len, printElement<char>);
    std::cout << std::endl;

    
    int array_j[] = {1, 2, 3, 4, 5};
    size_t array_j_len = sizeof(array_j)/sizeof(array_j[0]);

    std::cout << "Printing Int Array: ";
    iter(array_j, array_j_len, printElement<int>);
    std::cout << std::endl;
    std::cout << "Adding to it: ";
    iter(array_j, array_j_len, add<int>);
    iter(array_j, array_j_len, printElement<int>);
    std::cout << std::endl;

    std::string array_k[] = {"My", "Name", "Is", "Bob"};
    size_t array_k_len = sizeof(array_k)/sizeof(array_k[0]);

    std::cout << "Printing String Array: ";
    iter(array_k, array_k_len, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}