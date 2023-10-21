#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

// BASE CLASS AFORM - is ABSTRACT CLASS
// contains PURE VIRTUAL function (execute) 
// =>
// derived class must provide concrete implementation of execute func.
class AForm {
	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;

	public:
		// -- constructors and destructor ----
		AForm(void);
		~AForm(void);
		AForm(std::string name, int to_sign, int to_exec);
		AForm(AForm const &src);
		// ---- assignment operator -------
		AForm &operator=(AForm const &rhs);
		// ----- getters ------
		const std::string 	getName(void) const;
		int					getToSign(void) const;
		int 				getToExec(void) const;
		bool 				getIfSigned(void) const;
		// ---- memb. func ----
		void				beSigned(Bureaucrat &bureaucrat);
		void				setSigned(int state);
		void				checkAbleToExec(Bureaucrat const &bureaucrat) const;
		// IMPLEMENT EXECUTE IN DERIVED CLASSES
		virtual void		execute(Bureaucrat const & executor) const = 0;
	
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what () const throw () {
					return ("exception: form isn't signed");
				}
		};
};

std::ostream &operator << (std::ostream &o, AForm const &rhs);

#endif