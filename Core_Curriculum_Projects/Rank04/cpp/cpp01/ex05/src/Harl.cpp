#include "../include/Harl.hpp"

void Harl::debug() {
    std::cout << "AHHHH THIS IS A DEBUG" << std::endl;
}

void Harl::info() {
    std::cout << "AHHHH THIS IS A INFO" << std::endl;
}

void Harl::warning() {
    std::cout << "AHHHH THIS IS A WARNING" << std::endl;
}

void Harl::error() {
    std::cout << "AHHHH THIS IS A ERROR" << std::endl;
}

void Harl::complain(std::string level) {
    // void: This is the return type of the member functions.
    // (Harl::*...): This indicates that we're dealing with pointers to member functions of the Harl class.
    // complaints[4]: This is the name of the array, which will hold 4 elements.
    // (void): This specifies that the member functions take no arguments.
    void (Harl::* complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->* complaints[i])();
            return;
        }
    }
    std::cout << "Invalid complaint level" << std::endl;
}