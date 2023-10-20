#include "../inc/Intern.hpp"

Intern::Intern(void) {
	std::cout << "intern default constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "intern destructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "intern copy constructor called" << std::endl;
	*this = src;
}

Intern & Intern::operator=(Intern const &rhs) {
	(void)rhs;
	std::cout << "intern assignment operator called" << std::endl;
	return (*this);
}

// ----- getters
std::string Intern::getName() {
	return(_name);
}

std::string Intern::getTarget() {
	return(_target);
}

///////////////////////////////////////////////////////////////////////////////////
AForm *returnShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *returnPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *returnRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm * Intern::makeForm(std::string form_name, std::string target) {

	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	AForm *(*fptr[3])(std::string) = {returnShrubbery, returnPresidential, returnRobotomy};
	
	for (int i = 0; i < 3; i++) {
		if (!form_name.compare(arr[i])) {
			std::cout << "intern's working on [" + form_name + "]" << std::endl;
			return (fptr[i](target));
		}
	}
	// throw Intern::formNotFound();
	std::cout << "intern couldn't deliver [" << form_name << "]" << std::endl;
	return NULL;
}

