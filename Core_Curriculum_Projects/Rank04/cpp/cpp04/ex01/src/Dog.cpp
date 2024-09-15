/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:22:11 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 19:02:59 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    const Brain *dog_brain = new Brain();
    std::cout << "Dog Constructor called!" << std::endl;
}

Dog::Dog(const Dog &src) {
    *this = src;
    std::cout << "Dog Copy Constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "Dog Copy Assignment Operator called!" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete dog_brain;
    std::cout << "Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}