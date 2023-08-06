/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:19:20 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 16:10:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main() {
    // Create instances of Bureaucrat with custom names and grades
	std::cout << "\n----- init. 3 bureaucrats with valid values ----------------------" << std::endl;
    Bureaucrat john("John Doe", 150);
    Bureaucrat jane("Jane Smith", 1);
    Bureaucrat mike("Mike Johnson", 75);

    std::cout << "\n---- try init. with value 0 --------------------------------------" << std::endl;
    try {
        Bureaucrat james("James Brown", 0);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- try init. with grade 151 -----------------------------------" << std::endl;
    try {
        Bureaucrat lucy("Lucy Green", 151);
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    // Decrease the grade of john
    std::cout << "\n----- try decrement John's grade (from value 150) ----------------" << std::endl;
    try {
        john.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "John's grade: " << john.getGrade() << std::endl;

    // Increase the grade of jane
    std::cout << "\n----- try increment Jane' grade (from 0 value) -------------------" << std::endl;
    try {
        jane.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Jane's grade: " << jane.getGrade() << std::endl;

    // Increase the grade of mike
    std::cout << "\n------ try increment Mike's grade (from val. 75) -----------------" << std::endl;
    try {
        mike.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Mike's grade: " << mike.getGrade() << std::endl;

    // Decrease the grade of mike
    std::cout << "\n----- try decrement Mike's grade ---------------------------------" << std::endl;
    try {
        mike.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Mike's grade: " << mike.getGrade() << std::endl;

    // Print the Bureaucrats using the operator<< overload
    std::cout << "\n----- Print with operator overload -------------------------------" << std::endl;
    std::cout << john << std::endl;
    std::cout << jane << std::endl;
    std::cout << mike << std::endl;
	
    std::cout << std::endl;
    return 0;
}
