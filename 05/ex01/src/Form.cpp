#include "../inc/Form.hpp"

Form::Form(void) : _name("def.form"), _grade_to_sign(150), _grade_to_exec(150), _signed(false) {
	std::cout << "form def.constructor called" << std::endl;
}

Form::Form(std::string name, int to_sign, int to_exec) : _name(name), _grade_to_sign(to_sign), _grade_to_exec(to_exec), _signed(false) {
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (to_sign > 150 || to_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "form constructor called w.name " << this->_name << ", min.grade to sign: " << this->getToSign() << ", min.grade to exec: " << this->getToExec() << std::endl;
}

Form::~Form(void) {	
	std::cout << "form destructor called" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _signed(false) {
	*this = src;
	std::cout << "form copy constructor called" << std::endl;
}

const std::string Form::getName(void) const {
	return (this->_name);
}

int Form::getToSign(void) const {
	return(this->_grade_to_sign);
}

int Form::getToExec(void) const {
	return(this->_grade_to_exec);
}

bool Form::getIfSigned(void) const {
	return (this->_signed);
}

void Form::becomeSigned(Bureaucrat &bureaucrat) {

	if (bureaucrat.getGrade() > this->getToSign())
		throw Form::GradeTooLowException();
	this->_signed = true;
}


Form &Form::operator=(Form const &rhs) {
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream & operator<<(std::ostream &o, Form const &rhs) {
	o << rhs.getName() << ", min.grade to sign: " << rhs.getToSign() << ", min.grade to exec: " << rhs.getToExec() << ". signed? " << (rhs.getIfSigned()?"YES":"NO");
	return (o);
}
