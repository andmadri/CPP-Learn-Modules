#include <iostream>
#include "../incl/Phonebook.hpp"

int main(){
	Phonebook phonebook;
	std::string input;
	int	index = 0;

	while (true){
		std::cout << "Choose Option: ADD, SEARCH, EXIT\n";
		while(!(getline(std::cin, input))){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Choose Option: ADD, SEARCH, EXIT\n;
		}
		if (input == "ADD"){
			if (index == 8)
				index = 0;
			phonebook.addContact(index++);
			continue ;
		}
		else if (input == "SEARCH"){
			phonebook.displaySavedContacts();
			phonebook.displayOneContact();
			continue ;
		}
		else if (input == "EXIT")
		 	break;
	 	else
			std::cout << "Wrong Input. Try Again\n";
	}
	return 0;
}