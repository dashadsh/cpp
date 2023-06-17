
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
//////////////////////////////////////////////////
// the code must include a Contact class, 
// or whatever name the student used.
// This class must contain attributes for the 
// different fields.
//////////////////////////////////////////////////

class Contact {
public:
    Contact();
	~Contact();

	// ----------- getters ------------
	int get_index() const;
    std::string get_first_name() const;
	std::string get_last_name() const;
    std::string get_nickname() const;
	std::string get_phone_nbr() const;
    std::string get_darkest_secret() const;
	// A const member function is a member function that promises not to modify the state 
	// of the object on which it is called. It is used to ensure that calling the function 
	// won't cause any changes to the object's data members.
	//
	// Getters simply return the values of the corresponding member variables. 
	// Since they don't modify the object's state, it is appropriate to declare them as const member functions.

	// ----------- setters -------------
    void set_index(int value);
    void set_first_name(const std::string& value);
    void set_last_name(const std::string& value);
    void set_nickname(const std::string& value);
    void set_phone_nbr(const std::string& value);
    void set_darkest_secret(const std::string& value);
	// Passing the parameter by reference (const std::string&) instead of by value (const std::string) 
	// is a common practice when you don't need to modify the original argument and want to avoid 
	// unnecessary copies of the argument.
	//
	// Using a reference allows the function to work directly with the original object without 
	// creating a new copy. This can be more efficient, especially when dealing with large objects or 
	// when the function is called frequently.
	//
	// By using const std::string& value, you ensure that the function won't modify the original string 
	// argument passed to it.

private:
	// attributes (or member variables)
	// hold the values specific to EACH INSTANCE of the Contact class, 
	// allowing to store and retrieve information about individual contacts
    int _index;
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