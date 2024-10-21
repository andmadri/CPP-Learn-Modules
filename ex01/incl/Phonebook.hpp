#pragma once
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <string_view>
# include <array>
# include <limits>
# include "Contact.hpp"

class Phonebook{
public:
	Phonebook() = default;
	~Phonebook() = default;
	void addContact(int index);
	void displaySavedContacts();
	void displayOneContact();

private:
	Contact m_contacts[8];
	// Contact& getContact(int index) {return m_contacts[index];}
};

#endif
