#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <string_view>
# include "Contact.hpp"

class Phonebook{
public:
	Phonebook() = default;
	~Phonebook() = default;
	void addContact(int index);
private:
	Contact m_contatcs[8];
	Contact& getContact(int index);
};

#endif
