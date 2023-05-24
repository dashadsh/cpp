#include <iostream>

int main()
{
	std::cout << "HELLO" << std::endl;
	std::cin.get();
}

// The #include <iostream> line is a preprocessor command
//  that tells the compiler to include the iostream standard file. 
//  This file allows input and output operations.

// int main() is the main function where the program starts. 
// The integer type means it will return an integer.

// std::cout << "HELLO" << std::endl; uses the cout object, 
// along with the insertion operator (<<), to output the string "HELLO". 
// The std::endl part puts a newline and flushes the output.

// std::cin.get(); waits for user input before the program closes, 
// this is especially useful in windows console programs where the 
// console window closes immediately after the program execution.

// Compile the program using:
// clang++ -std=c++11 -stdlib=libc++ main.cpp -o main 
// replacing main.cpp with the name of your file and main with the desired output name.