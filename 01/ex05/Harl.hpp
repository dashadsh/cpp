#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

// In the Harl class, each complaint level has its own member function: 
// debug, info, warning, and error. 
// The syntax to declare a pointer to one of these functions looks like void (Harl::*)(), 
// which means "a PTR to a member func. of the Harl class that takes no args and returns void".

class Harl {
public:
	Harl(void);
    ~Harl (void);

    void complain(std::string level); // Public function to make Harl complain

private:	// Private member functions for each level of complaint

    void _debug();    // Debug level complaint
    void _info();	   // Info level complaint
    void _warning();    // Warning level complaint
    void _error();    // Error level complaint
};

#endif
