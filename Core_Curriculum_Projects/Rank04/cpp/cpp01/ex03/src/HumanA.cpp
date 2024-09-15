/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:19 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 17:21:18 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
    this->name = name;
    this->weapon = &weapon;
    std::cout << "HumanA constructed with name " << name << " and weapon type " << weapon.getType() << std::endl;
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}