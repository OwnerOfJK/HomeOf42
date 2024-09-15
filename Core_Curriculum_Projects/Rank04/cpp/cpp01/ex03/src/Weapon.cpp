/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:29 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 17:15:35 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}

const std::string &Weapon::getType() {
    return type;
}

void Weapon::setType(std::string weapon_name) {
    type = weapon_name;
}