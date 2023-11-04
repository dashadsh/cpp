#include "../inc/RPN.hpp"

// Reverse Polish notation (RPN) 
// is a method for representing expressions in which the operator 
// symbol is placed after the arguments being operated on. 
// Polish notation, in which the operator comes before the operands, 
// was invented in the 1920s by the Polish mathematician Jan Lucasiewicz.
// https://www.britannica.com/topic/Polish-notation
// https://en.wikipedia.org/wiki/Reverse_Polish_notation

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
		return 1;
	}
	return 0;
}
