#include <iostream>

class Sample {
public:
	Sample(void);
	~Sample(void);

	int	getdata(void) const;
	void setdata(int v);

private:
	int	_data;
};

Sample::Sample(void) {
	std::cout << "constructor called" << std::endl;

	this->setdata(0);
	std::cout << "this->getdata() = " << this->getdata() << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "destructor called" << std::endl;
	return;
}

// grant only read-only access to the attribute
int	Sample::getdata(void) const {
	// return a copy of the _data attribute
	return this->_data;
}

// this way allows the user to change the _data attribute
void	Sample::setdata(int v) {
	// don't allow _data to have a negative value
	if (v >= 0)
		this->_data = v;
	return;
}

int	main(void) {
	Sample	instance;

	instance.setdata(42);
	std::cout << "instance.getdata() = " << instance.getdata() << std::endl;
	instance.setdata(-42);
	std::cout << "instance.getdata() = " << instance.getdata() << std::endl;

	return 0;
}