#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(int maxContacts) : m_maxContacts (maxContacts), m_curIndex(0), m_size(0) {};

PhoneBook::~PhoneBook() {};


void PhoneBook::addContact(void) {
	std::string tmpStr;

	if (m_size < m_maxContacts)
		m_size++;
	if (m_curIndex == m_maxContacts)
		m_curIndex = 0;
	m_contacts[m_curIndex].setIndex(m_curIndex);
	std::cout << "Enter firts name" << std:: endl;
	if (!std::getline(std::cin, tmpStr))
		exit(0);
	m_contacts[m_curIndex].setFirstName(tmpStr);
	std::cout << "Enter last name" << std:: endl;
	if (!std::getline(std::cin, tmpStr))
		exit(0);
	m_contacts[m_curIndex].setLastName(tmpStr);
	std::cout << "Enter nickname name\n";
	if (!std::getline(std::cin, tmpStr))
		exit(0);
	m_contacts[m_curIndex].setNickname(tmpStr);
	while (true) {
		std::cout << "Enter phone number name\n";
		if (!std::getline(std::cin, tmpStr))
			exit(0);
		if (isAllDigit(tmpStr) == false) {
			std::cout << "invalid phone number, pleas enter valid one" << std::endl;
			continue ;
		} else {
			break ;
		}
	}
	m_contacts[m_curIndex].setPhoneNumber(tmpStr);
	std::cout << "Enter darkest secret name\n";
	if (!std::getline(std::cin, tmpStr))
		exit(0);
	m_contacts[m_curIndex].setDarkestSecret(tmpStr);
	m_curIndex++;
};

void PhoneBook::displayContacts() const {
	std::string	inputStr;
	int			inputNum;
	if (this->m_size == 0) {
		std::cout << "There is not contact yet" << std::endl;
		return ;
	}
	for (int i = 0; i < this->m_size ; i++)
		m_contacts[i].display('|');
	std::cout << "Enter the index of contact" << std::endl;
	if (!std::getline(std::cin, inputStr))
		exit(0);
	try {
		inputNum = std::stoi(inputStr);
	}
	catch(...){
		std::cout << "The index is out of range" << std::endl;
		return ;
	}
	if (inputNum < 0
		|| inputNum >= m_size) {
		std::cout << "The index is out of range" << std::endl;
		return ;
	}
	m_contacts[inputNum].display();
};
