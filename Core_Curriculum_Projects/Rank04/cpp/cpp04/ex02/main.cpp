/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaller <jkaller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:23:53 by jkaller           #+#    #+#             */
/*   Updated: 2024/09/15 19:14:48 by jkaller          ###   ########.fr       */
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

    // Delete all animals
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    // Test for leaks as per the example
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    return 0;
}