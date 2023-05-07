#pragma once
#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(int maxContacts);
		~PhoneBook();
		void addContact();
		void displayContacts() const ;
	private:
		int	m_maxContacts;
		int	m_curIndex;
		int m_size;
		Contact m_contacts[8];
};
