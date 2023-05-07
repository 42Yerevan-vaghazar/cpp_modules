#include "Contact.hpp"
#include <iostream>
#include <string>
#define GET_VARIABLE_NAME(Variable) (#Variable)

Contact::Contact() {};

Contact::Contact(int index) : m_index(index) {};

Contact::~Contact() {};

void Contact::printMember(std::string member, char c) const {
	int	n = member.length();
	for (int i = 0; n + i < 10; i++) {
		std::cout << ' ';
	}
	for (int i = 0; i < n; i++) {
		if (i == 9 && member.length() > 10) {
			std::cout << '.';
			break ;
		}
		std::cout << member[i];
	}
	std::cout << c;
};

void Contact::printMember(std::string member, std::string memberName) const {
	std::cout << memberName << " - " << member << std::endl;
};

void Contact::display() const {
	printMember(std::to_string(m_index), GET_VARIABLE_NAME(m_index) + 2);
	printMember(m_firstName, GET_VARIABLE_NAME(m_firstName) + 2);
	printMember(m_lastName, GET_VARIABLE_NAME(m_lastName) + 2);
	printMember(m_nickname, GET_VARIABLE_NAME(m_lastName) + 2);
};

void Contact::display(char c) const {
	printMember(std::to_string(m_index), c);
	printMember(m_firstName, c);
	printMember(m_lastName, c);
	printMember(m_nickname, c);
	std::cout << std:: endl;
};

void Contact::setIndex(int index) {
	m_index = index;
};

int Contact::getIndex(void) const {
	return (m_index);
};

void Contact::setFirstName(std::string firstName) {
	m_firstName = firstName;
};

std::string Contact::getFirstName(void) const {
	return (m_firstName);
};

void Contact::setLastName(std::string lastName) {
	m_lastName = lastName;
};

std::string Contact::getLastName(void) const {
	return (m_lastName);
};

void Contact::setNickname(std::string nickname) {
	m_nickname = nickname;
};

std::string Contact::getNickname(void) const {
	return (m_nickname);
};

void Contact::setDarkestSecret(std::string darkestSecret) {
	m_darkestSecret = darkestSecret;
};

std::string Contact::getDarkestSecret(void) const {
	return (m_darkestSecret);
};

void Contact::setPhoneNumber(std::string phoneNumber) {
	m_phoneNumber = phoneNumber;
};

std::string Contact::getPhoneNumber(void) const {
	return (m_phoneNumber);
};