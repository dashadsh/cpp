// ------------------------------------------------------------------------------------------------------------
// takes filename and two strings as input
// 
// reads the file, replaces each occurrence of the first string with the second one
// writes the result to a new file
// ------------------------------------------------------------------------------------------------------------

#include <iostream>  // std::cerr, std::endl
#include <fstream>  // std::ifstream, std::ofstream
#include <sstream>  // std::istringstream

void replace(std::string filename, std::string s1, std::string s2) {
//void replace(const std::string &filename, const std::string &s1, const std::string &s2) { - BETTER, SEE BELOW-1
    std::ifstream input_file(filename); // read from a file

    if (!input_file) { // check if the inputfile was successfully opened
        std::cerr << "error opening input file: " << filename << std::endl;
        return;
    }

    std::ofstream output_file(filename + ".replace"); // write to a file

    if (!output_file) { // check if outfile was successfully opened
        std::cerr << "error opening output file: " << filename << ".replace" << std::endl;
        return;
    }

    std::string line; // holds one line from the file which we will read

    while (std::getline(input_file, line)) {  // read the file line by line using std::getline
        std::istringstream iss(line);  // std::istringstream - split the line into words
        std::string word; // placeholder for a single word
        bool isFirstWord = true;

        while (iss >> word) { // read the words from the line 'iss'
            if (!isFirstWord) {
                output_file << ' '; // print a space after 1st word/between words, SEE BELOW-2
            }

            if (word == s1) { // if current word is equal to the 1st input string, replace it
                output_file << s2;
            } else { // if not, print word as it is
                output_file << word;
            }

            isFirstWord = false;
        }

        output_file << '\n'; //prints newline after each line
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "usage: " << av[0] << " filename s1 s2" << std::endl;
        return 1;
    }
    replace(av[1], av[2], av[3]);

    return 0;
}

// -----------------------------------------------------------------------------------
// Efficiency: 
// When you pass an argument by value (as in std::string filename), 
// a copy of that argument is created, which can be costly for large objects like strings. 
// By passing the argument by reference (&), no copy is made, and the function works 
// directly with the original data, which can be more efficient.
//
// Const correctness: 
// The const keyword tells the compiler that this function does not modify the argument. 
// This is a form of self-documenting code and can help prevent programming errors. 
// It's a good practice to make as many things const as you can.
//
// -----------------------------------------------------------------------------------
//
// The reason every iteration of the while loop reads a new word from iss is because 
// of the way the extraction operator (>>) works in C++.
// When you use the extraction operator (>>) on an std::istringstream object, it performs the following steps:
// 
// Skip leading whitespace: 
// The extraction operator skips over any leading whitespace characters (spaces, newlines, tabs).
// It keeps skipping until it finds a non-whitespace character.
//
// Extract non-whitespace characters: 
// The extraction operator then reads the non-whitespace characters and stores them in the variable 
// on the right side of the operator (word in this case).
// It stops reading when it encounters another whitespace character or the end of the string. 
// This sequence of non-whitespace characters is what we are referring to as a "word".
//
// Prepare for the next extraction: 
// The operator leaves the next character in the stream, even if it's a whitespace. 
// This is important because the next time you use the extraction operator, 
// it will start by skipping over this (and any subsequent) whitespace character(s), and then read the next word.
// This behavior is repeated each time you use iss >> word in the loop.
//
// Therefore, every iteration of the loop reads a new word from iss because the extraction operator 
// always starts reading from where it last stopped.
// This is how we can read words one by one from a string using a while loop in C++.