#include "../inc/Serializer.hpp"

//  we need to store memory address of an obj and then 
// reconstruct the object from that address
int main() {
    // create instance of the SerializableData structure
    Data originalData;
    originalData.intValue = 42;
    originalData.stringValue = "hello_world";

    // serialize the originalData object
    uintptr_t serialized = Serializer::serialize(&originalData);

    // deserialize the serialized data into a new object
    Data* deserializedData = Serializer::deserialize(serialized);

    // print the original data, serialized data, deserialized content
	std::cout << std::endl;
    std::cout << "original data address: " << &originalData << std::endl;
    std::cout << "after serialization: " << deserializedData << std::endl;
    std::cout << "deserialized content: " << deserializedData->intValue << " " << deserializedData->stringValue << std::endl;
	std::cout << std::endl;

    return 0;
}
