#include "../inc/BitcoinExchange.hpp"

#define INPUT "Expected input: ./btc inputfile\n";
int main(int ac, char **av) {	
	if (ac != 2) {
		std::cout << INPUT;
		return 0;
	}

 	// BitcoinExchange btc; - not possible, private constructor
	
	// store database in the map
	// BitcoinExchange btc = BitcoinExchange(DATABASE); 
	BitcoinExchange btc(DATABASE);
	btc.showExchange(av[1]);
	return 0;
}
