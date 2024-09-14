#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default ScavTrap Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called!" << std::endl;
    this->health = 100;
    this->energy = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->health = rhs.health;
        this->energy = rhs.energy;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energy <= 0)
        return;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy -= 1;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}