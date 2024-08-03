/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:59:25 by jkaller           #+#    #+#             */
/*   Updated: 2024/08/03 23:19:43 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/contact.hpp"

int main(void)
{
    Contact user(1, "John", "Doe", "Johnny", 1234567890, "Loves coding");
    user.displayContact();
}