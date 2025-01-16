#include "../incl/BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cerr << "Error: not enough arguments" << std::endl;
		return 1;
	}
	std::ifstream InputFile(argv[1]);
	if (!InputFile) {
		std::cerr << "Error: opening file" << std::endl;
		return 1;
	}
	BitcoinExchange::processInputFile(InputFile);
	return 0;
}