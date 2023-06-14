/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/06/14 22:12:13 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> // toupper, strlen

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	// << >> redirects the flow to or from a stream (like std::cout or std::cin)
	for (int i = 1 ; i < ac ; i++)
	{
		for (int j = 0 ; j < (int)strlen(av[i]) ; j++)
		{
			std::cout << (char)toupper(av[i][j]);
		}
	}
	// std::cout: stdout
	// std::endl == \n: newline
	std::cout << std::endl;
	return (0);
}
