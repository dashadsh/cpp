#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack> // stack
#include <list> // list to compare w. stack
#include <vector>

// std::stack container isn't iterable, but we should fix it

// common practice in C++ when creating iterable classes, 
// use non-const iterators to modify the elements of the container
// use const iterators to only access the elements of the container				
template <typename T> 
class MutantStack : public std::stack <T> { // inherit from std::stack, where T is a placeholder for any type. 
	    public:
		        MutantStack();
		        ~MutantStack ();
				MutantStack(const MutantStack &src);
		        MutantStack &operator=(const MutantStack &src);

				// typedef - keyword to create an alias name for another data type
				// typename - keyword to declare a qualified name as a type
				// std::stack<T> -  std::stack class template instantiated with a type T. It's the higher-level container that we want to access.
                // ::container_type - nested type within the std::stack class template. It refers to the type of the underlying container that std::stack uses to store its elements.
				// ::iterator - another nested type within container_type. It refers to the iterator type of the underlying container. T
				// iterator - new type alias that i'm defining
				typedef typename std::stack<T>::container_type::iterator iterator;
		        iterator begin();
		        iterator end();

				// typedef typename std::stack<T>::container_type::const_iterator const_iterator;
				// const_iterator begin() const;
				// const_iterator end() const;

				typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
				reverse_iterator rbegin();
   				reverse_iterator rend();

    			// typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    			// const_reverse_iterator rbegin() const;
    			// const_reverse_iterator rend() const;
};

#endif
