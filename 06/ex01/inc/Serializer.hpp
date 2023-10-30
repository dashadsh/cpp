#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>  // uintptr_t - C standart, can be used with C++98
// #include <cstdint> // uintptr_t  - C 99 standart
// #include <string>

// simple data structure that can be serialized
struct Data {
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
   		// Serialize a SerializableData object into a uintptr_t:
		// takes a pointer and converts it to the unsigned integer type uintptr_t.
   		static uintptr_t serialize(Data* ptr);

		// takes an unsigned integer parameter and converts it to a pointer to Data.
    	// Deserialize a uintptr_t back into a SerializableData pointer
    	static Data* deserialize(uintptr_t raw);
};

#endif

// uintptr_t is an int in C and C++ that is designed to store
// value of a memory address as an unsigned int
