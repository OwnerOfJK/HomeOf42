/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:53:01 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 19:03:10 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();
    void makeSound() const;

    private:
    Brain *dog_brain;
};

#endif