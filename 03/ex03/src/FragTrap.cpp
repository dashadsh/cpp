/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 20:21:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

// --------------------- CONSTRUCT -----------------------------

// Default
FragTrap::FragTrap(void) : ClapTrap("Fragtrap default robot") {
	_hitPoints = 101;
	_energyPoints = 91;
	_attackDamage = 31;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Parametrized
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 101;
	_energyPoints = 91;
	_attackDamage = 31;
	std::cout << "FragTrap constructor called with name: " << _name << std::endl;
}

// Copy
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// ------------------------ DESTRUCT -----------------------------
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called with name: " << _name << std::endl;
}

// ------------- COPY ASSIGNMENT OPERATOR ---------------------------
FragTrap& FragTrap::operator=(FragTrap const &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

// --------------------- FUNC. ---------------------------
// void FragTrap::attack(const std::string& target) {

// 	if (this->_hitPoints == 0)
// 		std::cout << "FragTrap " << this->_name << " is dead and cannot attack." << std::endl;
// 	else if (this->_energyPoints == 0)
// 		std::cout << "FragTrap " << this->_name << " does not have energy points and cannot attack." << std::endl;
// 	else
// 	{
// 		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
// 		this->_energyPoints--;	
// 	}
// }

void FragTrap::set_hit_points(void) {
	this->_hitPoints = 101;
}

void FragTrap::set_energy_points(void) {
	this->_energyPoints = 91;
}

void FragTrap::set_attack_damage(void) {
	this->_attackDamage = 31;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " is asking for high fives!" << std::endl;
}
