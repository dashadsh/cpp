
#include "../inc/Bureaucrat.hpp"

int main() {
	Bureaucrat a("a", 1);
	Bureaucrat b("b", 75);
    Bureaucrat c("c", 150);

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
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}