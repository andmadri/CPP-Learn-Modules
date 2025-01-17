#include "../incl/PmergeMe.hpp"

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
	insertRemaining(S, smaller);
	return S;
}
