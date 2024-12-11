/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:18:29 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 19:46:32 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal Constructor called!" << std::endl;
}

Animal::Animal(const Animal &src) {
    *this = src;
    std::cout << "Animal Copy Constructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    std::cout << "Animal Copy Assignment Operator called!" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called!" << std::endl;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}