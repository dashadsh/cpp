#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RRF", 72, 45), _target("def.target") {
	std::cout << "RRF default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target) {
	std::cout << "RRF target assigning constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RRF default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm() {
	std::cout << "RRF copy constructor called" << std::endl;
	*this = src;
}

std::string RobotomyRequestForm::getTarget() const {
    return(_target);
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkAbleToExec(executor);
	srand((unsigned int)time(NULL));
	std::cout << "drrrrr...DRRRRR..." << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
};