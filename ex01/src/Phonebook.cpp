#include "Phonebook.hpp"

Contact& Phonebook::getContact(int index){
	return m_contatcs[index];
}

std::string& getValidInput(std::string& input, const std::string& prompt){
	while(input.empty()){
		std::cout << "Invalid Input. Try " << prompt << ": ";
		getline(std::cin, input);
	}
	return (input);
}

void Phonebook::addContact(int index){
	std::string input;
	Contact& contact = getContact(index);

	std::cout << "First Name: ";
	getline(std::cin, input);
	if (input.empty())
		getValidInput(input, "First Name");
	contact.setFirstName(input);
	std::cout << "Last Name: ";
	getline(std::cin, input);
	if (input.empty())
		getValidInput(input, "Last Name");
	contact.setLastName(input);
	std::cout << "Nickname: ";
	getline(std::cin, input);
	if (input.empty())
		getValidInput(input, "Nickname");
	contact.setNickname(input);
	std::cout << "Phonenumber: ";
	getline(std::cin, input);
	if (input.empty())
		getValidInput(input, "Phonenumber");
	contact.setPhonenumber(input);
	std::cout << "Darkest Secret: ";
	getline(std::cin, input);
	if (input.empty())
		getValidInput(input, "Phonenumber");
	contact.setDarkestSecret(input);
}
