#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	private:
		std::string	_name;
		std::string	_target;

	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		
		Intern &operator=(Intern const &rhs);
		
		std::string getName();
   		std::string getTarget();

		AForm	*makeForm(std::string form_name, std::string target);

		class formNotFound : public std::exception {
			virtual const char* what() const throw();
	};
};

#endif
