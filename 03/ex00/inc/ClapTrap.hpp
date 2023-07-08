/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:24:11 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
public:
	ClapTrap(); // Default constructor
	ClapTrap(std::string name); // Parameterized constructor
	ClapTrap(ClapTrap const &src); // Copy constructor
	
	~ClapTrap(void); // Destructor

	ClapTrap & operator=(ClapTrap const &rhs); // Assignment operator

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int	getHitPoints(void) const;
	int	getEnergyPoints(void) const;
	int	getAttackDamage(void) const;
	
private:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;	
};

#endif