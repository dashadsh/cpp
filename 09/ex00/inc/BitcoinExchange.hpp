#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream> // close()
# include <cstring>  // c_str()
# include <algorithm> // atof()
# include <map>  // map container

// Using map container in this exercise

// std::map - sorted associative container that contains key-value pairs with unique keys (mapped value).
// Key values (date) are generally used to sort and uniquely identify the elements, 
// Mapped values (numericValue) store the content associated to this key.
// Types of key and mapped value may differ & are grouped together in member type value_type, 
// which is a pair type combining both:
// ypedef pair<const Key, T> value_type --> std::pair<std::string, float > (date, numericValue)


class	BitcoinExchange {
	    public:
                BitcoinExchange();
		        BitcoinExchange(const BitcoinExchange &src);
                ~BitcoinExchange();
		        BitcoinExchange	&operator=(const BitcoinExchange &src);

                void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);
                std::map<std::string, float>	getExchangeRateMap(void);
                
		        void							checkOpenFile(std::ifstream &infile);
		        void							dataExchangeRate(char* datafileName);
                
                bool                            checkDeliminator(std::string line);
                bool							checkDateValidity(std::string date);
                bool                            checkNumValidity(std::string btcNumber);
		        float							findBtcRate(std::string date);
		        void							printBtcValue(char* infileName);


	    private:
                std::map<std::string, float>	_btcExchangeRate;
};

#endif