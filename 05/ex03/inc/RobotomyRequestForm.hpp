#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);

		std::string getTarget() const;
		
		// --- memb.func
		void	execute(Bureaucrat const &bureaucrat) const;
};

#endif