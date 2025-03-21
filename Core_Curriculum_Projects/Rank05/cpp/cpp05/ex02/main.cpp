#include <iostream>
#include "include/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat king("King", 50);
        Form formA("Form A", 100, 150);
        Form formB("Form B", 10, 20);

        std::cout << formA << std::endl;
        king.signForm(formA); // Should succeed
        std::cout << formA << std::endl;

        std::cout << formB << std::endl;
        king.signForm(formB); // Should fail because the grade is too low
        std::cout << formB << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}