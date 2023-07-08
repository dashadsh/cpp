/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:06 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 19:23:00 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// --------------------- CONSTRUCTOR -----------------------------
ClapTrap::ClapTrap() : _name("Claptrap default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called with name: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// -------------------------- DESTRUCTOR ------------------------------------
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called with name: " << _name << std::endl;
}

// --------------------- COPY ASSIGNMENT OPERATOR -----------------------------
ClapTrap & ClapTrap::operator=(ClapTrap const &rhs) {
	this->_attackDamage = rhs.getAttackDamage();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_hitPoints = rhs.getHitPoints();
	this->_name = rhs.getName();

	return (*this);
}

// ------------------------ FUNC. ----------------------------------------
void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have energy points and can't attack." << std::endl;
	else {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead, can't be attacked!" << std::endl;
	else if (this->_hitPoints - (int)amount > 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " dies!" << std::endl;
		this->_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is dead and can't be repaired." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have any energy points left for repair." << std::endl;
	else {
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs himself by adding " << amount << " hit points. New HP: " << this->_hitPoints << "." << std::endl;
		this->_energyPoints--;
	}
}

// -------------------------- GETTERS -----------------------------

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}
