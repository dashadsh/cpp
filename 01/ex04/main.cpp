// replacer.cpp
#include <iostream>  // std::cerr, std::endl
#include <fstream>  // std::ifstream, std::ofstream
#include <sstream>  // std::istringstream

// takes filename and two strings as input
// 
// reads the file, replaces each occurrence of the first string with the second one
// writes the result to a new file
void replace(std::string filename, std::string s1, std::string s2) {
//void replace(const std::string &filename, const std::string &s1, const std::string &s2) { - BETTER, SEE BELOW
    // std::ifstream - to read from a file
    std::ifstream input_file(filename);

    // check if the input file was successfully opened
    if (!input_file) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return;
    }

    // std::ofstream - to write to a file
    std::ofstream output_file(filename + ".replace");

    // check if out. file was successfully opened
    if (!output_file) {
        std::cerr << "Error opening output file: " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    // read the file line by line using std::getline
    while (std::getline(input_file, line)) {
        // std::istringstream - split the line into words
        std::istringstream iss(line);
        std::string word;
        bool isFirstWord = true;

        // read the words from the line
        while (iss >> word) {
            // Don't print a space before the 1st word of the line
            if (!isFirstWord) {
                output_file << ' ';
            }

            // if current word is equal to the 1st input string, replace it
            if (word == s1) {
                output_file << s2;
            } else {
                // if not, print word as it is
                output_file << word;
            }

            isFirstWord = false;
        }

        // prints newline after each line
        // output_file << '\n';
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        // if the number of argss is not 4, print an error message and return 
		// 1 (non-zero) indicating program failure.
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
// -----------------------------------------------------------------------------------