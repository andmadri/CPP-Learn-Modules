#pragma once
#ifndef __CONTACT_H__
# define __CONTACT_H__

#include <iostream>
#include <string>

class Contact{

public:

	Contact() = default;
	~Contact()= default;
	
	// void setFirstName(const std::string& first_name) {m_first_name = first_name;}
	// void setLastName(const std::string& last_name) {m_last_name = last_name;}
	// void setNickname(const std::string& nickname) {m_nickname = nickname;}
	// void setPhonenumber(const std::string& phonenumber) {m_phonenumber = phonenumber;}
	// void setDarkestSecret(const std::string& darkest_secret) {m_darkest_secret = darkest_secret;}
	// void setIndexContact(int index) {m_index_contact = index;}
	
	// std::string getFirstName() {return m_first_name;}
	// std::string getLastname() {return m_last_name;}
	// std::string getNickname() {return m_nickname;}
	// std::string getPhonenumber() {return m_phonenumber;}
	// std::string getDarkestSecret() {return m_darkest_secret;}
	
	// int getIndexContact() {return m_index_contact;}

private:

	int			m_index_contact;
	
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phonenumber;
	std::string m_darkest_secret;
};

#endif