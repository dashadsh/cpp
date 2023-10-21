#include "../inc/Bureaucrat.hpp"

// SIC - we can do this kind of def. constructor:
// Bureaucrat::Bureaucrat() {}
// THEN - it will be bureaucrat w/o NAME & GRADE
// BUT
// we HAVE to move constructor to PRIVATE
// bc we SHOULDN'T ber able to INIT bureaucrat w/o this data !!!

Bureaucrat::Bureaucrat(void) : _name("def.name"), _grade(150) {
	std::cout << "bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "bureaucrat constructor called with name " << this->_name << " & grade " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
	std::cout << "bureaucrat copy constructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {
	this->_grade = rhs.getGrade();
	return (*this);
}


std::ostream &operator << (std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

const std::string Bureaucrat::getName(void) const{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return(this->_grade);
}

void Bureaucrat::incrementGrade(void) {
	if (this->getGrade() - 1 < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->getGrade() + 1 > 150 )
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}
