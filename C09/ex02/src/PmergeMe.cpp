#include "../incl/PmergeMe.hpp"

bool validateInput(std::string& input) {
	for (char& c : input) {
		if (c == '-') {
			std::cerr << "Error: Not a Positive Integer Sequence" << std::endl;
			return false;
		} else if (!(c >= '0' && c <= '9') && c != ' ') {
			std::cerr << "Error: Not an Integer Sequence" << std::endl;
			return false;
		}
	}
	return true;
}

std::vector<int> convertInput(const std::string& input) {
	
	std::stringstream ss(input);
	std::vector<int> numbers;
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

int binarySearch(std::vector<int>& sorted, int number) {
	int start_index = 0;
	int end_index = sorted.size() - 1;
	while (start_index <= end_index) {
		int mid = start_index + (end_index - start_index) / 2;
		if (sorted[mid] < number) {
			start_index = mid + 1;
		} else {
			end_index = mid - 1;
		}
	}
	return start_index;
}

void insertRemaining(std::vector<int>& sorted, std::vector<int>& not_sorted) {
	for (int number : not_sorted) {
		int pos = binarySearch(sorted, number);
		sorted.insert(sorted.begin() + pos, number);
	}
}

std::vector<int> fordJohnsonAlgorithm(std::vector<int>& elements) {
	std::vector<int> larger;
	std::vector<int> smaller;

	if (elements.size() <= 1) {
		return elements;
	}
	for (size_t i = 0; i + 1 < elements.size(); i += 2) {
		if (elements[i] > elements[i + 1]) {
			larger.push_back(elements[i]);
			smaller.push_back(elements[i + 1]);
		} else if (elements[i] < elements[i + 1]) {
			larger.push_back(elements[i + 1]);
			smaller.push_back(elements[i]);
		}
	}

	if (elements.size() % 2 != 0) {
		smaller.push_back(elements.back());
	}
	std::vector<int> S = fordJohnsonAlgorithm(larger);
	S.insert(S.begin(), smaller[0]);
	std::cout << "smaller: "; 
	printContainer(smaller);
	smaller.erase(smaller.begin());
	if (smaller.size() > 1)
			insertRemaining(S, smaller);
	return S;
}
