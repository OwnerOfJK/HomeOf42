#include "../include/Span.hpp"

Span::Span() : _max(0), _count(0) {
    _data = new size_t[0];
    std::cout << "Default Constructor called!" << std::endl;
}

Span::Span(size_t max) : _max(max), _count(0){
    _data = new size_t[_max];
    std::cout << "Input Constructor called!" << std::endl;
}

Span::Span(const Span &other) : _max(other._max), _count(other._count) {
    _data = new size_t[_max];
    for (size_t i = 0; i < _count; i++) {
        _data[i] = other._data[i];
    }
    std::cout << "Copy Constructor called!" << std::endl;
}

Span& Span::operator=(const Span &other) {
    if (this != &other) {
        delete[] _data;
        if (_max != other._max)
            throw std::runtime_error("Incompatible max sizes in assignment");
        _data = new size_t[_max];
        _count = other._count;
        for (size_t i = 0; i < _count; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

Span::~Span() {
    delete[] _data;
    std::cout << "Destructor called!" << std::endl;
}

size_t Span::addNumber(size_t new_number) {
    if (_count >= _max)
        throw std::runtime_error("Span class data is full.");
    _data[_count++] = new_number;
    return (_count);
}

size_t Span::shortestSpan() {
    if (_count < 2)
        throw std::runtime_error("Less than 2 elements in the Span.");

    size_t* sorted = new size_t[_count];
    for (size_t i = 0; i < _count; i++)
        sorted[i] = _data[i];
    
    std::sort(sorted, sorted + _count);

    size_t min_span = sorted[1] - sorted[0];
    for (size_t i = 1; i < _count - 1; i++) {
        size_t diff = sorted[i + 1] - sorted[i];
        if (diff < min_span)
            min_span = diff;
    }

    delete[] sorted;
    return min_span;
}

size_t Span::longestSpan() {
    if (_count < 2)
        throw std::runtime_error("Less than 2 elements in the Span.");

    size_t min = _data[0];
    size_t max = _data[0];

    for (size_t i = 0; i < _count; i++) {
        if (min > _data[i])
            min = _data[i];
        if (max < _data[i])
            max = _data[i];
    }
    return (max - min);
}

size_t* Span::begin() {
    return (&_data[0]);
}

size_t* Span::end() {
    return (&_data[_count]);
}