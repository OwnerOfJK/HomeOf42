#include "include/Harl.hpp"
#include <iostream>

int main(){
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("invalid");
    return (0);
}