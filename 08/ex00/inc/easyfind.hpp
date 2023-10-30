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
// #include <iterator>

template <class T> int easyfind(T &container_type, int tofind) {
	// CONST bc. won't accidentally modify the container while searching for an element
    typename T::const_iterator it;

	// std::find() returns iterator to 1st elem- in the range [0,last) that compares equal to val
	// it's STL algorithm that searches for an element in a container
    it = std::find(container_type.begin(), container_type.end(), tofind);
    if (it != container_type.end()) { // past-the-end element
        std::cout << "element: " << tofind << "	1st occurence at idx: ";
        std::cout << it - container_type.begin() << std::endl;
        return 0;
    }
    else {
        std::cout << "element: " << tofind << " not found" << std::endl;
        return 1;
    }
}

template <class T>
void printContainer(const T &type) {
    std::cout << "Container contents: ";
    for (typename T::const_iterator it = type.begin(); it != type.end(); ++it) {
        std::cout << *it << " - ";
    }
    std::cout << std::endl;
}

#endif
