#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
    std::string name;
    int health;
    int energy;
    int attack_damage;

    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);
    ClapTrap &operator=(const ClapTrap &rhs);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

