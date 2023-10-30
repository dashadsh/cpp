#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/*
function template:

template<typename T>
void swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}
instead of: void swap(int& x, int& y)

T is place holder for data type

avoid compicated codes for different data types
(floats, longs, Strings, Sets, and FileSystems,...) 
with almost identical code except for the type !

https://isocpp.org/wiki/faq/templates 
*/

// !!! typename T is a template parameter that acts as a placeholder for the input data type !!!
// not a CONST bc. purpose of function is to MODIFY values:
template <typename T>
void swap(T &a, T &b) {
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
// T min(const T a, const T b) {
T min(const T &a, const T &b) { // avoid creating copies!!! use refs
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
// T max(const T a, const T b) {
	T max(const T &a, const T &b) { // avoid creating copies!!! use refs
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
