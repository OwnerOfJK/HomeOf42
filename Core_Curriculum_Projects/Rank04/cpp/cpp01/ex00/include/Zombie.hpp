/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:58 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/12 18:12:59 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

    private:
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif