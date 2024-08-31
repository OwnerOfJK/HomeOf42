#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie destructor called" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
    Zombie zombie;
    zombie.name = name;
    return(&zombie);
}

void Zombie::randomChump( std::string name )
{
    Zombie zombie;
    zombie.name = name;
    zombie.announce();
}