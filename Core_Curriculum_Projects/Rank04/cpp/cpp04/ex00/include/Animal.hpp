/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:53:09 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 19:54:13 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
    Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);
    virtual ~Animal();
    const std::string &getType() const;
    virtual void makeSound() const; //allows function to be overriden

    protected:
    std::string type;
};

#endif