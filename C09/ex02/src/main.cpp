#include "../incl/PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: not correct number of arguments" << std::endl;
	}
	std::string inputString(argv[1]);
	if (!validateInput(inputString)) {
		return 1;
	}
	std::vector<int> vect = convertInput<std::vector<int>>(inputString);
	std::list<int> list = convertInput<std::list<int>>(inputString);
	std::vector<int> vect_sorted = fordJohnsonAlgorithmVector(vect);
	std::list<int> list_sorted = fordJohnsonAlgorithmList(list);
	std::cout << "Before: " << argv[1] << std::endl;
	std::cout << "After: ";
	printContainer(vect_sorted);
	printContainer(list_sorted);
	return 0;
}
