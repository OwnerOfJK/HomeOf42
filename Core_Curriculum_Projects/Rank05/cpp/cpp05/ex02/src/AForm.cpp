#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signStatus(false), _gradeRequiredToSign(1), _gradeRequiredToExecute(1) {
    std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _signStatus(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signStatus(other._signStatus), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->_signStatus = other._signStatus;
    }
    std::cout << "AForm Copy Assignment Called" << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm Destructor Called" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSignStatus() const {
    return _signStatus;
}

int AForm::getGradeSign() const {
    return _gradeRequiredToSign;
}

int AForm::getGradeExecute() const {
    return _gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    _signStatus = true;
}

std::ostream& operator<<(std::ostream &os, const AForm &form) {
    os << "AForm: " << form.getName() << ", Signed: " << (form.getSignStatus() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeSign()
       << ", Grade required to execute: " << form.getGradeExecute();
    return os;
}