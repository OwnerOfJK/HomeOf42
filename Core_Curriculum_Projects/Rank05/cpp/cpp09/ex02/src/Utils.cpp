#include "../include/Utils.hpp"

void print_vector(const std::vector<int> &vector){
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