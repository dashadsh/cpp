#include "../inc/Identity.hpp"
// Dynamic Casting: to identify the actual type of an object at runtime. 
// DC llows to check & convert ptrs and references to classes 
// up and down the class hierarchy. 
// commonly used for runtime type identification.

// Type Identification w/o Typeinfo: use dynamic casting and custom mechanisms 
// for type identification

int main() {

	Base* ptr;

    // generate random obj & store it as a Base pointer
	   	ptr = generate();
    // create a reference to the generated object
	    Base& refr = *ptr;
    // identify object's type using a ptr
  		identify(ptr);
    // identify object's type using a ref
    	identify(refr);
    // clean up dynamically allocated object!!!
    	delete ptr;
    
    return 0;
}