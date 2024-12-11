/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:23:53 by jkaller           #+#    #+#             */
/*   Updated: 2024/12/11 20:52:00 by jkaller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"

int main() {
    const int arraySize = 10;
    Animal* animals[arraySize];

    // Fill the array with Dogs and Cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Test deep copy
    Dog* originalDog = new Dog();
    Dog* copiedDog = new Dog(*originalDog);
    delete originalDog;
    copiedDog->makeSound(); // This should work if it's a deep copy
    delete copiedDog;

    // Delete all animals
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    // Test for leaks as per the example
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    // Cat *cat1 = new Cat();
    // cat1->makeSound();
    // cat1->setIdea("Climb a tree");
    // cat1->setIdea("Chase a mouse");
    // cat1->setIdea("Nap in the sun");
    // std::cout << cat1->getIdea(0) << std::endl;
    // std::cout << cat1->getIdea(1) << std::endl;
    // delete cat1;

    return 0;
}