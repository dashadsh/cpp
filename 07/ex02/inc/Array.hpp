#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

//	https://isocpp.org/wiki/faq/templates#class-templates

// class template Array that contains elements of type T 
// and that implements the following behavior and functions:
// !!! 4 You MUST use the operator new[] to allocate memory. 
/// Preventive allocation (allocating memory in advance) is forbidden. 
// Your program must never access non-allocated memory.
template < class T >
class Array {
	private:
	    unsigned int	_size;
		T	*_array;

    public:
   		// constructor: creates an empty arr.
		Array(); 

		// constructor: creates an arr. of n elem. initialized by default
		Array(unsigned int n);

		// copy constructor: creates a copy of the original arr.
		Array(const Array &src);

		// destructor: cleans up allocated memory
        ~Array();

		// assignment operator: assigns one arr. to another
		Array &operator=(const Array &src);

		// subscript operator: allows accessing elements with []
		T &operator[](unsigned int index);

		// member function: returns nb. of elements in the arr.,
    	// takes no parameter and doesn't modify current instance.
		unsigned int	size(void);

   		// member function: prints elements in the arr.
		void    printArrayElements(void);

    	// exception class for out-of-range idx access.
        class OutOfRangeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};      
};

#endif
