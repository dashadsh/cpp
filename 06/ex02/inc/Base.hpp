#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>

class Base {
    public:
        virtual ~Base(); // public virtual destructor ONLY
		// - this is required for polymorphism
};

// Defininig three empty classes that inherit from  Base class
// class A:public Base {};
// class B:public Base {};
// class C:public Base {};

// generate a random instance of A, B, or C as a Base pointer
Base *generate(void);
// identify the type of an object using a pointer
void identify(Base *p);
// identify the type of an object using a reference
void identify(Base &p);

#endif
