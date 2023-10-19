#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;

	public:
		// -- constructors and destructor ----
		Form(void);
		~Form(void);
		Form(std::string name, int to_sign, int to_exec);
		Form(Form const &src);
		// ---- assignment operator -------
		Form &operator=(Form const &rhs);
		// ----- getters ------
		const std::string 	getName(void) const;
		int					getToSign(void) const;
		int 				getToExec(void) const;
		bool 				getIfSigned(void) const;
		// ---- memb. func ----
		void				becomeSigned(Bureaucrat &bureaucrat);
	
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

std::ostream &operator << (std::ostream &stream, Form const &rhs);

#endif