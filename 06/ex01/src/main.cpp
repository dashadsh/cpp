#include "../inc/Serializer.hpp"

int main() {
    // create instance of the SerializableData structure
    SerializableData originalData;
    originalData.intValue = 42;
    originalData.stringValue = "hello";

    // serialize the originalData object
    uintptr_t serialized = Serializer::serialize(&originalData);

    // deserialize the serialized data into a new object
    SerializableData* deserializedData = Serializer::deserialize(serialized);

    // print the original data, serialized data, deserialized content
    std::cout << "Original data address: " << &originalData << std::endl;
    std::cout << "After serialization: " << deserializedData << std::endl;
    std::cout << "Deserialized content: " << deserializedData->intValue << " " << deserializedData->stringValue << std::endl;

    // additional tests with a different data obj
    SerializableData additionalData;
    additionalData.intValue = 99;
    additionalData.stringValue = "world";

    uintptr_t serializedAdditional = Serializer::serialize(&additionalData);
    SerializableData* deserializedAdditional = Serializer::deserialize(serializedAdditional);

    // print original data, serialized data, and deserialized content for additionalData
    std::cout << "\nAdditional data - Original data address: " << &additionalData << std::endl;
    std::cout << "After serialization: " << deserializedAdditional << std::endl;
    std::cout << "Deserialized content: " << deserializedAdditional->intValue << " " << deserializedAdditional->stringValue << std::endl;

    return 0;
}