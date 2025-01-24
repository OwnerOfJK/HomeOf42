#include <iostream.h>
#include "headers/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 0);  // Invalid grade, will throw GradeTooHighException
    } catch (std::exception& e) {  // Catch any exception derived from std::exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 200);  // Invalid grade, will throw GradeTooLowException
    } catch (std::exception& e) {  // Catch any exception derived from std::exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}