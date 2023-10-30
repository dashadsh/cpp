#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// default constructor
template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {
	std::cout << "default array constructor called" << std::endl;
}

// parameterized constructor
template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {
	std::cout << "parameterized array constructor called" << std::endl;
}

// copy constructor
template <typename T>
Array<T>::Array(const Array &copy) : _size(copy._size), _array(new T[copy._size]) {
	std::cout << "array copy constructor called" << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

// destructor
template <typename T>
Array<T>::~Array(void){
	std::cout << "array destructor called" << std::endl;
	delete[] _array;
}

// assignment operator
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

// subscript operator
template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index < 0 || index > (this->_size - 1))
		throw OutOfRangeException();
	return (this->_array[index]);
}

// member function to get the size
template <typename T>
unsigned int    Array<T>::size(void) {
	return (this->_size);
}

// member function to print array elements
template <class T>
void Array<T>::printArrayElements() {
    for (unsigned int i = 0; i < _size; ++i) {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
// template <typename T>
// void	Array<T>::printArrayElements(void) {
// 	unsigned int i = -1;

// 	if (_size == 0)
// 		std::cout << "array is empty" << std::endl;
// 	else {
// 		while (++i < this->size()) {
// 			if (i != this->size() - 1)
// 				std::cout << _array[i] << " - ";
// 			else
// 				std::cout << _array[i] << std::endl;
// 		}		
// 	}
// }

// exception message for out-of-range index access
template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
	return ("array idx is out of range");
}

#endif
