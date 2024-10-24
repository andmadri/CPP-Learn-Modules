#include <iostream>
#include <string>
#include <iomanip>

int main(){
    std::string StringOG = "HI THIS IS BRAIN";
    std::string* stringPTR = &StringOG;
    std::string& stringREF = StringOG;

    std::cout << "--Memory Address--\n";
    std::cout << std::left << std::setw(20) << "StringOG: " << &StringOG << std::endl;
    std::cout << std::left << std::setw(20) << "StringPTR: " << stringPTR << std::endl;
    std::cout << std::left << std::setw(20) << "StringREF: " << &stringREF << std::endl;
    std::cout << "\n\n";
    std::cout << "------Values------\n";
    std::cout << std::left << std::setw(20) << "StringOG: " << StringOG << std::endl;
    std::cout << std::left << std::setw(20) << "StringPTR: " << *stringPTR << std::endl;
    std::cout << std::left << std::setw(20) << "StringREF: " << stringREF << std::endl;
    return 0;
}