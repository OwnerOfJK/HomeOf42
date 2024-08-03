/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:22 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/03 23:26:03 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

// Constructor implementation
Contact::Contact(int userID,
                 const std::string& firstName,
                 const std::string& lastName,
                 const std::string& nickName,
                 int phoneNumber,
                 const std::string& secret)
    : userID_(userID), 
      firstName_(firstName),
      lastName_(lastName),
      nickName_(nickName),
      phoneNumber_(phoneNumber),
      secret_(secret) {}

// Destructor implementation
Contact::~Contact() {}

void Contact::displayContact() const {
        std::cout << "ID: " << userID_ << "\n"
        << "Name: " << firstName_ << " " << lastName_ << "\n"
        << "Nickname: " << nickName_ << "\n"
        << "Phone: " << phoneNumber_ << "\n"
        << "Secret: " << secret_ << std::endl;
}