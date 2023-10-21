#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);

		std::string getTarget() const;

		// --- memb.func
		void	execute(Bureaucrat const & executor) const;
		// create a file <target>_shrubbery in the working directory, 
		// and writes ASCII trees inside it.
};

#endif