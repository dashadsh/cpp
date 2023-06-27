#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>

// The Harl class declaration
// In the Harl class, each complaint level has its own member function: 
// debug, info, warning, and error. 
// The syntax to declare a pointer to one of these functions looks like 
// void (Harl::*)(), which means
// "a PTR to a member func. of the Harl class that takes no args and returns void".
class Harl {
public:
    // Public function to make Harl complain
    void complain(std::string level);

private:
    // Private member functions for each level of complaint

    // Debug level complaint
    void _debug();

    // Info level complaint
    void _info();

    // Warning level complaint
    void _warning();

    // Error level complaint
    void _error();
};

#endif
