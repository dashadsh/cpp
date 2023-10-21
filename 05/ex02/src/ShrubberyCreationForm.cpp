// #include <cstdlib>

#include <fstream> // BELOW
#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("SCF", 145, 137), _target("def.target") {
	std::cout << "SCF default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target) {
	std::cout << "SCF target assigning constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "SCF default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm() {
	std::cout << "SCF copy constructor called" << std::endl;
	*this = src;
}

std::string ShrubberyCreationForm::getTarget() const {
    return(_target);
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	this->checkAbleToExec(executor);
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile (filename.c_str()); // fstream

	outfile << std::endl;               
	outfile <<"      /\\    / ____|/ ____|_   _|_   _| | |" << std::endl;                  
	outfile <<"     /  \\  | (___ | |      | |   | |   | |_ _ __ ___  ___  ___ " << std::endl;
	outfile <<"    / /\\ \\  \\___ \\| |      | |   | |   | __| '__/ _ \\/ _ \\/ __|" << std::endl;
	outfile <<"   / ____ \\ ____) | |____ _| |_ _| |_  | |_| | |  __/  __/\\__ \"" << std::endl;
	outfile <<"  /_/    \\_\\_____/ \\_____|_____|_____|  \\__|_|  \\___|\\___||___/" << std::endl;
	outfile.close();
	std::cout << "file \"" << filename << "\" was created " << std::endl;
}