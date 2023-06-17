#include <iostream>

// Member attributes / functions are present inside of a class. 
// It means that the class needs to be instantiated, 
// in order to use this attribute / function. 
// Each attribute will be different in each instance

// Non member variables and functions exist at the class level, 
// and not at the instance level
class Sample {
public:
	Sample(void);
	~Sample(void);
	// non member function
	// when the function does not have anything to do with the other class
	// functions, but you want it to be part of the class
	static int getNbInst(void);

private:
	// non member attribute
	// number of instances: this information only makes sense at the class level
	static int _nbInst;
};

Sample::Sample(void) {
	std::cout << "constructor called" << std::endl;
	Sample::_nbInst += 1;
	return;
}

Sample::~Sample(void) {
	std::cout << "destructor called" << std::endl;
	Sample::_nbInst -= 1;
	return;
}

// With member function, CPP will pass as a parameter, an instance of your class
// so this-> can be used

// this pointer is not passed for a non member function, so you can't
// use this-> here
int	Sample::getNbInst(void) {
	return Sample::_nbInst;
}

// this is the only way to initialise a non member attribute (static attribute)
// this is initialised without an instance being created
int	Sample::_nbInst = 0;
void f0(void) {
	Sample instance;
	std::cout << "Number of instances = " << instance.getNbInst() << std::endl;
	return;
}

void f1(void) {
	Sample instance;
	std::cout << "Number of instances = " << instance.getNbInst() << std::endl;
	f0();
	return;
}

int main(void) {
	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;
	return 0;
}

// The key learning point here is about static members of a class in C++. 
// Static members are shared across all instances of the class and 
// can also be accessed even when no instances of the class have been created, 
// which is particularly useful for keeping track of the number of instances of the class.

// Both the function getNbInst() and the variable _nbInst are indeed members of the Sample class, 
// but they are "static" members.