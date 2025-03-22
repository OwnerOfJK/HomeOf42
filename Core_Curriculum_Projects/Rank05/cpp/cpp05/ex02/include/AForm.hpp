#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _signStatus;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;

    public:
        AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
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

        class NotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form has not been signed";
                }
        };

        virtual void execute(const Bureaucrat &executor) const = 0;

    };

    std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif