#include <iostream>
#include "include/Bureaucrat.hpp"

int main() {
    Bureaucrat king("king", 149);
    try {
        Bureaucrat queen("queen", 200);
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try {
        king.incrementGrade();
        king.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jack("jack", 1);
        jack.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    Bureaucrat alice("Alice", 42);
    std::cout << alice << std::endl;

    return 0;
}