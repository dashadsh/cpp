/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:20:24 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 15:16:43 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

// ------------------------ constructor + destructor ------------------------------------
// The part after the colon : is called the initializer list. 
// It initializes the member variables of the Contact class with the specified values. 
// Each member variable is followed by its initializer in parentheses.
Contact::Contact() {}
Contact::~Contact() {}

// ------------------------------ getters -----------------------------------------------
std::string Contact::get_first_name() const {
    return _first_name;
}
std::string Contact::get_last_name() const {
    return _last_name;
}
std::string Contact::get_nickname() const {
    return _nickname;
}
std::string Contact::get_phone_nbr() const {
    return _phone_nbr;
}
std::string Contact::get_darkest_secret() const {
    return _darkest_secret;
}

// ----------------------------------- setters -----------------------------------------
void Contact::set_first_name(const std::string& value) {
    _first_name = value;
}
void Contact::set_last_name(const std::string& value) {
    _last_name = value;
}
void Contact::set_nickname(const std::string& value) {
    _nickname = value;
}
void Contact::set_phone_nbr(const std::string& value) {
    _phone_nbr = value;
}
void Contact::set_darkest_secret(const std::string& value) {
    _darkest_secret = value;
}
