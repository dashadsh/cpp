/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:14:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 17:32:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

// constructors & destructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
	std::cout << "Form constructor called with name " << this->_name << " minimum grade to sign: " << this->getToSign() << ", minimum grade to execute: " << this->getToExec() << std::endl;
}

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

// assignment Operator
Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        _isSigned = rhs._isSigned;
    }
    return *this;
	std::cout << "Form assignment operator called" << std::endl;
}

// getters
const std::string &Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// member function
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

// exception classes - cam be implemented here instead 
// const char *Form::GradeTooHighException::what() const throw() {
//     return "Form Exception: Grade is too high!";
// }

// const char *Form::GradeTooLowException::what() const throw() {
//     return "Form Exception: Grade is too low!";
// }

// Overload the << operator to print the form's information
std::ostream &operator<<(std::ostream &o, const Form &form) {
    o << "Form: " << form.getName()
      << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
      << ", Grade to Sign: " << form.getGradeToSign()
      << ", Grade to Execute: " << form.getGradeToExecute();
    return o;
}
