#include "../inc/RPN.hpp"

// ----------------------------------------------------------------------------------------------
// Reverse Polish notation (RPN) 
// is a method for representing expressions in which the operator 
// symbol is placed after the arguments being operated on. 
// Polish notation, in which the operator comes before the operands, 
// was invented in the 1920s by the Polish mathematician Jan Lucasiewicz.
// https://www.britannica.com/topic/Polish-notation
// https://en.wikipedia.org/wiki/Reverse_Polish_notation
// ----------------------------------------------------------------------------------------------
// using std::stack: let's consider RPN expression: "3 4 +" 
// empty stack
// 3 is pushed onto the stack
// 4 is pushed onto the stack
// + is encountered, so 3 and 4 are popped off the stack and added together
// the result, 7, is pushed back onto the stack
// the stack now contains only 7 and the algorithm moves on to the next token
// if algorithm finishes - result is the only number left on the stack !!!
// ----------------------------------------------------------------------------------------------

int main(int ac, char **av) {	
	if (ac != 2) {
		std::cout << "Expected input: ./RPN \"RPN expression\"\n";
		return 1;
	}

	RPN reversedPolishNotation;

	try {
		std::cout << reversedPolishNotation.calculate(av[1]) << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}
