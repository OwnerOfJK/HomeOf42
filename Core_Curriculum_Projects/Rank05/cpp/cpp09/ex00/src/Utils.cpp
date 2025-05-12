#include "../include/Utils.hpp"

bool stringToInt(const std::string& str, double& out) {
    std::istringstream iss(str);
    iss >> out;
    return !iss.fail() && iss.eof();
}