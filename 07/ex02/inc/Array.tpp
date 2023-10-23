#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/*
Utilizing ".tpp" Files for Templated Functions and Classes
Separation of Interface and Implementation:
When working with templated functions and classes, it's often desirable to maintain a 
clear separation between the interface (the declarations) and the implementation (the definitions) 
of these templates. This separation helps improve code organization and readability.

Avoiding "Gory" Implementation Details:
The implementation of templated functions and classes can be complex and involve intricate details 
specific to the template's behavior. By placing this implementation in a separate file with a ".tpp" 
extension, you keep the interface file (typically a header file) cleaner and focused on the 
high-level descriptions of the template's structure and usage. 
This separation isolates the "gory" implementation details from users of the template, 
making it easier to understand and work with.

Templates Cannot Go in ".cpp" Files:
In C++, templates require the definition of the functions or classes to be available at compile time. 
Therefore, you cannot place the complete implementation of a templated function or class in a separate ".cpp" 
file as you would with non-templated functions or classes. 
This is because the compiler needs to see the implementation details to generate code for the specific types 
used with the template. However, you don't want to include the full implementation in the header file, 
so the ".tpp" extension is used to indicate that these files contain the implementation for templated code.

Conventions and ".cpp" Files:
While it is technically possible to use a ".cpp" extension for the implementation files of templates, 
doing so goes against common conventions in C++ development. ".cpp" files are typically reserved for the 
implementation of non-templated code, whereas ".tpp" is a naming convention used to signify that a file 
contains the implementation of templated functions and classes. Using ".tpp" is a way to signal to other 
developers that the file contains template-specific code.

In summary, ".tpp" files are employed when implementing templated functions and classes in C++ to separate the 
interface from the implementation, hide complex details, and follow established naming conventions. 
While it's technically possible to use ".cpp" for templated code, ".tpp" is a more recognized and meaningful 
choice within the C++ community.
*/

// constructors
template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {
	std::cout << "default array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {
	std::cout << "parameterized array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : _size(copy._size), _array(new T[copy._size]) {
	std::cout << "array copy constructor called" << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array(void){
	std::cout << "array destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
	std::cout << "array copy assignment operator called" << std::endl;
	this->_size = src._size;
	if (_array != NULL)
		delete [] _array;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index < 0 || index > (this->_size - 1))
		throw OutOfRangeException();
	return (this->_array[index]);
}

template <typename T>
unsigned int    Array<T>::size(void) {
	return (this->_size);
}

template <typename T>
void	Array<T>::printArrayElements(void) {
	unsigned int i = -1;

	if (_size == 0)
		std::cout << "array is empty" << std::endl;
	else {
		while (++i < this->size()) {
			if (i != this->size() - 1)
				std::cout << _array[i] << " - ";
			else
				std::cout << _array[i] << std::endl;
		}		
	}
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
	return ("idx is out of range");
}

#endif
