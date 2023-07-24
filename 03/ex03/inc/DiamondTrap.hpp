/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:03:38 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 20:23:49 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
DiamondTrap is derived from both FragTrap and ScavTrap. 
This is a case of multiple inheritance in C++ !!!

SIC! FragTrap and ScavTrap are virtually inherited to avoid the diamond problem 
(which is when a class has two copies of a grandparent class's members due to multiple inheritance). 

DiamondTrap has own:
_name data member
whoAmI() function to reveal its name. 

It overrides the attack() function, borrowing its implementation from ScavTrap.
*/
class DiamondTrap : public ScavTrap, public FragTrap {

public:

    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &src);

    ~DiamondTrap();

    DiamondTrap& operator=(DiamondTrap const &rhs);

	// std::string	getDiamondName();
	// void setDiamondName(std::string name);
	
	using	ScavTrap::attack;
    // void attack(const std::string& target);
	
    // new function to reveal the name
    void    whoAmI();

	
	private:
    std::string _name;
	// The DiamondTrap class will have a name private attribute. 
	// Give to this attribute exactly the same variable’s name 
	// (not talking about the robot’s name here) than the one in the ClapTrap base class.

};

#endif
