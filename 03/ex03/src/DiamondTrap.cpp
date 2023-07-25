/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:04:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 21:55:48 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// Due to virtual inheritance, DiamondTrap inherits only one instance of ClapTrap, 
// which is shared by both FragTrap and ScavTrap. 
// As a result, you cannot have different values for _attackDamage depending on 
// whether DiamondTrap behaves like a FragTrap or a ScavTrap.
// 

DiamondTrap::DiamondTrap() : _name("default name") {
	std::cout << "Diamond default constructor called.\n";
	this->FragTrap::set_hit_points();
	this->ScavTrap::set_energy_points();
	this->FragTrap::set_attack_damage();
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::set_hit_points();
	this->ScavTrap::set_energy_points();
	this->FragTrap::set_attack_damage();
	std::cout << "Diamond (with name:" << name << ") constructor is called.\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond destructor called.\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src.getName()), ScavTrap(src.getName()), FragTrap(src.getName()){
	std::cout << "Diamond copy constructor called.\n";
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	
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
	std::cout << "My name is : " << this->_name << " and my ClapTrap name is : " << this->ClapTrap::_name << std::endl;
}

// void DiamondTrap::setDiamondName(std::string name) {
//     _name = name;
// }

// std::string DiamondTrap::getDiamondName(void) {
//     return (_name);
// }

// void	DiamondTrap::attack(const std::string &target) {
// 	ScavTrap::attack(target);
// }
