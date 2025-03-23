#include "include/Base.hpp"
#include <string>
#include <cstdlib>

Base *generate() {
    srand((unsigned int)time(NULL)); // make sure randomness is different each time.
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "A instance created" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "B instance created" << std::endl;
        return new B();
    } else {
        std::cout << "C instance created" << std::endl;
        return new C();
    }
    return (NULL);
}

void identify(Base *p) {
    // Attempt to cast the pointer to each derived class using dynamic_cast.
    //A dynamic cast of a pointer is either the type or NULL.
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p)
{
    //A dynamic cast of a reference is either the object or an exception.
	Base a;
	Base b;
	Base c;

	try {
		a = dynamic_cast<A&> (p);
		std::cout << "A" << std::endl;
	} catch(std::exception & e){
    }
	try {
		b = dynamic_cast<B&> (p);
		std::cout << "B" << std::endl;
	} catch(std::exception & e){
    }
	try {
		c = dynamic_cast<C&> (p);
		std::cout << "C" << std::endl;
	} catch(std::exception & e){
    }
}

int main()
{
	Base * ptr = generate();
	Base * ref = generate();

	identify(ptr);
	identify(*ref);
	delete ptr;
	delete ref;
	return (0);
}