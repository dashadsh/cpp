#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string> // .c_str(), std::getline (also in <istream> and <sstream>)
#include <fstream> // std::ifstream class
#include <algorithm> // .find .end .empty
#include <cstdlib> // atof
#include <map> // std::map
// #include <iomanip>
// #include <sstream> 

#define DATABASE "data.csv"

class BitcoinExchange {

	public:

		BitcoinExchange(std::string database_file);
		BitcoinExchange(const BitcoinExchange& src); // those can stay in public bc we cannot instantiate the class w/o database anyway
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
	
		void showExchange(std::string input_file);
	
 	 private:

		// std::map where the key is a std::string and the value is a double.
		std::map<std::string, double> _db;

		BitcoinExchange(); // we should prevent the default constructor from being called

		double findRate(std::string date);
		bool validDataLine(std::string line);
		bool validInputLine(std::string line);
		bool validDate(std::string line);
		bool validValue(std::string line);
		bool validYear(int year);
		bool validMonth(int month);
		bool validDay(int day, int month, int year);
};

#endif
