#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>

template<typename T>
void easyfind(T container, int target) {
    auto it = std::find(container.begin(), container.end(), target);
    if (it == container.end()) {
        throw std::invalid_argument("Target not found");
    }
    std::cout << target << " found at index " << std::distance(container.begin(), it) << std::endl;
}

#endif