/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:56:15 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 17:56:16 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamondTrap.hpp"

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

    DiamondTrap diamond("Diamond");
    diamond.whoAmI();
    diamond.attack("Target");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond.highFivesGuys();

    DiamondTrap dt1;
    DiamondTrap dt2("Diamond");
    dt1.whoAmI();
    dt2.whoAmI();

    return 0;
}