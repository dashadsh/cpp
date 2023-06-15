
#include "Contact.hpp"

// ------------------- constructor --------------------
Contact::Contact(void) {
	// std::cout << "constructor called" << std::endl;
}

// -------------------- destructor --------------------
Contact::~Contact(void) {
	// std::cout << "destructor called" << std::endl;
}

// -------------------- setters -----------------------
void	Contact::set_idx(int val) {	
	this->idx = val;
}
void	Contact::set_first_name(std::string val) {	
	this->_first_name = val;
}
void	Contact::set_last_name(std::string val) {	
	this->_last_name = val;
}
void	Contact::set_nickname(std::string val) {
	this->_nickname = val;
}
void	Contact::set_phone_nbr(std::string val) {
	this->_phone_nbr = val;
}
void	Contact::set_darkest_secret(std::string val) {
	this->_darkest_secret = val;
}

// -------------- accessors (getters) -----------------
int	Contact::get_idx(void) {
	return (this->idx);
}
std::string	Contact::get_first_name(void) {
	return (this->_first_name);
}
std::string	Contact::get_last_name(void) {
	return (this->_last_name);
}
std::string	Contact::get_nickname(void) {
	return (this->_nickname);
}
std::string	Contact::get_phone_nbr(void) {
	return (this->_phone_nbr);
}
std::string	Contact::get_darkest_secret(void) {
	return (this->_darkest_secret);
}

// std::string is a class in the C++ Standard Library that represents 
// a sequence of characters. It is used to manipulate strings of characters.

// std::string is used as the return type of the getter functions, 
// this is because the members first_name, last_name, nickname, phone_nbr, and darkest_secret 
// of the Contact class are declared as std::string types. 
// These methods return the current values of those string members.

// Ease of Use: 
// std::string provides a lot of built-in functions for manipulating and working with strings. 
// For example, you can easily concatenate two strings using the + operator.

// Dynamic Size: 
// Unlike C-style strings, which require you to manually allocate memory 
// if you need a different size, std::string can automatically adjust its size as needed.

// Safety: 
// std::string takes care of some of the memory management for you, 
// so you are less likely to encounter errors related to memory management, 
// such as buffer overflows.

// Compatibility with C++ Standard Library: 
// Many functions in the C++ Standard Library, such as those in <algorithm> and <iostream>, 
// are designed to work with std::string, which makes it easier to use these 
// library functions with your strings.