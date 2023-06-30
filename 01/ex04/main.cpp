// ------------------------------------------------------------------------------------------------------------
// takes filename and two strings as input
// 
// reads the file, replaces each occurrence of the first string with the second one
// writes the result to a new file
// ------------------------------------------------------------------------------------------------------------

// In 2nd implementation each line is splitted into words and each word is checked against s1. 
// if a match is found,the word will be replaced with s2. 
// This approach will work well if you're trying to match and replace entire words. 
// If s1 is a substring that's part of a larger word, it won't be replaced 
// because it won't match any of the words extracted from the line.

// 1st implementation doesn't split the lines into words. 
// Instead, it checks the entire line for instances of s1,  
// If a match is found, it's replaced with s2.

// ------------------------------------------------------------------------------------------------------------

#include <fstream>  // file input/output
#include <iostream> // input/output on the console
#include <string>   // for string data type

int main(int ac, char *av[]) {

    if (ac != 4) {
        std::cerr << "usage: ./program <filename> <string1> <string2>\n";
        return 1;
    }

    // try to open the input file. std::ifstream is an input file stream which can read from files
    std::ifstream inFile(av[1]);
    // try to open the output file. std::ofstream is an output file stream which can write to files
    std::ofstream outFile(std::string(av[1]) + ".replace");

    if (!inFile) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    if (!outFile) {
        std::cerr << "Error opening output file\n";
        return 1;
    }

    // create string obj's to store lines from file, and 2 strings to find and replace
    std::string line;
    std::string s1 = av[2];
    std::string s2 = av[3];

    // while there are lines to read from input file:
    while (std::getline(inFile, line)) {
        // keep replacing s1 with s2 in current line
     	std::size_t pos;

		// this loop will find and process each occurrence of s1 in line, 
		// stopping when there are no more occurrences of s1 left:
        while ((pos = line.find(s1)) != std::string::npos) {
		// loop continues as long as s1 is found within line. 
		// It stops when s1 is no longer found, i.e., when line.find(s1) returns std::string::npos.
            line.erase(pos, s1.length());  // erase s1 from the line
            line.insert(pos, s2);  // insert s2 in its place
        }

        outFile << line << '\n';	// write modified line to the output file
    }

	// std::ifstream and std::ofstream objects automatically close the file they're 
	// associated with when they are destructed,
	// calls to close are not technically necessary but can be considered good practice 
	// because they make the code's intention clear
    inFile.close();
    outFile.close();

    return 0;
}

// For the dot (.) in line.insert(pos, s2) etc -  it's used to call the insert member function 
// on the std::string object line.

// In C++, the dot operator (.) is used to access members (functions or variables) of an object. 
// For example, if you have an object obj of a class MyClass, 
// and MyClass has a member function func, you could call func on obj like this: obj.func().

// The functions that are "just used as they are" are free functions that aren't associated with a specific class. 
// For example, std::getline is a free function that can read a line from a stream. 
// You can use it on any stream, so it doesn't belong to any specific stream object.

// On the other hand, functions used with the dot operator, like insert, are member functions. 
// They belong to a specific class and operate on objects of that class. 
// The insert function is a member of the std::string class and operates on std::string objects. 
// It can't be used on its own; it needs a std::string object to work on.

// ------------------------------------------------------------------------------------------------------------

// #include <iostream>  // std::cerr, std::endl
// #include <fstream>  // std::ifstream, std::ofstream
// #include <sstream>  // std::istringstream

// Open FD's: 
// The std::ifstream and std::ofstream objects (input_file and output_file) will automatically close 
// their associated files when they are destroyed. 
// They are local variables in the replace function, so they are destroyed when the function returns,
// which means the files they are associated with are closed.

// void replace(std::string filename, std::string s1, std::string s2) {
// //	void replace(const std::string &filename, const std::string &s1, const std::string &s2) { - BETTER, SEE BELOW-1
// //	std::ifstream input_file(filename); // read from a file
// 	std::ifstream input_file(filename.c_str()); // works with C++98
// //  In older versions of C++ the std::ifstream and std::ofstream constructors only accept const char*


//     if (!input_file) { // check if the inputfile was successfully opened
//         std::cerr << "error opening input file: " << filename << std::endl;
//         return;
//     }

// //	std::ofstream output_file(filename + ".replace"); // write to a file
// 	std::ofstream output_file((filename + ".replace").c_str());
// //	In older versions of C++ the std::ifstream and std::ofstream constructors only accept const char*


//     if (!output_file) { // check if outfile was successfully opened
//         std::cerr << "error opening output file: " << filename << ".replace" << std::endl;
//         return;
//     }

//     std::string line; // holds one line from the file which we will read

//     while (std::getline(input_file, line)) {  // read the file line by line using std::getline
//         std::istringstream iss(line);  // std::istringstream - split the line into words
//         std::string word; // placeholder for a single word
//         bool isFirstWord = true;

//         while (iss >> word) { // read the words from the line 'iss'
//             if (!isFirstWord) {
//                 output_file << ' '; // print a space after 1st word/between words, SEE BELOW-2
//             }

//             if (word == s1) { // if current word is equal to the 1st input string, replace it
//                 output_file << s2;
//             } else { // if not, print word as it is
//                 output_file << word;
//             }

//             isFirstWord = false;
//         }

//         output_file << '\n'; //prints newline after each line
//     }
// }

// int main(int ac, char **av) {
//     if (ac != 4) {
//         std::cerr << "usage: " << av[0] << " filename s1 s2" << std::endl;
//         return 1;
//     }
//     replace(av[1], av[2], av[3]);

//     return 0;
// }

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