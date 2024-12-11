/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:23:19 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 19:59:48 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat Constructor called!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
    *this = src;
    std::cout << "Cat Copy Constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "Cat Copy Assignment Operator called!" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}