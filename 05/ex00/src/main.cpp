#include "../inc/Bureaucrat.hpp"

// exception handling block must be catchable as follows:
// try
// {
// 		/* do some stuff with bureaucrats */
// }
// catch (std::exception & e) 
// {
// 		/* handle exception */
// }

// try {
// 	if (ONE THINGHY) {
// 		throw ANOTHER THINGHY
// 	};
// }; =>  the variable of throw is passed to catch

// exception class has virtual member function,
// it's eturn: ptr to a 0-terminated string with explanatory info
// virtual const char* what() const throw();  //(until C++11)
// virtual const char* what() const noexcept; //(since C++11)

int main() {
	Bureaucrat a("a", 1);
	Bureaucrat b("b", 75);
    Bureaucrat c("c", 150);
	std::cout << a << std::endl;

	try {
		Bureaucrat d("d", 0);
		// Bureaucrat e("d", 151);
		// c.decrementGrade();
		// a.incrementGrade();
	}
	// catches exceptions of type std::exception:
	// caught exception e is an instance of std::exception or 
	// one of its derived classes, which includes custom exceptions 
	// (GradeTooHighException and GradeTooLowException). 
	//
	// e.what() func is used to get err msg associated with the thrown exception, 
	// then it's printed to standard error stream (std::cerr)
	catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

	std::cout << "\nPRINT BUREAUCRAT WITH OPERATOR OVERLOAD" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl << std::endl;
}
