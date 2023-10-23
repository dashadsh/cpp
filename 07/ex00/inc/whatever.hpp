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
instead of: 

void swap(int& x, int& y)

avoiding long codes for different data types (floats, longs, Strings, Sets, and FileSystems,...) 
with almost identical code except for the type.
Every time using swap() with a given pair of types, the compiler will go to the above definition 
and will create yet another “template function” as an instantiation of the above.
Unlike template classes, template functions usually do not need to be explicit about 
the parameters over which they are instantiating. The compiler can usually determine them automatically.

Note: A “template function” is the instantiation of a “function template”.
Sometimes, you do want to be explicit about the types used. 
So explicitly select which version of a function template should get called: https://isocpp.org/wiki/faq/templates 
*/

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
	T max(const T &a, const T &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

#endif