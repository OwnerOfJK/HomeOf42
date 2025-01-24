#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const noexcept override {
                return "Grade too high!";
            }
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const noexcept override {
                return "Grade too low!";
            }
        };
};

#endif