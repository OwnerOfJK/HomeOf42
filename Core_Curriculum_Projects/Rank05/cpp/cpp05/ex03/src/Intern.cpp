#include "../include/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default Constructor Called" << std::endl;
    initialiseMapping();}

Intern::~Intern() {
    std::cout << "Intern Destructor Called" << std::endl;
}

void Intern::initialiseMapping() {
    formCreationMap["PresidentialPardonForm"] = &Intern::createPresidentialPardonForm;
    formCreationMap["ShrubberyCreationForm"] = &Intern::createShrubberyCreationForm;
    formCreationMap["RobotomyRequestForm"] = &Intern::createRobotomyRequestForm;
    std::cout << "Forms Mapping created." << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target){
    std::map<std::string, AForm*(Intern::*)(const std::string&)>::iterator it = formCreationMap.find(formName);
    if (it != formCreationMap.end()) {
        AForm *form = (this->*it->second)(target);
        std::cout << "Intern created " << form->getName() << std::endl;
        return form;
    } else {
        std::cout << "Form " << formName << " does not exist!" << std::endl;
        return NULL;
    }
}

AForm *Intern::createPresidentialPardonForm(const std::string &target){
    AForm *newForm = new PresidentialPardonForm(target);
    std::cout << "Intern created " << newForm->getName() << std::endl;
    return (newForm);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target){
    AForm *newForm = new ShrubberyCreationForm(target);
    std::cout << "Intern created " << newForm->getName() << std::endl;
    return (newForm);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target){
    AForm *newForm = new RobotomyRequestForm(target);
    std::cout << "Intern created " << newForm->getName() << std::endl;
    return (newForm);
}

