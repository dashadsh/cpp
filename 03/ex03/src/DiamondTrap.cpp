/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:04:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 13:46:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("default name") {
	std::cout << "Diamond default constructor called.\n";
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) :  _name(name) {
	this->ScavTrap::_name = name + "_clap_name";
// _name is a protected member in ClapTrap and ScavTrap is a subclass of ClapTrap, 
// so we can access it directly in ScavTrap and its subclasses (which includes DiamondTrap)
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << "Diamond (with name:" << name << ") constructor is called.\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond destructor called.\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond) {
	std::cout << "Diamond copy constructor called.\n";
	*this = diamond;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs) {
	this->_name = rhs.getName();
	this->_hitPoints = rhs.FragTrap::getHitPoints();
	this->_energyPoints = rhs.ScavTrap::getEnergyPoints();
	this->_attackDamage = rhs.FragTrap::getAttackDamage();
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My name is :" << this->_name << " and my ClapTrap name is : " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::setDiamondName(std::string name) {
    _name = name;
}

std::string DiamondTrap::getDiamondName(void) {
    return (_name);
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
