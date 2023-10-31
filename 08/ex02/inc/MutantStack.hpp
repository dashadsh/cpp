#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack> // stack
#include <list> // list to compare w. stack
#include <vector>


template <typename T> 
class MutantStack : public std::stack <T> { // MutantStack will also inherit (implicitly) the template argument T
	    public:
		        MutantStack();
		        ~MutantStack ();
				MutantStack(const MutantStack &src);
		        MutantStack &operator=(const MutantStack &src);

                typedef typename std::stack<T>::container_type::iterator iterator;
		        iterator begin();
		        iterator end();
};

#endif
