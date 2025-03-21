#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
    _name(name), _grade(grade) {
    if (grade < 1) {
        throw GradeTooLowException();
    } else if (grade > 150) {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat Input Constructor Called with grade: " << this->_grade << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor Called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade + 1 > 150) {
        throw GradeTooHighException();
    }
    this->_grade++;
    std::cout << "Grade incremented to: " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade - 1 < 1) {
        throw GradeTooHighException();
    }
    this->_grade--;
    std::cout << "Grade decremented to: " << this->_grade << std::endl; 
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b._name << ", bureaucrat grade " << b._grade << ".";
    return os;
}