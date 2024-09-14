#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called!" << std::endl;
    this->health = 100;
    this->energy = 50;
    this->attack_damage = 20;
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