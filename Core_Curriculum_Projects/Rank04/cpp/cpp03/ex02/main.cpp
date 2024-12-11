/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:55:39 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 17:55:40 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int main() {
    ClapTrap playerA("Jeff");
    ClapTrap playerB("John");

    playerA.attack("John");
    playerB.takeDamage(10);
    playerB.beRepaired(1);

    ScavTrap playerC("Robot");
    playerC.attack("Jeff");
    playerC.guardGate();

    FragTrap playerD("Joe");
    FragTrap playerE("Will");
    playerD.highFivesGuys();
    playerE = playerD;

    FragTrap playerX;
}