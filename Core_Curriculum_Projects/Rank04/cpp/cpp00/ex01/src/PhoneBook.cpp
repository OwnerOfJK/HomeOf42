/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:27 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 16:02:06 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() {
    currentIndex = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::addContact(const Contact &contact) {
    if (currentIndex >= MAX_CONTACTS)
        currentIndex = 0;
    contacts[currentIndex] = contact;
    currentIndex++;
}

void PhoneBook::exitBook() const {
    std::cout << "Exiting phone book..." << std::endl;
    std::exit(0);
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (!contacts[i].firstName.empty()) {
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << truncate(contacts[i].firstName) << "|"
                      << std::setw(10) << truncate(contacts[i].lastName) << "|"
                      << std::setw(10) << truncate(contacts[i].nickName) << std::endl;
        }
    }
}

void PhoneBook::displayContact(int index) const {
    if (index >= 0 && index < MAX_CONTACTS && !contacts[index].firstName.empty()) {
        std::cout << "First Name: " << contacts[index].firstName << std::endl;
        std::cout << "Last Name: " << contacts[index].lastName << std::endl;
        std::cout << "Nickname: " << contacts[index].nickName << std::endl;
        std::cout << "Phone Number: " << contacts[index].phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].secret << std::endl;
    } else {
        std::cout << "Invalid index or empty contact." << std::endl;
    }
}

std::string PhoneBook::truncate(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}