#include "../incl/PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: not correct number of arguments" << std::endl;
	}
	std::cout << "Before: " << argv[1] << std::endl;
	std::vector<int> sorted = {3, 5, 9, 7, 4};
	std::vector<int> sorted = fordJohnsonAlgorithm(sorted);
	std::cout << "After: " << sorted << std::endl;
}
