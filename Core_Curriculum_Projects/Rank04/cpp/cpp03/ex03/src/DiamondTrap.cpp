#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name) {
    std::cout << "DiamondTrap Constructor called!" << std::endl;
    this->health = FragTrap::health;
    this->energy = ScavTrap::energy;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap Destructor called!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}