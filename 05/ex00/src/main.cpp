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
	std::cout << std::endl;

	Bureaucrat a("a", 1);
	Bureaucrat b("b", 75);
    Bureaucrat c("c", 150);
	std::cout << std::endl;

	Bureaucrat z("Z", 1);
	z.decrementGrade();
	std::cout << z << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat d("d", 0);
		// Bureaucrat e("d", 151);
		// c.decrementGrade();
		// a.incrementGrade();
	}

	catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

	// e.what(): calls WHAT member function of the caught exception object e,
	// WHAT function is virtual memb func of std::exception + its derived classes,
	// returns C-style string (const char*) which contains error msg associated with exception

	std::cout << "\nPRINTING BUREAUCRAT WITH OPERATOR OVERLOAD:" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl << std::endl;
}




	// TEST 2: test to show exception with overload << operator
	/*
	Bureaucrat	Bob("Bob", 1000);
	Bob.decrementGrade();
	Bob.incrementGrade();
	// constructor sets grade to 150
	//std::cout << Bob.getGrade() << std::endl;
	//std::cout << Bob;
	
	*/

    // TEST 3: to test also cannoncial form
	/*
	try {
		Bureaucrat	first("George", 0); //change to a valid number to proceed
		Bureaucrat	second("Clooney", 2);
		first.decrementGrade();
		second.incrementGrade();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	std::cout << "Testing the canonical form:" << std::endl;
	
	Bureaucrat office1("Hugo", 69);
	Bureaucrat office2(office1); // deep copy gets created.
	std::cout << office2;
	office1.incrementGrade();
	std::cout << office2;
	office2 = office1; // increment also deep copy by 1.
	std::cout << office2;
	*/