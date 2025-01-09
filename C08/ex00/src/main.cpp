#include <iostream>
#include "../incl/easyfind.hpp"
#include <list>
#include <array>

int main(){
    std::cout << "---Test Normal Output---" << std::endl;
    try {
        std::list<int> lst = {1, 2, 3};
        std::array<char, 5> array = {'c', 'a' , '!' , '&' , 'b'};

        ::easyfind(lst, 2);
        ::easyfind(array, 'c');
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---Test Error Output---" << std::endl;
    try {
        std::list<int> lst = {1, 2, 3};
        std::array<char, 5> array = {'c', 'a' , '!' , '&' , 'b'};

        ::easyfind(lst, 4);
        ::easyfind(array, 'c');
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}