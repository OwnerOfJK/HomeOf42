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

#include "include/contact.hpp"

int main(void)
{
    Contact user;
    user.userID = 1;
    user.firstName = "John";
    user.lastName = "Doe";
    user.nickName = "JD";
    user.phoneNumber = 1234567890;
    user.secret = "I am a secret";
}