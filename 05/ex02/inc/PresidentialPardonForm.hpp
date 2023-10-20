// #ifndef ROBOTOMYREQUESTFORM_HPP
// #define ROBOTOMYREQUESTFORM_HPP

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

// #include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);

		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);

		std::string getTarget() const;
		// --- memb.func
		void	execute(Bureaucrat const & executor) const;
};

#endif