#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

// Constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "MutantStack default constructor called" << std::endl;
}

// Copy Constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
    std::cout << "MutantStack copy constructor called" << std::endl;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack destructor called" << std::endl;
}

// Assignment Operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &src) {
    if (this == &src) {
        return (*this);
    }
    std::stack<T>::operator=(src);
    std::cout << "MutantStack assignment operator called" << std::endl;
    return (*this);
}

// Iterator begin
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

// Iterator end
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

#endif
