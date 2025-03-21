#include <iostream>
#include "include/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat queen("queen", 200);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    Bureaucrat king("king", 2);
    try {
        king.incrementGrade();
        king.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << king << std::endl;

    try {
        Bureaucrat jack("jack", 150);
        jack.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}