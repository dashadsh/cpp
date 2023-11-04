#include "../inc/BitcoinExchange.hpp"

#define ERR_FILE "Error: Coudn't open file\n"
#define ERR_BAD_INPUT "Error: bad input => "
#define DB_HEADER "date,exchange_rate"
#define IN_HEADER "date | value"
#define ERR_HEADER "Error: invalid header => "
#define ERR_DATE "Error: invalid date => "
#define ERR_VALUE "Error: invalid value => "
#define ERR_VALUE_POS "Error: not a positive number.\n"
#define ERR_VALUE_LARGE "Error: too large a number.\n"
#define ERR_EXCHANGE "Error: No exchange rate available => "

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	_db = src._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	_db = src._db;
	return *this;
}

// PARAMETRIC CONSTRUCTOR
// will iterate through the file and store the data in the map - 
// std::map is a sorted associative container that contains key-value pairs.
// even if conversion date to double or other things fail, we still store the date in the map.
BitcoinExchange::BitcoinExchange(std::string database_file) {
	// std::ifstream class (derived from std::ifstream) is used for file handling
	// c_str() returns PTR to null-terminated array (string)
	std::ifstream db_stream(database_file.c_str());
	std::string buffer;
	
	// is_open() - member function of std::ifstream class
	if(!db_stream.is_open()) { 
		std::cerr << ERR_FILE;
		return ;
	}
	// getline is included in <string> and <sstream>
	getline(db_stream, buffer, '\n');
		if (buffer != DB_HEADER) {
		std::cerr << ERR_HEADER << buffer << "\n";
	}
	// reading a line of text from the db_stream input stream,
	// storing it in the buffer string, intil '\n'
	while (getline(db_stream, buffer, '\n')) {
		if(!validDataLine(buffer)) { // check all lines for length and separator
			std::cerr << ERR_BAD_INPUT << buffer << "\n";
			continue; // skip the rest of the loop - we HAVE to process ENTIRE FILE!!!
		}
		// substr can take 1 or 2 arguments,
		// we save date & value to temp variables
		std::string date = buffer.substr(0, 10);
		std::string raw_value = buffer.substr(11);	
		// atof - convert str to double, from c++11 better to use 'stod'
		double value = atof(raw_value.c_str());	
		// atof returns 0.0 when it cannot convert the string
		if (!value && raw_value != "0") {
			std::cerr << ERR_BAD_INPUT << buffer << "\n";
			continue;
		}
		_db[date] = value;
	}	
}

// check all lines for length and separator
bool BitcoinExchange::validDataLine(std::string line) {
    const size_t expectedDateLength = 10;
    const size_t minimumValidLength = 12;

    if (line.length() < minimumValidLength)
        return false;

    size_t comma_pos = line.find(',');

    if (comma_pos != expectedDateLength)
        return false;
    return true;
}

// check all lines for length and separator
// Each line in this file must use the following format: "date | value".
bool BitcoinExchange::validInputLine(std::string line) {
    const size_t expectedSeparatorPosition = 10; // idx of " | "
    const size_t minimumValidLength = expectedSeparatorPosition + 3 + 1; // Minimum length for "date | value" - date+sep+value

	if (line.length() < minimumValidLength)
        return false;

    // check if the separator " | " is in the expected position (10 characters from the beginning).
    if (line.substr(expectedSeparatorPosition, 3) != " | ")
        return false;
    return true;
}

bool BitcoinExchange::validYear(int year) {
    return year >= 1;
}

bool BitcoinExchange::validMonth(int month) {
    return month >= 1 && month <= 12;
}

bool BitcoinExchange::validDay(int day, int month, int year) {
    if (day < 1)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    } else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        return (isLeapYear && day <= 29) || (!isLeapYear && day <= 28);
    } else {
        return day <= 31;
    }
}

// a valid date will always be in the following format: Year-Month-Day.
bool BitcoinExchange::validDate(std::string line) {
	if (line.at(4) != '-' || line.at(7) != '-')
		return false;
	
	std::string year_str = line.substr(0, 4);
	std::string month_str = line.substr(5, 2);
	std::string day_str = line.substr(8, 2);
	
	int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());
	
	if (!validYear(year) || !validMonth(month) || !validDay(day, month, year))
        return false;
	return true;
}

// a  valid value must be either a float or a positive integer, between 0 and 1000.
bool BitcoinExchange::validValue(std::string line) {
	double value = std::atof(line.c_str());
	
	// atof returns 0.0 when it cannot convert the string
	if (!value && line.substr(0, 1) != "0") {
		std::cerr << ERR_VALUE << line << "\n";
		return false;
	}
	if (value < 0) { // exchange rate cannot be negative
 		std::cerr << ERR_VALUE_POS;
		 return false;
	}
	if (value > 1000) {
 		std::cerr << ERR_VALUE_LARGE;
		return false;
	}
	return true;
}

// If the date used in the input does not exist in your DB then you
// must use the closest date contained in your DB. Be careful to use the
// lower date and not the upper one.
double BitcoinExchange::findRate(std::string date) {
	// find an iterator pointing to the elem. w. the smallest key that is greater than or equal to 'date'.
	std::map<std::string, double>::iterator it = _db.lower_bound(date);
	if (it != _db.end()) { // check we are not at the and of _db map
		if (it->first != date) // 'first' gives us access to key
			--it; // if match for 'date' NOT found, move iterator to the closest earlier date.
		return it->second; // 'second' gives us access to value (return the exchange rate for the date)
	}
	else if (!_db.empty()) 
		// if 'date' is greater than any date in the map, use the exchange rate for the latest available date.
		return (--it)->second;
	// if map is empty or 'date' is before any date in the map, return -1 (no exchange rate is available)
	return -1;
}

void BitcoinExchange::showExchange(std::string input_file) {
	std::ifstream input_stream(input_file.c_str());
	std::string buffer;
	if(!input_stream.is_open()) {
		std::cerr << ERR_FILE;
		return;
	}
	getline(input_stream, buffer, '\n');
	if (buffer != IN_HEADER) {
		std::cerr << ERR_HEADER << buffer << "\n";
	}
	while (getline(input_stream, buffer, '\n')) {
		if(!validInputLine(buffer)) { // check all lines for length and separator
			std::cerr << ERR_BAD_INPUT << buffer << "\n";
			continue;
		}
		std::string date = buffer.substr(0, 10);
		std::string raw_value = buffer.substr(13);
		if(!validDate(date)) { // a valid date will always be in the following format: Year-Month-Day.
			std::cerr << ERR_DATE << buffer << "\n";
			continue;
		}
		if(!validValue(raw_value)) // a  valid value must be either a float or a positive integer, between 0 and 1000.
			continue;

		double rate = findRate(date);
		if (rate == -1) {
			std::cerr << ERR_EXCHANGE << buffer << "\n";
			continue;
		}
		std::cout << date << " => " << raw_value << " = " 
			<< atof(raw_value.c_str()) * rate << "\n";
	}
}
