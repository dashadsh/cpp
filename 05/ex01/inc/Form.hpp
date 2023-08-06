/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:14:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 16:42:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string	_name;
    bool 				_isSigned;
    const int			_gradeToSign;
    const int			_gradeToExecute;

public:
	// -- constructors and destructor ----
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute); // better then "name"
    Form(const Form &src);
    ~Form();

	// ---- assignment operator -------
    Form &operator=(const Form &rhs);

	// --------- getters ----------
    const std::string	&getName() const; // better w. &
    bool				getIsSigned() const;
    int					getGradeToSign() const;
    int					getGradeToExecute() const;

	// ----- memb. functions ----------
    void 				beSigned(const Bureaucrat &bureaucrat);

	// -------- nested exception classes ----------
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
			return ("Form Exception: Grade is too high for form!");
		};
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
			return ("Form Exception: Grade is too low for form!");
		};
    };
};

// Overload the << operator to print the form's information
std::ostream &operator<<(std::ostream &o, const Form &form);

#endif
