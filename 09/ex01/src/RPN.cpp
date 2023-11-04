#include "../inc/RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::~RPN() {
	std::cout << "RPN destructor called" << std::endl;
}
RPN::RPN(const RPN &src) {
	std::cout << "RPN copy constructor called" << std::endl;
	_s = src._s;
}

RPN& RPN::operator=(const RPN &src) {
	std::cout << "RPN assignment operator called" << std::endl;
	_s = src._s;
	return (*this);
}

bool RPN::operationToken(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*' ;
}

double RPN::calculate(std::string input) {
	int operandCount = 0; // had to add this variable to keep track of operands/operator
    int operatorCount = 0; // to handle "1 1 + 1"

	// iterate through the input string, if it's a number, push it to the stack
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == ' ')
			continue; // skip spaces, search for next token
		else if (isdigit(input[i])) {
			operandCount++; // NEW !!!
			for (size_t j = 0; j + i < input.length(); j++) {
				if (!isdigit(input[i + j])) { // find !isdigit -> indicates end of number token
					_s.push(input.substr(i, j)); // push number to stack
					i += j;
					break;
				}
			}
		}
		else if (operationToken(input[i])) { // if token is not a number/space, it must be an operator
			operatorCount++; // NEW !!!
			if (_s.size() < 2) // if there are less than 2 operands in the stack, we can't do any operations !
				throw ErrorException();
			_s.push(input.substr(i, 1));
			proceed();
		}
		else // if token is not a number/space/operator, it must be an invalid token
			throw ErrorException();
	}

	// after  loop, ensure that there is exactly one more operand than operator
    if (operandCount != operatorCount + 1) {
        throw ErrorException();
    }

	// after doOperation() is called, the result of the operation is pushed to the stack => _operations.size() == 1
	if (_s.size() != 1)
		throw ErrorException();
	// std::atoi with top elem. of the _operations stack as the arg.
	return std::atoi(_s.top().c_str());
}

// perform operations on a stack,
// changed to C++98 std::stringstream from C++11 std::to_string:
	// std::stringstream ss;
	// if (operToken == "+")
	// 	ss << a + b;
	// if (operToken == "-")
	// 	ss << a - b;
	// if (operToken == "/") {
	// 	if (b == 0)
	// 		throw std::exception();
	// 	ss << a / b;
	// }
	// if (operToken == "*")
	// 	ss << a * b;
	// std::string out = "";
	// ss >> out;
	// _s.push(out);
void RPN::proceed() {
	std::string operToken = _s.top();
	_s.pop();
	int b = std::atoi(_s.top().c_str());
	_s.pop();
	int a = std::atoi(_s.top().c_str());
	_s.pop();
	std::stringstream stream; // create string representation of the result to push it to the stack
	if (operToken == "+")
		stream << a + b;
	if (operToken == "-")
		stream << a - b;
	if (operToken == "/") {
		if (b == 0)
			throw ErrorException();
		stream << a / b;
	}
	if (operToken == "*")
		stream << a * b;
	std::string output = "";
	stream >> output;
	_s.push(output);
}
// std::stringstream is converting int result of the arithmetic operation into a string 
// so that it can be stored in the stack, which presumably holds strings. 
// This allows us to handle  conversion w/o relying on C++11 std::to_string.

const char *RPN::ErrorException::what() const throw() {
    return("Error\n");
}
