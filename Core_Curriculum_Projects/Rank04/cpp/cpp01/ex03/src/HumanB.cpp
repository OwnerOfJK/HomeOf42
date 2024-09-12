/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:23 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 18:25:48 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(Weapon("")) {
    
}

void HumanB::attack() {
    
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = weapon;
}