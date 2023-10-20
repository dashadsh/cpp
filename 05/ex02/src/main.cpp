/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:31:30 by yarutiun          #+#    #+#             */
/*   Updated: 2023/10/20 22:33:27 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
// #include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << std::endl;

	Bureaucrat weak("WEAK", 150);
	Bureaucrat strong("STRONG", 1);

	std::cout << std::endl;
	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////////
	std::cout << "------------- SHRUBBERY TEST -----------------------" << std::endl; 
	ShrubberyCreationForm scf_form("SCF_FORM");
	
	std::cout << std::endl;
	
	std::cout << weak.getName() << " -  attempt to sign the form " << scf_form.getName() << ":" << std::endl;
	try {
		weak.signForm(scf_form);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	std::cout << weak.getName() << " - attempt to execute the form " << scf_form.getName() << ":" << std::endl;
	try {
		scf_form.execute(weak);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to sign the form " << scf_form.getName() << ":" << std::endl;
	try {
		strong.signForm(scf_form);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to execute the form " << scf_form.getName() << ":" << std::endl;
	try {
		scf_form.execute(strong);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << " ------------- ROBOTOMY TEST -------------------------- " << std::endl; 
	RobotomyRequestForm rrf_form("RRF_FORM");

	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to sign the form " << rrf_form.getName() << ":" << std::endl;
	try {
		strong.signForm(rrf_form);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << weak.getName() << " - attempt to execute the form " << rrf_form.getName() << ":" << std::endl;
	try {
		weak.executeForm(rrf_form);
		// rrf_form.execute(weak);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to execute the form " << rrf_form.getName() << ":" << std::endl;
	try {
		strong.executeForm(rrf_form);
		// rrf_form.execute(strong);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
		////////////////////////////////////////////////////////////////////////
	std::cout << "------------- PRESIDENTAL TEST --------------------------" << std::endl; 
	PresidentialPardonForm ppf_form("PPF_FORM");

	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to sign the form " << ppf_form.getName() << ":" << std::endl;
	try {
		strong.signForm(ppf_form);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << weak.getName() << " - attempt to execute the form " << ppf_form.getName() << ":" << std::endl;
	try {
		ppf_form.execute(weak);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << strong.getName() << " - attempt to execute the form " << ppf_form.getName() << ":" << std::endl;
	try {
		ppf_form.execute(strong);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
}
