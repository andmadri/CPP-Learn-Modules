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

int binarySearchVector(std::vector<int> sorted, int number) {
	
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

std::list<int>::iterator binarySearchList(std::list<int> sorted, int number) {
	
	auto start = sorted.begin();
	auto end = sorted.end();

	while(std::distance(start, end) > 0) {
		auto mid = start;
		std::advance(mid, std::distance(start, end) / 2);
		if (*mid < number) {
			start = std::next(mid);
		} else {
			end = mid;
		}
	}
	return start;
}

std::vector<int> fordJohnsonAlgorithmVector(std::vector<int>& elements) {
	std::vector<int> larger;
	std::vector<int> smaller;

	if (elements.size() <= 1) {
		return elements;
	}
	else if (elements.size() == 2) {
		if (elements[0] > elements[1]) {
			std::swap(elements[0], elements[1]);
		}
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
	std::vector<int> S = fordJohnsonAlgorithmVector(larger);
	for (int number : smaller) {
		int pos = binarySearchVector(S, number);
		S.insert(S.begin() + pos, number);
	}
	return S;
}

std::list<int> fordJohnsonAlgorithmList(std::list<int>& elements) {
	std::list<int> larger;
	std::list<int> smaller;

	if (elements.size() <= 1) {
		return elements;
	}
	// } else if (elements.size() == 2) {
	// 	if (elements.begin() > elements[1]) {
	// 		std::swap(elements[0], elements[1]);
	// 	}
	// 	return elements;
	// }
	auto it = elements.begin();
	while (it != elements.end()) {
		int first = *it;
		++it;
		if (it == elements.end()) {
			smaller.push_back(first);
			break ;
		}
		int second = *it;
		if (first > second) {
			larger.push_back(first);
			smaller.push_back(second);
		} else {
			larger.push_back(second);
			smaller.push_back(first);
		}
		++it;
	}
	std::list<int> S = fordJohnsonAlgorithmList(larger);
	for (int number : smaller) {
		auto pos = binarySearchList(S, number);
		S.insert(pos, number);
	}
	return S;
}
