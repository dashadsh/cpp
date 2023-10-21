#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string _name; // CONSTANT NAME !!!
        int _grade; // range 1-150

    public:
		// -- constructors and destructor ----
        Bureaucrat(void);
        ~Bureaucrat(void);
		Bureaucrat(std::string name, size_t grade);
        Bureaucrat(Bureaucrat const &src);

		// ---- assignment operator -------
        Bureaucrat &operator=(Bureaucrat const &rhs);

        // ----- getters ------ NEED TO BE PROVIDED !!! 
		const std::string getName() const;
        int getGrade() const;

		// ---- memb. functions ----- NEED TO BE PROVIDED !!! 
        void incrementGrade();
        void decrementGrade();

		// ------ nestes exception classes ----- 
		// if the grade is invalid, an exception must thrown =>
		// CUSTOM error message when the exception is caught
		// INHERIT FROM EXCEPTION CLASS
        class GradeTooHighException : public std::exception {
            public:
			// function can be overridden in derived classes
			// not nesessary - but good thing for custom exceptions!
			// const char*: returns ptr to constant char (a C-style string)
			// what() const: what is DIAGNOSTIC function => isn't modifying obj it was called on
			// throw(): prior to C++11, used to specify that WHAT func doesn't throw exceptions 
                virtual const char *what() const throw() {
					return ("exception: grade too high");
				}
			// COULD BE MOVED TO .CPP
			// const char* Bureaucrat::GradeTooLowException::what() const {
    		// return "exception: grade too low"; }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw()  {
					return ("exception: grade too low");
				}
        };
};

// operator<<: name of the operator being overloaded (standard stream insertion operator, which is overloaded for Bureaucrat class)
// std::ostream &stream: ref to std::ostream obj, represents output stream where we want to insert Bureaucrat obj
// const Bureaucrat &rhs - ref to constant Bureaucrat obj - represents Bureaucrat obj we want to print
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif



/*
throw: is used for exception handling in C++
used when an exceptional or error condition is encountered.
when an exception is thrown,  normal program flow is interrupted, 
control is transferred to the nearest catch block, 
where the exception can be handled.

we can throw an exception of any type, incl user-defined exception types, 
and we can catch & handle these exceptions using try and catch blocks
*/