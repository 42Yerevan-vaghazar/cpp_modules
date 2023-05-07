#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string str;
    PhoneBook phoneBook(8);

    while (true) {
        std::cout << "Enter the command (ADD, SEARCH and EXIT)" << std::endl;
        if (!std::getline(std::cin, str))
            exit(0);
        if (!str.compare("EXIT")) {
            std::cout << "finish\n";
            break ;
        }
        else if (!str.compare("ADD")) {
            phoneBook.addContact();
        }
        else if (!str.compare("SEARCH")) {
            phoneBook.displayContacts();
        }
    }
    return (0);
}