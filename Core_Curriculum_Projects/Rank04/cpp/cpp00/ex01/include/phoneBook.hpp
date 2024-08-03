/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:18 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/03 23:56:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <string>
#include <map>
#include "contact.hpp"

class PhoneBook {
public:
    PhoneBook();  // Constructor
    ~PhoneBook(); // Destructor

    void addContact(const Contact& contact);
    Contact getContact(int userId) const;
    void exitBook();

    private:
    std::vector<Contact> contacts_
};

#endif // PhoneBook_HPP
