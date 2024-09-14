#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif