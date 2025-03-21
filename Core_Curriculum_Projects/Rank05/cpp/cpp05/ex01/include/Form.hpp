#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _signStatus;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;

    public:
        Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        const std::string& getName() const;
        bool getSignStatus() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form Grade is too low";
                }
        };

        void beSigned(const Bureaucrat &b);

    };

    std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif