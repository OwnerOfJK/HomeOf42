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

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->dog_brain = new Brain();
    std::cout << "Dog Constructor called!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    this->dog_brain = new Brain(*src.dog_brain);
    std::cout << "Dog Copy Constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete this->dog_brain;
        this->dog_brain = new Brain(*rhs.dog_brain);
    }
    std::cout << "Dog Copy Assignment Operator called!" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->dog_brain;
    std::cout << "Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}