#include "../inc/Serializer.hpp"

# include "../inc/Serializer.hpp"

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