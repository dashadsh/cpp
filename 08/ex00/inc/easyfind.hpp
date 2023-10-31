// STL (Standard Template Library)
// has a set of template classes and functions to work with common data structures and algorithms. 

// ======= KEY COMPONENTS OF STL ========
// >>>>>>> CONTAINERS: 
// replicate structures very commonly used in programming - 
// dynamic arrays (vector), 
// queues (queue), 
// stacks (stack), 
// heaps (priority_queue), 
// linked lists (list), 
// trees (set), 
// associative arrays (map)...

// >>>>>>> ALGORITHMS: 
// (functions) that can be applied to containers or sequences of elements, for example:
// sorting (std::sort), searching (std::find), iteration (std::for_each) etc. 

// >>>>>>> ITERATORS:
// provide a uniform way to access and manipulate the elements within a container, for example:
// input iterators, output iterators, forward iterators, bidirectional iterators, and random access iterators.

// >>>>>>> FUNCTION OBJECTS (FUNCTORS): 
// objects that act like functions, often used in conjunction with algorithms, 
// can be custom-made or used from the library to perform operations on elements in containers.

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <array> // array container
#include <algorithm> // find()
#include <vector> // vector container, end()
#include <list>
#include <deque>

template <class T>
int easyfind(T &container_type, int tofind) {
	// std::find to search for the elem.in the container
    typename T::iterator it = std::find(container_type.begin(), container_type.end(), tofind);

    if (it != container_type.end()) {
        int index = 0; // bc of LIST
        for (typename T::iterator i = container_type.begin(); i != it; ++i) { // bc of LIST
            ++index; // bc of LIST
        }
        std::cout << "element: " << tofind << " 1st occurrence at index: " << index << std::endl;
		// std::cout << "element: " << tofind << " 1st occurrence at index: " << std::endl; // doesn't work for LIST
		// std::cout << it - container_type.begin() << std::endl; // doesn't work for LIST
        return 0;
    } else {
        std::cout << "element: " << tofind << " not found" << std::endl;
        return 1;
    }
}
// POSSIBLE PROBLEM: subtraction of iterators in the easyfind 
// when we try to calculate the idx of an element within a std::list. 
// Unlike random-access containers like std::vector, 
// we cannot subtract iterators from std::list directly to get the idx bc 
// it doesn't support random access.

template <class T>
void printContainer(const T &type) {
    std::cout << "Container contents: ";
    for (typename T::const_iterator it = type.begin(); it != type.end(); ++it) {
        std::cout << *it << " - ";
    }
    std::cout << std::endl;
}

#endif
