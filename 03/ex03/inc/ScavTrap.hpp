/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:31 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 12:51:40 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"

// class ScavTrap : public ClapTrap {
class ScavTrap : virtual public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	
	~ScavTrap();

	ScavTrap& operator=(ScavTrap const &rhs);

	// Overridden attack function
	void attack(const std::string& target);
	
	void guardGate();


	private:

};

#endif