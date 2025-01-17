#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>

int binarySearch(std::vector<int>& sorted, int number);
void insertRemaining(std::vector<int>& sorted, std::vector<int>& not_sorted);
std::vector<int> fordJohnsonAlgorithm(std::vector<int>& elements);

#endif