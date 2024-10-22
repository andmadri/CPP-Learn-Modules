#include "../incl/Contact.hpp"

void Contact::setFirstName(const std::string& first_name) {
    m_first_name = first_name;
}

void Contact::setLastName(const std::string& last_name) {
    m_last_name = last_name;
}

void Contact::setNickname(const std::string& nickname) {
    m_nickname = nickname;
}

void Contact::setPhonenumber(const std::string& phonenumber) {
    m_phonenumber = phonenumber;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
    m_darkest_secret = darkest_secret;
}

void Contact::setIndexContact(int index) {
    m_index_contact = index;
}

std::string Contact::getFirstName() const {
    return m_first_name;
}

std::string Contact::getLastname() const {
    return m_last_name;
}

std::string Contact::getNickname() const {
    return m_nickname;
}

std::string Contact::getPhonenumber() const {
    return m_phonenumber;
}

std::string Contact::getDarkestSecret() const {
    return m_darkest_secret;
}

int Contact::getIndexContact() const {
    return m_index_contact;
}
