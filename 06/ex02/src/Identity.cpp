#include "../inc/Identity.hpp"

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

// identify the type of an object using a pointer
void identify(Base *p) {
    A   *Aptr = dynamic_cast<A *>(p);
    B   *Bptr = dynamic_cast<B *>(p);
    C   *Cptr = dynamic_cast<C *>(p);
    if (Aptr)
        std::cout << Aptr << "orig. type: A" << std::endl;
    else if (Bptr)
        std::cout << Bptr << "orig. type: B" << std::endl;
    else if (Cptr)
        std::cout << Cptr << "orig. type: C" << std::endl;
    else
        std::cout << "cast failed" << std::endl;
}

// identify the type of an object using a reference
void identify(Base &p)
{
    try { // Attempt to cast the reference to an A object
        A   &Aptr = dynamic_cast<A &>(p);
        std::cout << &Aptr << "orig. type: A" << std::endl;
    }
    catch(std::exception &e) {
        try { // Attempt to cast the reference to an B object
            B   &Bptr = dynamic_cast<B &>(p);
            std::cout << &Bptr << "orig. type: B" << std::endl;
        }
        catch(std::exception &e) {
            try { // Attempt to cast the reference to an C object
                C   &Cptr = dynamic_cast<C &>(p);
                std::cout << &Cptr << "orig. type: C" << std::endl;
            }
            catch(const std::exception& e) {
				// if none of the casts succeed, object is not A, B, or C
                std::cerr << e.what() << "object is not of type A, B, or C" << std::endl;
            }
        }
    }
}