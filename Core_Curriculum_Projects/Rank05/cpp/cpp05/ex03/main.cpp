#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

// Main test function
int main() {
    Intern bob;
    AForm *form;
    form = bob.makeForm("PresidentialPardonForm", "John");
    Bureaucrat king("king", 1);
    king.signForm(*form);
    king.executeForm(*form);

    form = bob.makeForm("Not found!", "John");
    return 0;
}
