#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// member func. should use STL algorithms
// provide improved addNumber function

// If you don’t have a clue, study the Containers.  Some member
// functions take a range of iterators in order to add a sequence of
// elements to the container.

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:
		Span();
		// class Span store max amt of N int
		Span(unsigned int N);
		~Span();
		Span(Span const &src);

		Span & operator=(Span const &src);
		
		// add a single number to the Span. It will be used in order to fill it. 
		// not possible to add more numbers then N
		void 	addNumber(int number);
		// shortest span or the longest span (or distance, if you prefer) between 
		// all the numbers stored, and return it. 
		int 	shortestSpan();
		int 	longestSpan();

		// ------custom functions------
		void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		void 	fillConsecutiveNumbers();
		void 	fillRandomNumbers();
		void	printElements();
		// ------custom functions end ------

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
