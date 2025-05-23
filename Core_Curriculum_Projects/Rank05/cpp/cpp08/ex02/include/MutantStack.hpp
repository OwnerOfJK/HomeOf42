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
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        
        // This->c is how you're accessing the internal container
        // from within a class that inherits from std::stack.
		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const {
			return this->c.rend();
		}
};

#endif
