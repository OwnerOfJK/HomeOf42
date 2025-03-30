#ifndef Functions_HPP
#define Functions_HPP

#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

template <typename T> 
class Array {
    private:
        T*   _data;
        size_t _size;

    public:
        Array();
        Array(size_t size);
        Array(const Array<T> &other);
        Array<T>& operator=(const Array<T>& other);
        ~Array();
        void display() const;
        size_t size() const;

        class outOfBounds : public std::exception {
            public:
              const char* what() const throw() {
                  return "Index is out of bounds!";
              }
            };

        T &operator[](const int index);
        const T& operator[](int index) const;
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)  {
    std::cout << "Default Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t size) : _size(size) {
    _data = new T[size];  // Allocate memory
    std::cout << "Input Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size){
    _data = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
    std::cout << "Copy Constructor Called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        T* newData = new T[other._size];
        for (size_t i = 0; i < other._size; i++) {
            newData[i] = other._data[i];
        }
        delete[] _data;
        _data = newData;
        _size = other._size;
    }
    std::cout << "Copy Assignment Operator Called" << std::endl;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
    std::cout << "Destructor Called" << std::endl;
}

template <typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < _size; ++i)
        std::cout << _data[i] << " ";
    std::cout << std::endl;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(_size)) {
        throw outOfBounds();
    }
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(_size)) {
        throw outOfBounds();
    }
    return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}

#endif