#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <sstream>

class ScalarConverter {
public:
    static void convert(const std::string& input);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter & other);
    ScalarConverter & operator = (const ScalarConverter & other);
    ~ScalarConverter();
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isSpecialValue(const std::string& input);
    static void printResultsChar(char value);
    static void printResultsInt(int value);
    static void printResultsFloat(float value);
    static void printResultsDouble(double value);
    static void printChar(double value);
    static void printSpecialValue(const std::string& input);
    static std::string formatFloat(float value);
    static std::string formatDouble(double value);
};