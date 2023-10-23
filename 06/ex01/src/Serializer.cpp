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
uintptr_t Serializer::serialize(SerializableData* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
	// uintptr_t   address = reinterpret_cast<uintptr_t>(ptr);
    // return (address);
}

// convert a uintptr_t back into a SerializableData pointer
SerializableData* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<SerializableData*>(raw);
	// SerializableData *tmp = reinterpret_cast<Data *>(raw);
    // return (tmp);
}
