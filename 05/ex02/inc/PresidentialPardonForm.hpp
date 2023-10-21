#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target); // All of them take only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.
		PresidentialPardonForm(PresidentialPardonForm const &src);

		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);

		std::string getTarget() const;
		// --- memb.func
		void	execute(Bureaucrat const & executor) const;
		// Informs that <target> has been pardoned by Zaphod Beeblebrox
};

#endif