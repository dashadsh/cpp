/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 15:32:06 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// SIC! - read about static_cast / dynamic_cast (type conversion based on inheritance relationship)

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	// << >> redirects the flow to or from a stream (like std::cout or std::cin)
	for (int i = 1 ; i < ac ; i++)
	{
		// strlen returns unsigned long (site_t)
		for (size_t j = 0 ; j < strlen(av[i]) ; j++)
		{
			char uppercaseChar = std::toupper(av[i][j]);
			std::cout << uppercaseChar;
		}
	}
	// std::cout: stdout
	// std::endl == \n: newline
	std::cout << std::endl;
	return 0;
}
