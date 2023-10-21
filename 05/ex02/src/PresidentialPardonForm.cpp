#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PPF", 25, 5), _target("def.target") {
	std::cout << "PPF default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), _target(target) {
	std::cout << "PPF target assigning constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PPF default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm() {
	std::cout << "PPF copy constructor called" << std::endl;
	*this = src;
}

std::string PresidentialPardonForm::getTarget() const {
    return(_target);
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkAbleToExec(executor);
	std::cout << this->_target << " pardoned by Zaphod Beeblebrox" << std::endl;	
};