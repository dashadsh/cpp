/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/29 00:13:52 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

// void toUpper(char *str) 
// {
//     for(int i = 0; str[i]; i++) 
//     {
//         if(str[i] >= 'a' && str[i] <= 'z') 
//             str[i] -= 'a' - 'A';
//     }
// }

#include <cctype> // for 'toupper'
// If you need to support non-ASCII letters, 
// you should use the version from the <locale> header and 
// specify the appropriate locale.

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            // toUpper(argv[i]);
            // std::cout << argv[i]; // << " ";
			// prints the i'th command line argument followed by a space
			for(int j = 0; argv[i][j]; j++)
                argv[i][j] = std::toupper(argv[i][j]);
            std::cout << argv[i]; // << " ";
        }
        std::cout << std::endl;
		// inserts \n into the output stream
		//  "flushes" the output stream - any text output to std::cout before this point will be visible in the console after this point
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
