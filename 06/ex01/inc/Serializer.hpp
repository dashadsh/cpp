// Serializer.h
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
// #include <cstdint>
// #include <string>

// simple data structure that can be serialized
struct SerializableData {
    int intValue;
    std::string stringValue;
};

// lass to perform serialization & deserialization
class Serializer {
	private:   
        Serializer();
        ~Serializer();
        Serializer(Serializer   const &src);

        Serializer   &operator=(Serializer   const &src);

	public:
   		// Serialize a SerializableData object into a uintptr_t
   		static uintptr_t serialize(SerializableData* ptr);

    	// Deserialize a uintptr_t back into a SerializableData pointer
    	static SerializableData* deserialize(uintptr_t raw);
};

#endif