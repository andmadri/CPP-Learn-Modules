#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

std::vector<int> fordJohnsonAlgorithmVector(std::vector<int>& elements);
std::list<int> fordJohnsonAlgorithmList(std::list<int>& elements);
std::list<int>::iterator binarySearchList(std::list<int> sorted, int number);
int binarySearchVector(std::vector<int> sorted, int number);
void insertRemaining(std::vector<int>& sorted, std::vector<int>& not_sorted);
bool validateInput(std::string& input);
std::vector<int> fordJohnsonAlgorithm(std::vector<int>& elements);
std::vector<int> convertInput(const std::string& input);

template<typename Container>
void printContainer(Container s) {
	for (auto it = s.begin(); it != s.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename Container>
Container convertInput(const std::string& input) {
	
	std::stringstream ss(input);
	Container numbers;
	std::string token;

	while (ss >> token) {
		try {
			int number = std::stoi(token);
			numbers.push_back(number);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
	return numbers;
}

#endif