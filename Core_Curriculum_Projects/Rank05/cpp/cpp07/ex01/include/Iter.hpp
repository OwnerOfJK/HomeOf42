#ifndef Functions_HPP
#define Functions_HPP

#include <stdint.h>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F func) {
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

void add_one(int &n) {
    n++;
}

template <typename T>
void print_element(const T &elem) {
    std::cout << elem << " ";
}

#endif