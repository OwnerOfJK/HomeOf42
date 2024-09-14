#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), attack_damage(0) {
    std::cout << "ClapTrap Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        this->health = rhs.health;
        this->energy = rhs.energy;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energy <= 0)
        return;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->energy <= 0)
        return;
    std::cout << "ClapTrap " << this->name << " took " << amount << " damage!" << std::endl;
    this->health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy <= 0)
        return;
    std::cout << "ClapTrap " << this->name << " repaired " << amount << " health!" << std::endl;
    this->health += amount;
    this->energy -= 1;
}