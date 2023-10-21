#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	private:
		// std::string	_name;
		// std::string	_target;

	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		
		Intern &operator=(Intern const &rhs);
		
		// std::string getName();
   		// std::string getTarget();

		// The first one is the name of a form,
		// the second one is the target of the form. 
		// It return a PTR to a Form object 
		// (whose name is the one passed as parameter) 
		// whose target will be initialized to the second parameter.
		AForm	*makeForm(std::string form_name, std::string target);

		// class formNotFound : public std::exception {
		// 	virtual const char* what() const throw(); }; 
		//  // could be POSSIBLE SOLUTION - 
		//  // i will JUST PRINT ERROR MESSAGE
};

#endif
