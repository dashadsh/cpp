#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp" // !!!! NEW

class AForm; // !!! NEW

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
		// -- constructors and destructor ----
        Bureaucrat(void);
        ~Bureaucrat(void);
		Bureaucrat(std::string name, size_t grade);
        Bureaucrat(Bureaucrat const &src);

		// ---- assignment operator -------
        Bureaucrat & operator=(Bureaucrat const &rhs);

        // ----- getters ------
		const std::string getName() const;
        int getGrade() const;

		// ---- memb. functions -----
        void incrementGrade();
        void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);// NEW !!!!!!!!!!!!
		
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

std::ostream &operator << (std::ostream &o, const Bureaucrat &rhs);

#endif