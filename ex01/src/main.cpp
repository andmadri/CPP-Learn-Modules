#include <iostream>
#include "Phonebook.hpp"

int main(){
	Phonebook phonebook;
	std::string input;
	int	index = 0;

	while (true){
		std::cout << "Choose Option: ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD"){
			if (index == 8) index = 0;
			phonebook.addContact(index);
			index++;
		}
		else if (input == "SEARCH"){

		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Wrong Input. Try Again\n";
	}
	return 0;
}