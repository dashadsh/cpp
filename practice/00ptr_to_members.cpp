#include <iostream>

class Sample {
public:

	int foo;

	Sample(void);
	~Sample(void);

	void bar(void) const;
};

// constructor Sample::Sample() initializes foo to 0 and prints a message to the console. 
Sample::Sample(void) : foo(0) {
	std::cout << "constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "destructor called" << std::endl;
	return;
}

// simple function that prints a message to the console.
void Sample::bar(void) const {
	std::cout << "member function bar called" << std::endl;
	return;
}


// first creates an object of the class Sample, called instance, 
// on the stack. 
// Then, it creates a pointer instancep to this object.

int main(void) {
    // Create an instance of the Sample class on the stack.
    Sample instance;

    // Declare a pointer variable, instancep, and initialize it to the address of the Sample instance.
    Sample *instancep = &instance;

    // Declare a pointer-to-member-variable for the Sample class.
    // This pointer will be used to access the 'foo' member variable of a Sample instance.
    int Sample::*p = NULL;

    // Declare a pointer-to-member-function for the Sample class.
    // This pointer will be used to access the 'bar' member function of a Sample instance.
    void (Sample::*f)(void) const;

    // Point 'p' to the 'foo' member variable of the Sample class.
    // Note that 'p' doesn't point to a specific instance's 'foo', but rather the 'foo' variable in any instance of Sample.
    p = &Sample::foo;

    // Print the initial value of 'foo'.
    std::cout << "Value of member foo = " << instance.foo << std::endl;

    // Change the value of 'foo' in the 'instance' object to 21 using the '.*' operator.
    instance.*p = 21;
    std::cout << "Value of member foo = " << instance.foo << std::endl;

    // Change the value of 'foo' in the object pointed to by 'instancep' to 42 using the '->*' operator.
    instancep->*p = 42;
    std::cout << "Value of member foo = " << instance.foo << std::endl;

    // Point 'f' to the 'bar' member function of the Sample class.
    // Similar to 'p', 'f' doesn't point to a specific instance's 'bar', but rather the 'bar' function in any instance of Sample.
    f = &Sample::bar;

    // Call the 'bar' function on the 'instance' object using the '.*' operator.
    (instance.*f)();

    // Call the 'bar' function on the object pointed to by 'instancep' using the '->*' operator.
    (instancep->*f)();
    return 0;
}
