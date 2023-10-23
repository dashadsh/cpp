#include "../inc/Identity.hpp"

int main() {
    // generate random obj & store it as a Base pointer
    Base* ptr = generate();
    
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