#pragma once
#ifndef __CONTACT_H__
# define __CONTACT_H__

#include <iostream>
#include <string>

class Contact{

public:

	Contact() = default;
	~Contact()= default;
	
	void setFirstName(const std::string& first_name);
	void setLastName(const std::string& last_name);
	void setNickname(const std::string& nickname);
	void setPhonenumber(const std::string& phonenumber);
	void setDarkestSecret(const std::string& darkest_secret);
	void setIndexContact(int index);
	
	std::string getFirstName() const;
	std::string getLastname() const;
	std::string getNickname() const;
	std::string getPhonenumber() const;
	std::string getDarkestSecret() const;
	
	int getIndexContact() const;

private:

	int			m_index_contact;
	
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phonenumber;
	std::string m_darkest_secret;
};

#endif