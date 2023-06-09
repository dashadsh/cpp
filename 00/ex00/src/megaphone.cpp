/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 19:41:30 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //  I/O in C++
#include <cctype> //
// The <cctype> header provides various functions for character classification 
// and case conversion, including std::toupper for converting characters to uppercase.

// SIC! - read about static_cast / dynamic_cast (type conversion based on inheritance relationship)

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	// << >> redirects the flow to or from a stream (like std::cout or std::cin)
	for (int i = 1 ; i < ac ; i++)
	{
		for (size_t j = 0 ; av[i][j] != '\0' ; j++)
		{
			char uppercaseChar = std::toupper(av[i][j]);
			std::cout << uppercaseChar;
		}
	}
	std::cout << std::endl;
	return 0;
}
