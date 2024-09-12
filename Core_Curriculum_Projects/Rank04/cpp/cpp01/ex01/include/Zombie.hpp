/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:52 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 18:12:53 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

    private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif