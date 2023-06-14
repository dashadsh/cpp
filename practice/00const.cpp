#include <iostream>

class Sample
{
public:
	float const pi;
	int nbr;

	Sample(float const f);
	~Sample(void);

	// const between ) & ; -> the instance of the class will never be altered
	void public_function(void) const;
};

// it's not assigning f value to pi attribute
// it's initialising pi attribute to the f value
Sample::Sample(float const f) : pi(f), nbr(42) {
	std::cout << "constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "destructor called" << std::endl;
	return;
}

// this is central to CPP
// define const when your member function should never be changed in the \
// current instance of your class
void	Sample::public_function(void) const {

	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->nbr << std::endl;

	// this assignment below won't work, as it's a const function
	// this->qd = 0;
	return;
}

int main() {

	Sample instance(3.14f);

	instance.public_function();

	return 0;
}