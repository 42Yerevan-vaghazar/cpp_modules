#pragma once
#include <iostream>
#include "utils.hpp"

class Contact
{
	public:
		Contact();
		Contact(int index);
		~Contact();
		void display() const;
		void display(char c) const;
		void setIndex(int index);
		int getIndex(void) const;
		void setFirstName(std::string firstName);
		std::string getFirstName(void) const;
		void setLastName(std::string lastName);
		std::string getLastName(void) const;
		void setNickname(std::string nickname);
		std::string getNickname(void) const;
		void setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret(void) const;
		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber(void) const;
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_darkestSecret;
		std::string m_phoneNumber;
		int	m_index;
		void printMember(std::string member, char c) const;
		void printMember(std::string member, std::string memberName) const;
};
