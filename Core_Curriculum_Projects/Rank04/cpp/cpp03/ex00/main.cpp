#include "include/ClapTrap.hpp"

int main() {
    ClapTrap playerA("Jeff");
    ClapTrap playerB("John");
    ClapTrap playerC;

    playerA.attack("John");
    playerB.takeDamage(10);
    playerB.beRepaired(1);
}