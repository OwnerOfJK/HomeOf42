#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        void execute(const Bureaucrat &executor) const;
};

#endif