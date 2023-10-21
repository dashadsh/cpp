#include "../inc/Intern.hpp"

int main()
{
	Intern guy;
	
	AForm* rrf;
	
	rrf = guy.makeForm("ShrubberyCreationForm", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	// delete called on 'AForm' that is abstract but has non-virtual destructor 
	// [-Werror,-Wdelete-abstract-non-virtual-dtor]
	delete rrf;

	rrf = guy.makeForm("PresidentialPardonForm", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	delete rrf;

	rrf = guy.makeForm("RobotomyRequestForm", "olaf bender");
	std::cout << *rrf << std::endl << std::endl;
	delete rrf;
	
	rrf = guy.makeForm("someStupidForm", "olaf bender");
	std::cout << std::endl;
}
