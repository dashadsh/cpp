#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp" // !!!! NEW !!!!

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
		// -- constructors and destructor ----
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string name);
		Bureaucrat(std::string name, size_t grade);
        Bureaucrat(Bureaucrat const &src);

		// ---- assignment operator -------
        Bureaucrat &operator=(Bureaucrat const &rhs);

        // ----- getters ------
		const std::string getName() const;
        int getGrade() const;

		// ---- memb. functions -----
        void incrementGrade();
        void decrementGrade();
		void signForm(Form &form); // NEW !!!!!!!!!!!!

		// ------ nestes exception classes -----
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
					return ("exception: grade too high");
				}
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw()  {
					return ("exception: grade too low");
				}
        };
};

std::ostream &operator << (std::ostream &stream, const Bureaucrat &rhs);

#endif