/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:18:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 16:42:45 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

// Forward declaration of Form class
class Form;

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
	    // -- constructors and destructor ----
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade); // specially for larger data is better than: Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		
		// ---- assignment operator -------
		Bureaucrat &operator=(Bureaucrat const &rhs);
		
		// --------- getters ----------
		std::string const 	&getName() const; // specially for larger data is better than: std::string getName() const;
		int					getGrade() const;
		
		// ----- memb. functions ----------
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form); // NEW !!!!!!!!!!
		
		// -------- nested exception classes ----------
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Grade is too high! Highes Grade is 1.");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what () const throw () {
					return ("Exception: Grade is too low! Lowest Grade is 150.");
				}
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
