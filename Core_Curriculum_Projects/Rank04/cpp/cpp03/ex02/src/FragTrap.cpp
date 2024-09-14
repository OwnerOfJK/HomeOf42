#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called!" << std::endl;
    this->health = 100;
    this->energy = 100;
    this->attack_damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Positive high fives request from FragTrap!" << std::endl;
}