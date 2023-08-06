/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:19:20 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/08/06 17:58:07 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main() {
    std::cout << "\n----- Test the Form class ------------------------" << std::endl;
    try {
        Form taxForm("Tax Form", 5, 10);
        std::cout << taxForm << std::endl;

        Bureaucrat hercules("Hercules", 3);
        hercules.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat lowGrade("Low_Grade", 8);
        lowGrade.signForm(taxForm);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
