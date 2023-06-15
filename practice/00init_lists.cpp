#include <iostream>

class Sample {
public:
	//attributes
	char a1;
	int a2;
	float a3;
	Sample(char p1, int p2, float p3);
	~Sample(void);
};

//initialise the attributes in a class
Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
// The syntax : a1(p1), a2(p2), a3(p3) just after the constructor declaration  is called the member initialization list. 
// This is where you initialize the class attributes. 
// The member initializer lists provide a way to initialize class data members when an instance of the class is created.
// It is generally more efficient to initialize a class data member in this way rather than using 
// assignment statements in the body of the constructor.
// The member initializer list in Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) 
// initializes a1 with p1, a2 with p2, and a3 with p3.
	std::cout << "constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

// //initialise the attributes in a class
// Sample::Sample(char p1, int p2, float p3)
// {
// 	this->a1 = p1;
// 	this->a2 = p2;
// 	this->a3 = p3;

// 	std::cout << "Constructor called" << std::endl;
// 	std::cout << "this->a1 = " << this->a1 << std::endl;
// 	std::cout << "this->a2 = " << this->a2 << std::endl;
// 	std::cout << "this->a3 = " << this->a3 << std::endl;
// }

Sample::~Sample(void) {
	std::cout << "destructor called" << std::endl;
	return;
}

int	main(void) {
	Sample instance('a', 42, 4.2f);
	return (0);
}