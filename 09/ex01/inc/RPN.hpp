#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack> // std::stack
#include <string> // std::string
#include <algorithm> // _s.size _s.empty _s.top
#include <cstdlib> // std::atoi
#include <sstream> // std::stringstream

// Using Stack container in this exercise
// https://www.geeksforgeeks.org/stack-in-cpp-stl/

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
   		 // clculate result of the RPN expression
		double calculate(std::string input);

		class ErrorException: public std::exception { // Add this class definition
			public:
				virtual const char* what() const throw();
		};
	
	private:
		// stack to store operands
		std::stack<std::string> _s;

	    // check if token is operator
		bool operationToken(char c);
		// perform operations
		void proceed();
};

#endif
