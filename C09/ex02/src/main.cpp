#include "../incl/PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: not correct number of arguments" << std::endl;
	}
	if (!validateInput(argv[1])) {
		return 1;
	}
	std::vector<int> to_sort = convertInput(argv[1]);
	std::vector<int> sorted = fordJohnsonAlgorithm(to_sort);
	std::cout << "Before: " << argv[1] << std::endl;
	std::cout << "After: ";
	printContainer(sorted);
	return 0;
}
