/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 22:25:17 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type; // private attribute to store the weapon type

public:
    Weapon(std::string type); // constructor to initialize the weapon type
//	Weapon(const std::string& type); // BETTER PRACTICE
	~Weapon();

	const std::string& getType() const;
    void setType(std::string newType); // member func. to set the weapon type
//	void setType(const std::string& newType); // BETTER PRACTICE
};

#endif

/*
const std::string& getType(); - 
This function returns a const reference to an std::string which cannot be changed.

std::string& getType() const; - 
This is a const member function, which means the function promises not to change 
any member variables of the object it's called on.
*/