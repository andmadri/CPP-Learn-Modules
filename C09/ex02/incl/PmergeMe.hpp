#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int binarySearch(std::vector<int>& sorted, int number);
void insertRemaining(std::vector<int>& sorted, std::vector<int>& not_sorted);
bool validateInput(const std::string& input);
std::vector<int> fordJohnsonAlgorithm(std::vector<int>& elements);
std::vector<int> convertInput(const std::string& input);

template<typename Container>
void printContainer(Container s) {
	for (size_t i = 0; i < s.size(); ++i) {
		std::cout << s[i] << " ";
	}
	std::cout << std::endl;
}

#endif