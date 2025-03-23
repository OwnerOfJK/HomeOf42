#ifndef Serializer_HPP
#define Serializer_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int value;
};

class Serializer {
    private:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    

};

#endif