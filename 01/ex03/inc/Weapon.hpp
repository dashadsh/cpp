/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 12:33:00 by dgoremyk         ###   ########.fr       */
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

//	std::string getType(); // member func. to get the weapon type
	const std::string& getType() const; // BETTER PRACTICE
    void setType(std::string newType); // member func. to set the weapon type
//	void setType(const std::string& newType); // BETTER PRACTICE
};

#endif
