#include <iostream>
#include <string> // std::string.

#ifndef CONTACT_H
# define CONTACT_H

// constructors and destructors should be declared as public in your class. 
// because you usually want to allow code outside the class to create and destroy 
// instances of the class. 

class Contact {
public:
    Contact(); // CPP use the name of the class for constructor
    ~Contact(); // and the name of the class for destructor
    
	// Getters
	// it's common to declare methods that don't modify the object as const. 
	// This lets the compiler know that the method won't modify the object, 
	// and allows you to call the method on a const object. 
	// It's common to declare getter methods as const because they typically 
	// don't need to modify the object:
	// int get_idx() const;
    // std::string get_first_name() const;
	int get_idx();
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_nbr();
	std::string	get_darkest_secret(void);

    // Setters
	// Passing by const reference (const std::string&) instead of by value (std::string) 
	// is a common optimization when the function doesn't need to modify the original argument.
	// This avoids the cost of copying the string, which can be expensive for large strings. 
	// The const keyword ensures that the function doesn't modify the passed string.
	void set_idx(int val);
    void set_first_name(std::string val);
    void set_last_name(std::string val);
    void set_nickname(std::string val);
    void set_phone_nbr(std::string val);
    void set_darkest_secret(std::string val);

private:
    int idx;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_nbr;
    std::string _darkest_secret;
};

#endif