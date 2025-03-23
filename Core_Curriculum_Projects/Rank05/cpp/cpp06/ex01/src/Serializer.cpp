#include "../include/Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer & other) { 
    (void)other;
    std::cout << "Copy constructor called" << std::endl;
}

Serializer & Serializer::operator = (const Serializer & other) { 
    (void)other;
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
