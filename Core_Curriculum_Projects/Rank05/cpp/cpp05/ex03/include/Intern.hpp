#ifndef Intern_HPP
#define Intern_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <map>

class Intern {
    private:
        std::map<std::string, AForm*(Intern::*)(const std::string&)> formCreationMap;
        void initialiseMapping();
        AForm *createPresidentialPardonForm(const std::string &target);
        AForm *createShrubberyCreationForm(const std::string &target);
        AForm *createRobotomyRequestForm(const std::string &target);

    public:
        Intern();
        ~Intern();
        AForm *makeForm(const std::string &formName, const std::string &target);
    };

#endif