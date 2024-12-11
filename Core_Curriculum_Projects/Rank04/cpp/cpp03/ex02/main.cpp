#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int main() {
    ClapTrap playerA("Jeff");
    ClapTrap playerB("John");

    playerA.attack("John");
    playerB.takeDamage(10);
    playerB.beRepaired(1);

    ScavTrap playerC("Robot");
    playerC.attack("Jeff");
    playerC.guardGate();

    FragTrap playerD("Joe");
    FragTrap playerE("Will");
    playerD.highFivesGuys();
    playerE = playerD;

    FragTrap playerX;
}