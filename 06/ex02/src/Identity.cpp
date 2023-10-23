#include "../inc/Identity.hpp"

// dynamic_cast:
// runtime type cast operator primarily used in the context of polymorphism and inheritance.
// It is used for safely converting pointers or references of base classes to derived classes.
// dynamic_cast checks if the conversion is valid by examining the actual type 
// of the object at runtime and returns a null pointer if the conversion is not safe.
// It requires that the base class has at least one virtual function to enable 
// runtime type identification (RTTI).
// It is most commonly used when you need to determine the actual type of an object
// and perform operations accordingly, especially in polymorphic scenarios.

// Base* basePtr = new Derived();
// Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
// if (derivedPtr != nullptr) {
//     // The dynamic_cast was successful; derivedPtr points to a Derived object.
// } else {
//     // The dynamic_cast failed; basePtr does not point to a Derived object.
// }

Base::~Base() {
    std::cout << "base destructor called" << std::endl;
}

// generate a random instance of A, B, or C as a Base pointer
Base *generate(void) {
    time_t t;
    Base *ptr;
	// generate random number based on the current time
    switch(time(&t) % 3) {
        case 0: // create an instance of class A
            ptr = new A;
            std::cout << "type A created" << std::endl;
            break;
        case 1: // create an instance of class B
            ptr = new B;
            std::cout << "Type B created" << std::endl;
            break;
        case 2: // create an instance of class C
            ptr = new C;
            std::cout << "Type C created" << std::endl;
            break;
    }
    return (ptr);
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// identify the type of an object using a pointer
void identify(Base *p) {
    A   *Aptr = dynamic_cast<A *>(p);
    B   *Bptr = dynamic_cast<B *>(p);
    C   *Cptr = dynamic_cast<C *>(p);
    if (Aptr)
        std::cout << Aptr << " - pointer of type: A" << std::endl;
    else if (Bptr)
        std::cout << Bptr << " - pointer of type: B" << std::endl;
    else if (Cptr)
        std::cout << Cptr << " - pointer of type: C" << std::endl;
    else
        std::cout << " - cannot identify pointer type" << std::endl;
}

// Using a pointer inside this function is forbidden.
// identify the type of an object using a reference
// we use dynamic_cast with references and catch std::bad_cast exceptions 
// to handle cases where the reference is not of the expected type. 
void identify(Base &p)
{
    try { // Attempt to cast the reference to an A object
        A   &Aptr = dynamic_cast<A &>(p);
        std::cout << &Aptr << " - reference of type: A" << std::endl;
    }
    catch(std::exception &e) {
        try { // Attempt to cast the reference to an B object
            B   &Bptr = dynamic_cast<B &>(p);
            std::cout << &Bptr << " - reference of type: B" << std::endl;
        }
        catch(std::exception &e) {
            try { // Attempt to cast the reference to an C object
                C   &Cptr = dynamic_cast<C &>(p);
                std::cout << &Cptr << " - reference of type: C" << std::endl;
            }
            catch(const std::exception& e) {
				// if none of the casts succeed, object is not A, B, or C
                std::cerr << e.what() << " - cannot identify reference type" << std::endl;
            }
        }
    }
}

// //USING POINTERS:
// void identify(Base& p) {
//     if (dynamic_cast<A*>(&p)) {
//         std::cout << "Object type: A" << std::endl;
//     } else if (dynamic_cast<B*>(&p)) {
//         std::cout << "Object type: B" << std::endl;
//     } else if (dynamic_cast<C*>(&p)) {
//         std::cout << "Object type: C" << std::endl;
//     } else {
//         std::cerr << "Object is not of type A, B, or C" << std::endl;
//     }
// }