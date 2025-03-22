#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("default_target") {
    std::cout << "Default RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!getSignStatus())
        throw NotSignedException();
    if (executor.getGrade() > getGradeExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;

    int success = std::rand() % 2;

    if (success) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}
