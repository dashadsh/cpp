#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
	Bureaucrat b("b", 50);
	Form form1("FORM1", 1, 50);
	Form form2("FORM2", 50, 50);
	Form form3("FORM3", 150, 50);


	try {
		b.signForm(form1);
		// b.signForm(form2);
		// b.signForm(form3);
		// form3.becomeSigned(b);
		// Form form4("FORM4", 0, 150);
		// Form form5("FORM5", 151, 150);
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

	std::cout << "\nPRINT FORM WITH OPERATOR OVERLOAD" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << std::endl;
}