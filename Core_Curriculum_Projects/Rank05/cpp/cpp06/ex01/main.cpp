#include "include/Serializer.hpp"

//The whole idea is serialization is to convert a data structure into a format that can be easily stored and reconstructed later.
//After being serialized we can easily senc the data and then deserializer after to access the original data.

int main() {
    // Example usage
    Data data;
    data.value = 42;

    // Serialize the pointer
    uintptr_t serializedData = Serializer::serialize(&data);
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized Data address: " << serializedData << std::endl;

    // Deserialize the pointer
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Return value: " << deserializedData << std::endl;
    std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;

    return 0;
}