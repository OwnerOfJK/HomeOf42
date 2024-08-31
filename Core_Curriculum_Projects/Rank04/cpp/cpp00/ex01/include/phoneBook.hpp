/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:18 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/31 17:01:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <array>
#include "contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void addContact(const Contact &contact);
    void exitBook() const;
    void displayContacts() const;
    void displayContact(int index) const;
    std::string truncate(const std::string& str) const;

private:
    static const int MAX_CONTACTS = 8;
    std::array<Contact, MAX_CONTACTS> contacts;
    int currentIndex;
};

#endif
