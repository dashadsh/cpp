#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////////////////
// reference is an alternative name or alias given to an existing variable, 
// it allows you to create a new name that refers to the same memory location as the original variable. 
// Once a reference is established, any changes made through the reference will 
// affect the original variable, and vice versa.
//
// SIC!
// References are often used as function parameters to pass variables by reference, 
// allowing modifications to be made directly to the original variable.
//
// References provide a more readable and convenient syntax compared to 
// using pointers in certain scenarios.
//
// Unlike pointers, references cannot be null or uninitialized. 
// They must be bound to an existing variable upon declaration.
//
// References cannot be reassigned to refer to a different variable after initialization.
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
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
