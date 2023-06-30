
/* ---------------------------------------------------------------------------
From now on, all your classes must be designed in the Orthodox Canonical Form, 
unless explicitely stated otherwise. 
Then, they will implement the four required member functions below:
• Default constructor
• Copy constructor
• Copy assignment operator • Destructor
Split your class code into two files. 

The header file (.hpp/.h) contains the class definition 
whereas the source file (.cpp) contains the implementation.
-----------------------------------------------------------------------------*/
#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
