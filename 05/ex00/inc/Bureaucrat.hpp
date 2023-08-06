/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:18:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 15:57:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

/*
GradeTooHighException -  custom exception class (defined as a nested class inside the Bureaucrat class). 
Inherits from the std lib's std::exception class, 
making it a custom exception type that can be thrown/caught like any other C++ exception.

1. Declaration:
class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Exception: Grade is too high! Highest Grade is 1.";
        }
};

2. Inheritance:
class inherits from std::exception, which is the base class for all standard C++ exceptions. 
This allows custom exception class to be treated as a std exception.

3. Func. override:
overrides what() function from the base class std::exception. 
What() function is a virtual member function defined in the std::exception class, 
it is used to retrieve the exception's error message.

4. Custom Error Message:
In overridden what() function, we provide a custom error message as a C-style string (const char*).
 
5. Handling:
Exception Handling:
To handle GradeTooHighException (and others), we need to use try-catch block in the calling code:
try {
    // Code that may throw the GradeTooHighException
} catch (const GradeTooHighException& ex) {
    // Handle the exception here
    std::cout << "Error: " << ex.what() << std::endl;
}
If GradeTooHighException is thrown, catch block will be executed. 
It can access the error message by calling the what() function of the caught exception, 
allowing us to display the err message/take appropriate actions to handle exceptional situation.
*/


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
		Bureaucrat & operator=(Bureaucrat const &rhs);
		
		// --------- getters ----------
		std::string const 	&getName() const; // specially for larger data is better than: std::string getName() const;
		int					getGrade() const;
		
		// ----- memb. functions ----------
		void				incrementGrade(); // increase the grade of bureaucrat
		void				decrementGrade(); // decrease the grade of bureaucrat
		
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
