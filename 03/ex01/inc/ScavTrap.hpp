/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 11:58:39 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// scavtrap publicity inherits from claptrap class
class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	
	~ScavTrap();

	ScavTrap& operator=(ScavTrap const &rhs);

	// Overridden attack function
	void attack(const std::string& target);
	// New function
	void guardGate();

	private:
	// doesnt redeclare any attributes

};

#endif