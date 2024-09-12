#include "include/Zombie.hpp"

int main()
{
    // Stack allocation
    std::cout << "Creating zombie on stack:" << std::endl;
    randomChump("Stack Zombie");

    // Heap allocation
    std::cout << "\nCreating zombie on heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // Delete heap-allocated zombie
    delete heapZombie;

    return 0;
}