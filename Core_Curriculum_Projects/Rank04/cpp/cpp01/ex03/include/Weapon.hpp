/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:13:16 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 17:15:29 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    public:
    Weapon(std::string type);
    const std::string &getType();
    void setType(std::string weapon_name);

    private:
    std::string type;
};

#endif