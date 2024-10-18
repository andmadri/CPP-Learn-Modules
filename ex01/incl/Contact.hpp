#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact{
public:
	Contact() = default;
	~Contact()= default;
	void setFirstName(const std::string& first_name) {m_first_name = first_name;}
	void setLastName(const std::string& last_name) {m_last_name = last_name;}
	void setNickname(const std::string& nickname) {m_nickname = nickname;}
	void setPhonenumber(const std::string& phonenumber) {m_phonenumber = phonenumber;}
	void setDarkestSecret(const std::string& darkest_secret) {m_darkest_secret = darkest_secret;}

private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phonenumber;
	std::string m_darkest_secret;
};

#endif