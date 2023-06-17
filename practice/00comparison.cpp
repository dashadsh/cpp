#include <iostream>


class Sample
{
public:
	Sample(int v);
	~Sample(void);

	int	getData(void) const;
	// taking as a parameter (the address of a sample instance). Making a
	// comparison between the current instance and the passed parameter instance
	int	compare(Sample *other) const ;

private:
	int	_data;
};

Sample::Sample(int v) : _data(v) // Sample instance1(42); we can construct it immideately like this
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample::getData(void) const
{
	return this->_data;
}

int	Sample::compare(Sample *other) const
{
	if (this->_data < other->getData())
		return (-1);
	else if (this->_data > other->getData())
		return (1);
	return (0);
}

int	main(void)
{
	// physically different but structurally identical instances
	Sample instance1(42);
	Sample instance2(42);

	if (&instance1 == &instance1)
		std::cout << "instance 1 and instance 1 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance 1 are not physically equal" << std::endl;

	if (&instance1 == &instance2)
		std::cout << "instance 1 and instance 2 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance 2 are not physically equal" << std::endl;

	if (instance1.compare(&instance1) == 0)
		std::cout << "instance 1 and instance 1 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance 1 are not structurally equal" << std::endl;

	if (instance1.compare(&instance2) == 0)
		std::cout << "instance 1 and instance 2 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance 2 are not structurally equal" << std::endl;

	return (0);
}