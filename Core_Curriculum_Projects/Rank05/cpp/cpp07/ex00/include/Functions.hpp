#ifndef Functions_HPP
#define Functions_HPP

#include <stdint.h>
#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    const T tmp = a;
    a = b;
    b = tmp;
};

template<typename T>
const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

#endif