/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/25 01:04:20 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

// The iostream library is part of the C++ Standard Library that provides functionality to perform input and output operations, and is one of the most frequently used libraries in C++.

// The library defines several objects that correspond to the standard input, output, and error streams:

// std::cin: Standard input stream - Usually corresponds to keyboard input.
// std::cout: Standard output stream - Used to produce output to the screen.
// std::cerr: Standard error stream - Used to output errors to the screen. 
// It's unbuffered, meaning it will output text immediately without waiting for the buffer to fill.
// std::clog: Standard log stream - Also used for errors, but unlike cerr, it's buffered.
// The library also provides features for file input and output via std::ifstream (input file stream) and std::ofstream (output file stream) respectively.

// These objects are used with the stream insertion operator (<<) and the stream extraction operator (>>) 
// to perform formatted input and output. 
// This is one of the ways that C++ differs from C, which uses functions like printf and scanf for input and output. 
// Instead of having to remember format specifiers, you can use << and >> with std::cout and std::cin (and others) 
// to output and input data of any type that has these operators defined.

// void toUpper(char *str) 
// {
//     for(int i = 0; str[i]; i++) 
//     {
//         if(str[i] >= 'a' && str[i] <= 'z') 
//             str[i] -= 'a' - 'A';
//     }
// }

#include <cctype> // for 'toupper'

/// @brief converts command line arguments to uppercase
int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            // toUpper(argv[i]);
            // std::cout << argv[i] << " ";
			// prints the i'th command line argument followed by a space
			for(int j = 0; argv[i][j]; j++)
                argv[i][j] = std::toupper(argv[i][j]);
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
		// inserts a newline character (\n) into the output stream
		//  "flushes" the output stream - any text output to std::cout before this point will be visible in the console after this point
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
