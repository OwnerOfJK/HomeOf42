#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif