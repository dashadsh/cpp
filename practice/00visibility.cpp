#include <iostream>

// Why do we have const in void public_func(void) const; 
// and void private_func(void) const;?
//
// The const keyword after the function declaration specifies that this is a constant member function. 
// A constant member function doesn't modify any non-static data members of the class. 
// It means that inside these functions (public_func and private_func), 
// you cannot change any member variables of the object for which they are called.
//
// For instance, if you tried to assign a new value to public_int or private_int 
// inside either public_func or private_func, you would get a compiler error because those functions 
// are declared as const. This is a way to guarantee that a function does not modify the state of an object.
class Sample
{
public:
	Sample(void);
	~Sample(void);
	int public_int;
	void public_func(void) const;

private:
	// use _ prefix for all private identifier
	// it gives reader a quick idea of which is public or private
	int private_int;
	void private_func(void) const;
};

// this can also be written with initialisation list
Sample::Sample(void)
{
	std::cout << "constructor called" << std::endl;

	this->public_int = 0;
	std::cout << "this->public_int = " << this->public_int <<std::endl;
	this->private_int = 0;
	std::cout << "this->private_int = " << this->private_int <<std::endl;

	this->public_func();
	this->private_func();
	// this->public_func(); and this->private_func(); were called in the constructor 
	// to demonstrate that you can call other member functions from within a constructor 
	// (or indeed, any other member function). 
	// However, if you don't need to perform the actions within these functions at the time 
	// of object construction, you can certainly omit these calls.
	return;
}

Sample::~Sample(void)
{
	std::cout << "destructor called" << std::endl;
	return;
}

void	Sample::public_func(void) const
{
	std::cout << "public_func called" << std::endl;
	return;
}

void	Sample::private_func(void) const
{
	std::cout << "private_func called" << std::endl;
	return;
}

int	main(void)
{
	Sample	instance;

	instance.public_int = 42;
	std::cout << "instance.public_int = " << instance.public_int << std::endl;
	// compilation error when you want to access private attributes
	// instance.private_int = 42;
	// std::cout << "instance.private_int = " << instance.private_int << std::endl;

	instance.public_func();
	// compilation error when you want to access private function
	// instance.private_func();

	return (0);
}