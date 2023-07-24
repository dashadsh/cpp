/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 20:17:45 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:

	ClapTrap(void); // Default constructor
	ClapTrap(std::string name); // Parameterized constructor
	ClapTrap(ClapTrap const &src); // Copy constructor

	//~ClapTrap(); // Destructor //	
	virtual ~ClapTrap(); // Destructor - RECOMMEMDED FOR CORRECT CLEAN-UP
	// base class destructorshould be virtual to correctly handle the deletion of a derived class object via a pointer to base

	ClapTrap& operator=(ClapTrap const &rhs); // Assignment operator

	virtual void attack(const std::string& target); // then we can overwrite it!
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int	getHitPoints(void) const;
	int	getEnergyPoints(void) const;
	int	getAttackDamage(void) const;

	// void setName(std::string name);
	// void setHitPoints(int hitpoints);
	// void setEnergyPoints(int energypoints);
	// void setAttackDamage(int damage);
	
protected:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;	
	// class ScavTrap inherits from class ClapTrap - 
	// use 'protected' keyword in the parent class to allow the derived class access 
	// parent's members directly.

};

#endif