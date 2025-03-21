#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getSignStatus())
        throw std::runtime_error("Form is not signed.");
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();

    std::ofstream outFile(getTarget() + "_shrubbery");
    outFile << "ASCII Trees:\n";
    outFile << "       &&& &&  & &&\n";
    outFile << "    && &\\/&\\|&|&&/&\\&&\n";
    outFile << "   &\\/&|&&\\/&\\&&&&&&&\\&&\n";
    outFile << "   &&/&&&&&&&&&&&&&&&\\\n";
    outFile.close();
    std::cout << "Shrubbery created at " << getTarget() + "_shrubbery" << std::endl;
}
