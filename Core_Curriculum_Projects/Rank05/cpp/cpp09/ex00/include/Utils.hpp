#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>

inline bool stringToInt(const std::string& str, double& out) {
    std::istringstream iss(str);
    iss >> out;
    return !iss.fail() && iss.eof();
}

#endif
