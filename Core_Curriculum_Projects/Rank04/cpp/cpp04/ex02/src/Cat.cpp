/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:23:19 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 20:09:24 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->cat_brain = new Brain();
    std::cout << "Cat Constructor called!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
    this->cat_brain = new Brain(*src.cat_brain);
    std::cout << "Cat Copy Constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete this->cat_brain;
        this->cat_brain = new Brain(*rhs.cat_brain);
    }
    std::cout << "Cat Copy Assignment Operator called!" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->cat_brain;
    std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}