#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <vector>

class Span {
    private:
        size_t*         _data;
        const size_t    _max;
        size_t          _count;

    public:
        Span();
        Span(size_t max);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        size_t addNumber(size_t new_number);
        size_t shortestSpan();
        size_t longestSpan();
        size_t* begin();
        size_t* end();

        size_t getMax() { return _max; };
        size_t getCount() { return _count; };

        template<typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            for (InputIterator it = begin; it != end; ++it) {
                if (_count >= _max)
                    throw std::runtime_error("Span is full, cannot add more numbers.");
                _data[_count++] = *it;
            }
        }
};

#endif