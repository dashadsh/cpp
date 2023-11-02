#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <array> // array container
#include <algorithm> // find()
#include <vector> // vector container
#include <list>
#include <deque>

// easyfind is a template function with a type parameter T,
// it can work with containers of various types (std::vector<int>, std::list<int> ...)
template <class T>
int easyfind(T &container_type, int tofind) {
	// when using dependent names from a template parameter (e.g., T::iterator), 
	// we need to specify typename before the dependent name to indicate that it is a type
    typename T::iterator it;
	// STL algorithm used to search for a specific value in a container,
	// it's used to find the 1st occurrence of the element tofind in the container  
	it = std::find(container_type.begin(), container_type.end(), tofind);

    if (it != container_type.end()) { // we found the element
        int index = 0;
        for (typename T::iterator i = container_type.begin(); i != it; ++i) {
            ++index;
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
// when we try to calc. idx of an element within a std::list. 
// Unlike random-access containers like std::vector, 
// we cannot subtract iterators from std::list directly to get the idx bc 
// it doesn't support random access.

template <class T>
void printContainer(const T &type) {
    std::cout << "Container contents: ";
	// use iterator for forward traversal
    for (typename T::const_iterator it = type.begin(); it != type.end(); ++it) {
        std::cout << *it << " -> "; // ITERATOR SUPPORTS DEREFEREMCING to get elem. value
    }
    std::cout << std::endl;
}

#endif

/*
1. Sequence Containers:

std::vector: Dynamic array with fast random access.
std::deque: Double-ended queue for efficient insertion and deletion at both ends.
std::list: Doubly-linked list for efficient insertions and deletions in the middle.
std::array: Fixed-size array with fast access.
std::forward_list: Singly-linked list with forward traversal only.

2. Associative Containers:

std::set: Ordered collection of unique elements.
std::multiset: Ordered collection of elements with possible duplicates.
std::map: Ordered key-value pairs with unique keys.
std::multimap: Ordered key-value pairs with possible duplicate keys.

3. Unordered Containers:

std::unordered_set: Unordered collection of unique elements.
std::unordered_multiset: Unordered collection of elements with possible duplicates.
std::unordered_map: Unordered key-value pairs with unique keys.
std::unordered_multimap: Unordered key-value pairs with possible duplicate keys.

4. Container Adapters:

std::stack: Adapts a container to provide a stack interface (Last In, First Out).
std::queue: Adapts a container to provide a queue interface (First In, First Out).
std::priority_queue: Adapts a container to provide a priority queue interface.

------------------------------------------------------------
std::vector, std::deque, std::list, etc., are primary containers.
std::queue is a container adapter, not a primary container.
However, we can use std::queue to work with an underlying container to implement a queue efficiently. 
Under the hood, std::queue relies on one of the primary containers (usually std::deque) to manage its elements.
*/
