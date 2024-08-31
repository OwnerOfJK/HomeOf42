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
#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <string>
#include <map>
#include "contact.hpp"

class PhoneBook {
public:
    void addContact(const Contact& contact);
    Contact searchContact(int userId) const;
    void exitBook();

    private:
    std::map<int, Contact> contacts;
};

#endif // PhoneBook_HPP
