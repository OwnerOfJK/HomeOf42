#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default_target") {
    std::cout << "Default ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getSignStatus())
        throw NotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile) {
        std::cout << "File cannot be opened!" << std::endl;
        return;
    }

    outfile << "      /\\      \n"
            << "     /  \\     \n"
            << "    /    \\    \n"
            << "   /______\\   \n"
            << "     ||||     \n";

            outfile.close();
    std::cout << executor.getName() << " has executed " << getName() << " on " << _target << "!\n" << std::endl;
}
