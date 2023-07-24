/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:26 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 20:19:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

// --------------------- CONSTRUCT. -----------------------------

// ClapTrap default constructor is called, which initializes _hitPoints, _energyPoints, and _attackDamage 
// with the values provided in ClapTrap's constructor (10, 10, 0 respectively).
// After ClapTrap constructor finishes, the ScavTrap constructor body executes, reassigning _hitPoints, _energyPoints, and _attackDamage 
// to the values you specified (100, 50, 20).
// This is inefficient BUT WORKS

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap() {

	this->_name = name;
	this->_hitPoints = 101;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;

}

// Copy constructor
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap() {
	
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "ScavTrap copy constructor called" << std::endl;

}

// --------------------- DESTRUCT. -----------------------------
ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap destructor called with name: " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs) {
	
	this->_attackDamage = rhs.getAttackDamage();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_hitPoints = rhs.getHitPoints();
	this->_name = rhs.getName();
	
	return (*this);

}

// --------------------- FUNC. ---------------------------

void ScavTrap::set_hit_points(void) {	
	this->_hitPoints = 100;
}

void ScavTrap::set_energy_points(void) {
	this->_energyPoints = 50;
}

void ScavTrap::set_attack_damage(void) {
	this->_attackDamage = 20;
}


void ScavTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have energy points and cannot attack." << std::endl;
	else	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;	
	}
}

void ScavTrap::guardGate() {

	std::cout << "ScavTrap " << this->_name << " is in gatekeeper mode" << std::endl;
}