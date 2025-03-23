#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & other) { 
	(void)other;
    std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & other) { 
	(void)other;
    std::cout << "Assignation operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    if (isSpecialValue(input)) { // Handle special values first
        printSpecialValue(input);
    } else if (isChar(input)) {
        char value = input[0];
        printResultsChar(value);
    } else if (isInt(input)) {
        long value = std::strtol(input.c_str(), NULL, 10);
        if (errno == ERANGE || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            std::cout << "int: impossible (overflow)" << std::endl;
        else
            printResultsInt(static_cast<int>(value));
    } else if (isFloat(input)) {
        float value = std::strtof(input.c_str(), NULL);
        printResultsFloat(value);
    } else if (isDouble(input)) {
        double value = std::strtod(input.c_str(), NULL);
        printResultsDouble(value);
    } else {
        std::cout << "Invalid input." << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& input) {
    return input.length() == 1 && isprint(input[0]) && !isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string& input) {
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+') i++;
    while (i < input.length()) {
        if (!isdigit(input[i])) return false;
        i++;
    }
    return !input.empty();
}

bool ScalarConverter::isFloat(const std::string& input) {
    if (input == "-inff" || input == "+inff" || input == "nanf") return true;
    size_t i = 0, dotCount = 0;
    if (input[i] == '-' || input[i] == '+') i++;
    while (i < input.length() - 1) { // Last char must be 'f'
        if (input[i] == '.') dotCount++;
        else if (!isdigit(input[i])) return false;
        i++;
    }
    return input[i] == 'f' && dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string& input) {
    if (input == "-inf" || input == "+inf" || input == "nan") return true;
    size_t i = 0, dotCount = 0;
    if (input[i] == '-' || input[i] == '+') i++;
    while (i < input.length()) {
        if (input[i] == '.') dotCount++;
        else if (!isdigit(input[i])) return false;
        i++;
    }
    return dotCount == 1;
}

bool ScalarConverter::isSpecialValue(const std::string& input) {
    return input == "nan" || input == "+inf" || input == "-inf" ||
           input == "nanf" || input == "+inff" || input == "-inff";
}

void ScalarConverter::printResultsChar(char value) {
    std::cout << "char: '" << value << "'\n";
    std::cout << "int: " << static_cast<int>(value) << "\n";
    std::cout << "float: " << formatFloat(static_cast<float>(value)) << "f\n";
    std::cout << "double: " << formatDouble(static_cast<double>(value)) << "\n";
}

void ScalarConverter::printResultsInt(int value) {
    printChar(value);
    std::cout << "int: " << value << "\n";
    std::cout << "float: " << formatFloat(static_cast<float>(value)) << "f\n";
    std::cout << "double: " << formatDouble(static_cast<double>(value)) << "\n";
}

void ScalarConverter::printResultsFloat(float value) {
    printChar(value);
    std::cout << "int: " << static_cast<int>(value) << "\n";
    std::cout << "float: " << formatFloat(value) << "f\n";
    std::cout << "double: " << formatDouble(static_cast<double>(value)) << "\n";
}

void ScalarConverter::printResultsDouble(double value) {
    printChar(value);
    std::cout << "int: " << static_cast<int>(value) << "\n";
    std::cout << "float: " << formatFloat(static_cast<float>(value)) << "f\n";
    std::cout << "double: " << formatDouble(value) << "\n";
}

void ScalarConverter::printChar(double value) {
    if (value >= 0 && value <= 127 && isprint(static_cast<int>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printSpecialValue(const std::string& input) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input == "nanf")
        std::cout << "float: nanf\n" << "double: nan\n";
    else if (input == "+inff")
        std::cout << "float: +inff\n" << "double: +inf\n";
    else if (input == "-inff")
        std::cout << "float: -inff\n" << "double: -inf\n";
    else if (input == "nan")
        std::cout << "float: nanf\n" << "double: nan\n";
    else if (input == "+inf")
        std::cout << "float: +inff\n" << "double: +inf\n";
    else if (input == "-inf")
        std::cout << "float: -inff\n" << "double: -inf\n";
}

//Float has 6-7 decimal precision, so it looses the fractions if too long.
std::string ScalarConverter::formatFloat(float value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(value == static_cast<int>(value) ? 1 : 6) << value;
    return oss.str();
}

std::string ScalarConverter::formatDouble(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(value == static_cast<int>(value) ? 1 : 6) << value;
    return oss.str();
}