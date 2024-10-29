#include <iostream>
#include "../incl/Phonebook.hpp"


std::string trim(std::string& input)
{
	const char* white_space = " \t\v\r\n";
	std::size_t start = input.find_first_not_of(white_space);
	std::size_t end = input.find_last_not_of(white_space);
	if (start == end)
		return std::string();
	return input.substr(start, end - start + 1);
}


int main(){
	Phonebook phonebook;
	std::string input;
	int	index = 0;

	while (true){
		std::cout << "Choose Option: ADD, SEARCH, EXIT\n";
		if (!getline(std::cin, input)){
				return -1;
		}
		input = trim(input);
		if (input == "ADD"){
			if (index == 8){
				index = 0;
			}
			phonebook.addContact(index++);
			continue ;
		}
		else if (input == "SEARCH"){
			phonebook.displaySavedContacts();
			phonebook.displayOneContact();
			continue ;
		}
		else if (input == "EXIT"){
		 	break;
		}
		else if (std::cin.eof() || std::cin.bad() || std::cin.fail()){
			return -1;
		}
	 	else{
			std::cout << "Wrong Input. Try Again\n";
		}
	}
	return 0;
}
