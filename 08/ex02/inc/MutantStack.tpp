#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
    std::cout << "MutantStack copy constructor called" << std::endl;
}

// returns a ref. to the obj. that the values are being assigned to. 
// this allows assignment expressions to be chained together, like a = b = c !!!
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    std::cout << "MutantStack assignment operator called" << std::endl;
    return *this;
}

// // IF WE WANT TO RETURN VALUE:
// template <typename T>
// MutantStack<T> MutantStack<T>::operator=(const MutantStack &src) {
//     if (this != &src) {
//         std::stack<T>::operator=(src);
//     }
//     std::cout << "MutantStack assignment operator called" << std::endl;
//     return *this;
// }


// By default, std::stack uses a std::deque, 
// but it can be configured to use other container types like std::vector or std::list.
// Underlying container can be accessed through protected member 'c' of std::stack.
//
// Usually, stack should only be accessed through push, pop, and top operations.
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin(); // member function of the underlying container
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
//     return this->c.begin();
// }

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
//     return this->c.end();
// }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin(); // member function of the underlying container 
	// that returns a reverse iterator pointing to the last element in the container.
	// Reverse iterators traverse container from the end to the beginning.
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

// template <typename T>
// typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
//     return this->c.rbegin();
// }

// template <typename T>
// typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
//     return this->c.rend();
// }

#endif

// // COPY CONSTRUCTOR
// template <typename T>
// MutantStack<T>::MutantStack(const MutantStack &copy) {
// 	std::stack<T> tmpStack(copy); // create temp. stack with a shallow copy
//     std::stack<T>& underlyingContainer = this->c;
    
//     // clear current container to make room for the deep copy
//     underlyingContainer = std::stack<T>();
    
//     // copy elements from temp. stack to the underlying container
//     while (!tmpStack.empty()) {
//         underlyingContainer.push(tmpStack.top());
//         tmpStack.pop();
//     }

//     std::cout << "MutantStack copy constructor called" << std::endl;
// }

// // ASSIGNMENT OPERATOR
// template <typename T>
// MutantStack<T>& MutantStack<T>::operator=(const MutantStack &src) {
//     if (this == &src) {
//         return *this;
//     }
//     std::stack<T> tmpStack(src); // create temporary stack with a shallow copy
//     std::stack<T>& underlyingContainer = this->c;

//     // clear current container to make room for the deep copy
//     underlyingContainer = std::stack<T>();

//     // copy elements from the temp. stack to the underlying container
//     while (!tmpStack.empty()) {
//         underlyingContainer.push(tmpStack.top());
//         tmpStack.pop();
//     }
//     std::cout << "MutantStack assignment operator called" << std::endl;
//     return *this;
// }
