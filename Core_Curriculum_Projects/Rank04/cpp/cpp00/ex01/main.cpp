/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:25 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 16:03:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"
#include <iostream>
#include <string>

void createContact(PhoneBook& PhoneBook) {
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
        PhoneBook.addContact(newContact);
        std::cout << "Contact added successfully." << std::endl;
    } else {
        std::cout << "Error: All fields must be filled." << std::endl;
    }
}

void searchContact(const PhoneBook& PhoneBook) {
    PhoneBook.displayContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    if (!(std::cin >> index)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }
    std::cin.ignore(1000, '\n');
    PhoneBook.displayContact(index);
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