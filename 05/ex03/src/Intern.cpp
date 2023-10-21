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
// std::string Intern::getName() {
// 	return(_name);
// }

// std::string Intern::getTarget() {
// 	return(_target);
// }

///////////////////////////////////////////////////////////////////////////////////
// returns new ShrubberyCreationForm object
AForm *returnShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *returnPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *returnRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

// makeForm function creates specific form based on the form_name provided.
// It uses FPTR's to select appropriate form creation function.
// param:
//   - form_name: string -  name of the form to create
//   - target: string - target of the form
// returns:
//   - ptr to created form if successful
//   - NULL if form_name doesnt match any known form
AForm * Intern::makeForm(std::string form_name, std::string target) {
    // array of known form names
	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	// array of FPTR's to form creation functions
	AForm *(*fptr[3])(std::string) = {returnShrubbery, returnPresidential, returnRobotomy};
	
	for (int i = 0; i < 3; i++) {
		if (!form_name.compare(arr[i])) {
			std::cout << "intern creates form [" + form_name + "]" << std::endl;
			// call appropriate form creation function&return created form
			return (fptr[i](target));
		}
	} // print error mssg  -  not an exceprion, WHY???
	std::cout << "intern couldn't deliver [" << form_name << "]" << std::endl;
	return NULL;
}

