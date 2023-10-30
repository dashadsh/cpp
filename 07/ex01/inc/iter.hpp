#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/*
T is place holder for data type

VOID function template takes 3 parameters:
1. address of an array, 
2. length of the array, 
3. function that's called on every element of the array.
*/

// T: type of elements in the arr.
// const &ptr: function will not modify the elements of the arr.
template < typename T >
void    iter(T *arrayAdress, size_t len, void (*f)(T const &ptr)) {
    size_t 	i = 0;

	while (i < len) {
		f(arrayAdress[i]);
		i++;
	}
}

template < typename T >
void    myPrint(T const &x) { // takes constant refr to a value of data type T
    std::cout << x << std::endl;
}

#endif
