#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
        MutantStack<T>& operator=(const MutantStack<T>& other) {
            std::stack<T>::operator=(other);
            return *this;
        };

        typedef typename std::stack<T>::container_type::iterator iterator;

        // This->c is how you're accessing the internal container
        // from within a class that inherits from std::stack.
        iterator begin() {
            return this->c.begin();
        };

        iterator end() {
            return this->c.end();
        };
};

#endif
