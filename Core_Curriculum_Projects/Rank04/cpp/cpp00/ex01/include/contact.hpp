/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:20 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/31 16:56:28 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define Contact_HPP

#include <string>
#include <iostream>

class Contact {
public:
    int userID;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    int phoneNumber;
    std::string secret;
};

#endif