/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:55:49 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 17:55:50 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, virtual public ScavTrap {
    public:
    DiamondTrap();  // Default constructor
    DiamondTrap(std::string name);  // Parameterized constructor
    DiamondTrap(const DiamondTrap &src);  // Copy constructor
    DiamondTrap &operator=(const DiamondTrap &rhs);  // Copy assignment operator
    ~DiamondTrap();  // Destructor

    using ScavTrap::attack;
    void whoAmI();

    private:
    std::string name;
};

#endif