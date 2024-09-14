#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
    this->health = FragTrap::health;
    this->energy = ScavTrap::energy;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "Default DiamondTrap Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    this->health = FragTrap::health;
    this->energy = ScavTrap::energy;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src) ,FragTrap(src)  {
    *this = src;
    std::cout << "DiamondTrap Copy Constructor called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name + "_clap_name";
        this->health = rhs.health;
        this->energy = rhs.energy;
        this->attack_damage = rhs.attack_damage;
    }
    std::cout << "DiamondTrap Copy Assignment Operator called!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}