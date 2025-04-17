#include <vector>
#include <iostream>
#include "include/Find.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        int idx = easyfind(vec, 30);
        std::cout << "Found at index: " << idx << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
