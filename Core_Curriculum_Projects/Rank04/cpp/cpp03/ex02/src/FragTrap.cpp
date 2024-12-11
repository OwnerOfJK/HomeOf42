#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
    std::cout << "FragTrap Default Constructor called!" << std::endl;
    this->health = 100;
    this->energy = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called!" << std::endl;
    this->health = 100;
    this->energy = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->health = rhs.health;
        this->energy = rhs.energy;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Positive high fives request from FragTrap!" << std::endl;
}