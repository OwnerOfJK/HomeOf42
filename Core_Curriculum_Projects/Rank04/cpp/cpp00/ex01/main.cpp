/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:25 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/31 16:57:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/phoneBook.hpp"
#include <iostream>
#include <string>

void createContact(PhoneBook& phoneBook) {
    Contact newContact;
    std::cout << "Enter First Name: ";
    std::getline(std::cin, newContact.firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, newContact.lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, newContact.nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, newContact.phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, newContact.secret);
    if (!newContact.firstName.empty() && !newContact.lastName.empty() &&
        !newContact.nickName.empty() && !newContact.phoneNumber.empty() &&
        !newContact.secret.empty()) {
        phoneBook.addContact(newContact);
        std::cout << "Contact added successfully." << std::endl;
    } else {
        std::cout << "Error: All fields must be filled." << std::endl;
    }
}

void searchContact(const PhoneBook& phoneBook) {
    phoneBook.displayContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    phoneBook.displayContact(index);
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD") {
            createContact(phoneBook);
        } else if (command == "SEARCH") {
            searchContact(phoneBook);
        } else if (command == "EXIT") {
            std::cout << "Exiting program. All contacts will be lost." << std::endl;
            phoneBook.exitBook();
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}