#include "../include/Utils.hpp"

void printVec(const std::vector<int> &vector) {
    if (vector.size() > 100) {
        std::cout << "Array is too large to display." << std::endl;
        return;
    }
    std::cout << "{";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << " " << vector[i];
    std::cout << " }";
    std::cout << std::endl;
}

void printList(const std::list<int> &lst) {
    if (lst.size() > 100) {
        std::cout << "Array is too large to display." << std::endl;
        return;
    }
    std::cout << "{";
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << " " << *it;
    std::cout << " }";
    std::cout << std::endl;
}

std::string isSortedV(const std::vector<int> &vector) {
    for (size_t i = 1; i < vector.size(); ++i) {
        if (vector[i] < vector[i - 1])
            return "Not correctly sorted😞";
    }
    return "Correctly sorted😊";
}

std::string isSortedL(const std::list<int> &lst) {
    std::list<int>::const_iterator it = lst.begin();
    int prev = *it;
    ++it;
    for (; it != lst.end(); ++it) {
        if (*it < prev)
            return "Not correctly sorted😞";
        prev = *it;
    }
    return "Correctly sorted😊";
}