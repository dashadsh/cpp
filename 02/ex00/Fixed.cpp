/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:02 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:23:03 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// ------------------------------ CONSTRUCTORS -------------------------------------------------------
// DEFAULT CONSTRUCTOR
// this is a constructor that can be called with no arguments. 
// It is used to create an object with default values.
// To provide a way to create an object of the class with default values.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR
// this constructor is used when an object is initialized with another object of the same class.
// To provide a way to create a new object as a copy of an existing object. 
// This is especially important for classes that manage resources such as memory, file handles, network connections, etc., 
// where copying the resource requires specific actions.
// SIC! This generally means that any resources that the original object owns (e.g., memory that it has dynamically allocated) 
// should be separately allocated for the new object, and the values copied over. This is called deep copying.
// In contrast, shallow copying, which might look like sharing resources, involves copying the resource pointers of the original object. 
// This can lead to issues such as double deletion: when the original object and its copy are destroyed (go out of scope), 
// both will try to free the same memory.
// Orthodox canonical form prescribes deep copying.
// used here: Fixed b(a);
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// ------------------------------ DESTRUCTOR -------------------------------------------------------
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// ------------------- COPY ASSIGNMENT OPERATOR OVERLOAD -------------------------------------------
// this operator is used when an already initialized object is assigned the values of another object of the same class.
// To allow one object to be assigned the values of another.
// By default, for classes, the assignment operator performs shallow copy, also known as copy assignment. 
// It's used like this:
//
// Type obj1, obj2;
// // ... set some values in obj1 ...
// obj2 = obj1;  // copy assignment
//
// Here, obj2 = obj1; invokes the copy assignment operator. The object obj2 becomes a copy of obj1.
// However, you can OVERLOAD the assignment operator for your own classes. 
// This is especially important if your class manages resources like memory. 
// Here's an example of how you might define a copy assignment operator for a simple class:
//
// class MyClass {
// public:
//   int* data;
//   MyClass& operator=(const MyClass& other) {
//     if (this != &other) {
//       delete[] data;  // free existing resource
//       // perform DEEP COPY!
//       data = new int[10];
//       for(int i=0; i<10; ++i) {
//         data[i] = other.data[i];
//       }
//     }
//     return *this;
//   }
// };
// Note the check if (this != &other). This is necessary to handle self-assignment correctly, i.e., when someone does something like obj = obj;.
// When you define your own copy assignment operator, you should also define a copy constructor and destructor to properly manage memory. 
// This is known as the rule of three.
// used here: c = b;
Fixed& Fixed::operator=(const Fixed& rhs) { // RHS - right hand side
    std::cout << "Copy assignment operator called" << std::endl;
	// checking if the current object (this) is not the same as the object referred to by rhs. 
	//
	// & returns the memory address of rhs, 
	// THIS is a pointer that points to the memory address of the current object. 
	//
	// If this and &rhs are equal - current obj. and rhs are the same object (i.e., self-assignment). 
	// In the case of self-assignment, we don't want to do anything, bc copying an obj to itself is a no-op and could be harmful 
	// (e.g., if we first deleted the contents of the object).
    if (this != &rhs) // RHS - right hand side
        this->_value = rhs.getRawBits();
    return *this;
}

// -------------------------------- MEMBER FUNC. -------------------------------------------
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}
