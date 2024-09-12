/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 18:18:33 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    public:
    HumanB(std::string name);
    void attack();
    void setWeapon(Weapon &weapon);

    private:
    std::string name;
    Weapon weapon;
};

#endif