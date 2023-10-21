#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name; // CONST !!!
		const int			_grade_to_sign; // CONST !!!
		const int			_grade_to_exec; // CONST !!!
		bool				_signed; // BOOLEAN INDICATING WHETHER IT'S SIGNED

	public:
		// -- constructors and destructor ----
		Form(void);
		~Form(void);
		Form(std::string name, int to_sign, int to_exec);
		Form(Form const &src);
		// ---- assignment operator -------
		Form &operator=(Form const &rhs);
		// ----- getters ------ // FOR ALL ATTRIBUTES
		const std::string 	getName(void) const;
		int					getToSign(void) const;
		int 				getToExec(void) const;
		bool 				getIfSigned(void) const;
		
		// ---- memb. func ---- changes the form status to signed if the bureaucrat’s grade is high enough
		void				beSigned(Bureaucrat &bureaucrat);
	
		// -----exception classes-------------- 
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("exception: grade too high for form");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what () const throw () {
					return ("exception: grade too low for form");
				}
		};
};

// SHOULD PRINT ALL DATA OF FORM !!! 
std::ostream &operator << (std::ostream &o, Form const &rhs);

#endif