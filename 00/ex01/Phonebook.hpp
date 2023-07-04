/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:04 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PhoneBook class can: store, retrieve, and display contact information in a phone book-like structure. 
// It uses an array of Contact objects internally to store the contacts, 
// and exposes member functions to interact with and manipulate the contacts.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

	// member func sets the contact info for a specific entry in the phonebook,
	// takes: first name, last name etc. as parameters, 
	// assigns them to corresponding fields of the Contact object in the contacts array
    void set_contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
                     const std::string &phone_nbr, const std::string &darkest_secret);

	// member func prints the list of contacts stored in the phonebook,
	// retrieves the contact info from the contacts array, displays it in a formatted manner, 
	// typically using the truncate func to ensure that displayed info fits within a certain width
    void print_contacts() const;

	// member func retrieves the Contact object at the specified idx from the contacts array and returns it, 
	// allows external code to access the contact info stored in the phonebook
    Contact get_contact(int index) const;

	// member function takes a string str, truncates it to the specified width, 
	// ensuring that it fits within the desired width.
	// if the string is longer than the width, it's truncated + last displayable character is replaced by a dot, 
	// truncated string is returned
    std::string truncate(std::string str, size_t width) const;

private:
	// private members of the class
	// it's private to encapsulate the implementation details and prevent direct access from outside the class
    Contact contacts[8];
	
};

#endif