#include "../inc/Serializer.hpp"

//  we need to store memory address of an obj and then 
// reconstruct the object from that address
int main() {
    // create instance of the SerializableData structure
    Data originalData;
    originalData.intValue = 42;
    originalData.stringValue = "hello";

    // serialize the originalData object
    uintptr_t serialized = Serializer::serialize(&originalData);

    // deserialize the serialized data into a new object
    Data* deserializedData = Serializer::deserialize(serialized);

    // print the original data, serialized data, deserialized content
    std::cout << "original data address: " << &originalData << std::endl;
    std::cout << "after serialization: " << deserializedData << std::endl;
    std::cout << "deserialized content: " << deserializedData->intValue << " " << deserializedData->stringValue << std::endl;

    // additional tests with a different data obj
    Data additionalData;
    additionalData.intValue = 24;
    additionalData.stringValue = "world";

    uintptr_t serializedAdditional = Serializer::serialize(&additionalData);
    Data* deserializedAdditional = Serializer::deserialize(serializedAdditional);

    // print original data, serialized data, and deserialized content for additionalData
    std::cout << "\nadditional data - Original data address: " << &additionalData << std::endl;
    std::cout << "after serialization: " << deserializedAdditional << std::endl;
    std::cout << "deserialized content: " << deserializedAdditional->intValue << " " << deserializedAdditional->stringValue << std::endl;

    return 0;
}