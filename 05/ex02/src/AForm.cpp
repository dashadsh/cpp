#include "../inc/AForm.hpp"

AForm::AForm(void) : _name("def.form"), _grade_to_sign(150), _grade_to_exec(150), _signed(false) {
	std::cout << "aform def.constructor called" << std::endl;
}

AForm::AForm(std::string name, int to_sign, int to_exec) : _name(name), _grade_to_sign(to_sign), _grade_to_exec(to_exec), _signed(false) {
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (to_sign > 150 || to_sign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "aform constructor called w.name " << this->_name << ", min.grade to sign: " << this->getToSign() << ", min.grade to exec: " << this->getToExec() << std::endl;
}

AForm::~AForm(void) {	
	std::cout << "aform destructor called" << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _signed(false) {
	*this = src;
	std::cout << "aform copy constructor called" << std::endl;
}

// ----- getters
const std::string AForm::getName(void) const {
	return (this->_name);
}

int AForm::getToSign(void) const {
	return(this->_grade_to_sign);
}

int AForm::getToExec(void) const {
	return(this->_grade_to_exec);
}

bool AForm::getIfSigned(void) const {
	return (this->_signed);
}

// --- memb.func
void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getToSign())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::setSigned(int state) {
	if (state == 1)
		this->_signed = true;
	else
		return;
}

void AForm::checkAbleToExec(Bureaucrat const &bureaucrat) const {
	if (this->getIfSigned() == 0) {
		throw FormNotSignedException();
		return ;
	}
	else if (this->getToExec() < bureaucrat.getGrade()) {
		throw GradeTooLowException();
		return ;
	}
}

AForm &AForm::operator=(AForm const &rhs) {
	this->_signed = rhs._signed;
	return (*this);
}

// ---- overload
std::ostream & operator<<(std::ostream &o, AForm const &rhs) {
	o << rhs.getName() << ", min.grade to sign: " << rhs.getToSign() << ", min.grade to exec: " << rhs.getToExec() << ". signed? " << (rhs.getIfSigned()?"YES":"NO");
	return (o);
}
