#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// member func. should use STL algorithms
// provide improved addNumber function

// If you don’t have a clue, study the Containers.  
// Some member functions take a range of iterators in order to add a sequence of
// elements to the container:

// std::vector container allows to add a range of elements using iterators. 
// We can use 'insert' function with a range of iterators to add elements:
// std::vector<int> original = {1, 2, 3};
// std::vector<int> additional = {4, 5, 6};

// std::vector<int>::iterator insertPosition = original.begin() + 2;
// original.insert(insertPosition, additional.begin(), additional.end());

// 'original' will now contain: {1, 2, 4, 5, 6, 3}

class Span {
	private:
		unsigned int		_N; // max amt of int can be stored
		std::vector<int>	_vec; // container to store int

	public:
		Span();
		// class Span store max amt of N int
		Span(unsigned int N);
		~Span();
		Span(Span const &src);

		Span & operator=(Span const &src);
		
		void 	addNumber(int number); // mandatory func
		int 	shortestSpan(); // mandatory func
		int 	longestSpan(); // mandatory func

		// ------custom functions------
		void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		void 	fillConsecutiveNumbers();
		void 	fillRandomNumbers();
		void	printElements();
		// ------custom functions end ------
		// 'Virtual' is to enable polymorphic behavior when we catch exceptions 
		// using ptr's or ref's to the base class std::exception.
		// If a MaxSizeException or NoSpanException is thrown, what() function 
		// from the derived class will be called, 
		// and we'll get custom err. msg associated with that specific exception type.
		class MaxSizeException: public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class NoSpanException: public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

#endif
