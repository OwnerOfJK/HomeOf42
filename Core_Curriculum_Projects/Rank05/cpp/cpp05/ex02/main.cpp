#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

// Test 1: Test ShrubberyCreationForm
void testShrubberyCreationForm() {
    Bureaucrat bob("Bob", 150); // Bureaucrat with grade 150, too low to sign and execute
    Bureaucrat alice("Alice", 130); // Bureaucrat with grade 140, can sign but not execute

    ShrubberyCreationForm form("home");

    // Test if form is not signed
    assert(!form.getSignStatus());

    // Test signing
    bob.signForm(form);
    assert(form.getSignStatus() == false); // Bob cannot sign (grade too low)

    alice.signForm(form);
    assert(form.getSignStatus() == true); // Alice can sign the form

    // Test executing
    try {
        bob.executeForm(form);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    alice.executeForm(form); // Alice can execute now, test if file is created
    std::ifstream file("home_shrubbery");
    assert(file.is_open()); // Check if file exists
    file.close();
}

// Test 2: Test RobotomyRequestForm
void testRobotomyRequestForm() {
    Bureaucrat bob("Bob", 50); // Bob can sign and execute
    RobotomyRequestForm form("home");

    // Test if form is not signed
    assert(!form.getSignStatus());

    // Test signing
    bob.signForm(form);
    assert(form.getSignStatus() == true);

    // Test execution
    try {
        bob.executeForm(form); // This should make a success or failure message
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Test 3: Test PresidentialPardonForm
void testPresidentialPardonForm() {
    Bureaucrat bob("Bob", 10); // Bob can sign and execute
    Bureaucrat zaphod("Zaphod", 5); // Zaphod can execute the pardon form
    PresidentialPardonForm form("Jacky");

    // Test if form is not signed
    assert(!form.getSignStatus());

    // Test signing
    bob.signForm(form);
    assert(form.getSignStatus() == true);

    // Test execution
    try {
        bob.executeForm(form); // This should print a pardon message
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    zaphod.executeForm(form); // Zaphod executes the pardon
}

// Main test function
int main() {
    std::cout << "Running tests for ShrubberyCreationForm...\n";
    testShrubberyCreationForm();

    std::cout << "\nRunning tests for RobotomyRequestForm...\n";
    testRobotomyRequestForm();

    std::cout << "\nRunning tests for PresidentialPardonForm...\n";
    testPresidentialPardonForm();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
