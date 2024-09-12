/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:33 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 18:17:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanA.hpp"
#include "include/HumanB.hpp"
#include "include/Weapon.hpp"

int main() {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    return 0;
}