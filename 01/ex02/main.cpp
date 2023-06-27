#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////////////////
// reference -  alternative name / alias given to an existing var, 
// allows to create a new name that refers to the same memory location as the orig.var. 
//
// Once a REF is created, any changes made through the REF will affect the orig. var. & vice versa.
//
// REFs are often used as func. param. to pass variables by ref., 
// allowing modifications to be made directly to the orig. variable.
//
// REFs provide a more readable and convenient syntax compared to using PTRs in certain scenarios.
//
// unlike PTRs, REFs cannot be null or uninitialized => must be bound to an existing var. upon declaration
//
// REFs cannot be reassigned to refer to a different var. after initialization.
/////////////////////////////////////////////////////////////////////////////////////////////////////

// the reference stringREF is declared and initialized to reference the str variable.
// Any changes made through stringREF will affect the str variable, 
// and accessing stringREF will provide the same value as str.
int main() {
	// ---------------------- declare ----------------------------------
	// declares a string variable str initialized to "HI THIS IS BRAIN".
    std::string str = "HI THIS IS BRAIN";
	// declares a pointer stringPTR that points to the str variable
    std::string* stringPTR = &str;
	// declares reference stringREF that references the str variable
    std::string& stringREF = str;

    // ------------------ print the memory addresses --------------------
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // ---------------------- print the values ----------------------
    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl; // dereferenced PTR
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl; // REF is like a dereferenced PTR => don't need to add any symbol to access it

    return 0;
}
