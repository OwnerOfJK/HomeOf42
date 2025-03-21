#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(): _name("default"), _signStatus(false), _gradeRequiredToSign(1), _gradeRequiredToExecute(1) {
    std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _signStatus(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signStatus(other._signStatus), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_signStatus = other._signStatus;
    }
    std::cout << "Form Copy Assignment Called" << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << "Form Destructor Called" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSignStatus() const {
    return _signStatus;
}

int Form::getGradeSign() const {
    return _gradeRequiredToSign;
}

int Form::getGradeExecute() const {
    return _gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    _signStatus = true;
}

std::ostream& operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getSignStatus() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeSign()
       << ", Grade required to execute: " << form.getGradeExecute();
    return os;
}