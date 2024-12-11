/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:54:52 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 17:54:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int main() {
    ClapTrap playerA("Jeff");
    ClapTrap playerB("John");
    ClapTrap playerC;

    playerA.attack("John");
    playerB.takeDamage(10);
    playerB.beRepaired(1);
}