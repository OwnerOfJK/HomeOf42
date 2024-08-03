/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:20 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/03 23:57:08 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.hpp
#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iostream>

class Contact {
public:
    Contact(int userId,
            const std::string& firstName,
            const std::string& lastName,
            const std::string& nickName,
            int phoneNumber,
            const std::string& secret);  // Constructor
    ~Contact(); // Destructor

    void displayContact() const;

    private:
    int userID_;
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    int phoneNumber_;
    std::string secret_;
};

#endif // Contact_HPP