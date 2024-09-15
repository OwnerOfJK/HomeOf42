/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:03:55 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 19:04:37 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor called!" << std::endl;
}

Brain::Brain(const Brain &src) {
    *this = src;
    std::cout << "Brain Copy Constructor called!" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "Brain Copy Assignment Operator called!" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called!" << std::endl;
}