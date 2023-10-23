#include "../inc/Serializer.hpp"

// reinterpret_cast is one of the C++ casting operators, 
// and it's used for low-level type conversions where you need to 
// re-interpret or cast a pointer or data from one type to another, 
// even if the resulting behavior is implementation-dependent or undefined. 
// It is the most powerful and potentially dangerous of the C++ casts.

// Some key points about reinterpret_cast:

// It performs a bitwise type conversion, meaning it treats the object or pointer 
// as a sequence of bits and changes the type without considering the original 
// object's structure or semantics.
// reinterpret_cast can be used for pointer-to-pointer conversions, 
// casting pointers to integers, and vice versa.
// It is not subject to the usual type safety checks performed by other casting operators, 
// and it may lead to undefined behavior if used incorrectly.
// reinterpret_cast should be used sparingly and only in situations where you need 
// to work with low-level memory representation or when interfacing with external code 
// that relies on specific memory layouts.

// int number = 42;
// int* numberPtr = &number;
// uintptr_t intPtrValue = reinterpret_cast<uintptr_t>(numberPtr); // Casting a pointer to an integer
// int* newNumberPtr = reinterpret_cast<int*>(intPtrValue); // Casting an integer back to a pointer


Serializer::Serializer() {
    std::cout << "serializer default constructir is called.\n";
}

Serializer::~Serializer() {
    std::cout << "Serializer destructor is called.\n";
}

Serializer::Serializer(Serializer   const &src) {
    *this = src;
}

Serializer  &Serializer::operator=(Serializer   const &src) {
    std::cout << "Serializer copy assignment is called.\n"; 
    (void)src;   
    return (*this);
}

// convert a pointer to SerializableData into a uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
	// uses reinterpret_cast operator to 
	// reinterpret ptr as a uintptr_t.
	// it converts memory address of the object into integer.
    return reinterpret_cast<uintptr_t>(ptr);
	// uintptr_t   address = reinterpret_cast<uintptr_t>(ptr);
    // return (address);
}
// When to use it:
// when we want to serialize an object, 
// which involves converting object+its data into a format that can be 
// stored or transmitted. 
// storing memory address in the form of a uintptr_t allows us later to 
// reconstruct object by converting the uintptr_t back into a pointer.

// convert a uintptr_t back into a SerializableData pointer
Data* Serializer::deserialize(uintptr_t raw) {
	// uses reinterpret_cast operator to 
	// reinterpret the uintptr_t value raw as a ptr to a Data object. 
	// It reconstructs pointer from the integer representation.
    return reinterpret_cast<Data *>(raw);
	// SerializableData *tmp = reinterpret_cast<Data *>(raw);
    // return (tmp);
}
// When to use it:
// when we want to deserialize an object, 
// which involves converting previously serialized data back into an object. 
// By converting uintptr_t back into a ptr, we can work with the original
// object in memory.