#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
//////////////////////////////////////////////////////////////////////////////////////////////////
// the code must include a Contact class, 
// or whatever name the student used.
// This class must contain attributes for the 
// different fields.
//////////////////////////////////////////////////////////////////////////////////////////////////

class Contact {
public:
    Contact();
	~Contact();

	// ------------------------------ getters -----------------------------------------------
    std::string get_first_name() const;
	std::string get_last_name() const;
    std::string get_nickname() const;
	std::string get_phone_nbr() const;
    std::string get_darkest_secret() const;
	// CONST member funct. -  promises not to modify the state of the obj. on which it is called,
	// used to ensure that calling the func. won't cause any changes to the obj's data members
	//
	// getters  - simply return val of the corresponding member var's;
	// they don't modify the object's state => declare them as CONST member func's

	// ----------------------------------- setters -----------------------------------------
    void set_first_name(const std::string& value);
    void set_last_name(const std::string& value);
    void set_nickname(const std::string& value);
    void set_phone_nbr(const std::string& value);
    void set_darkest_secret(const std::string& value);
	// passing by REF. (const std::string&) instead of by VAL. (const std::string);
	// common practice when you don't need to modify the orig. arg. +
	// want to avoid unnecessary copies of the arg.
	//
	// using a ref. allows the func. to work directly with the orig. obj. w/o creating a new copy. 
	// can be more efficient, especially for large objects / when the function is called frequently
	//
	// using CONSR std::string& value, you ensure that the func. won't modify the orig. str. arg. passed to it.

private:
	// attributes (or member variables)
	// hold the values specific to EACH INSTANCE of the Contact class, 
	// allowing to store and retrieve information about individual contacts
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_nbr;
    std::string _darkest_secret;
	// std::string handles memory management for you, automatically allocating and deallocating memory 
	// as needed to store the string data.
	// An alternative to using std::string that could potentially lead to memory leaks is using raw C-style 
	// character arrays (char arrays) to store strings: char _first_name[50];
};

#endif