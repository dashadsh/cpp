#include "../inc/BitcoinExchange.hpp"

#define INPUT "Expected input: ./btc inputfile\n";

// using std::map where the key is a std::string and the value is a double,
// std::map is a sorted associative container that contains key-value pairs

int main(int ac, char **av) {	
	if (ac != 2) {
		std::cout << INPUT;
		return 1;
	}

 	// BitcoinExchange btc; - not possible, private constructor
	// BitcoinExchange btc = BitcoinExchange(DATABASE); 

	// do all operations on DATABASE using PARAMETRIC CONSTRUCTOR
	BitcoinExchange btc(DATABASE);
	// do all operations on av[1] (input file)
	btc.showExchange(av[1]);
	return 0;
}
