/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 13:59:46 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include <iostream>
#include <string>

Character::Character() : _name("Unnamed") {
	std::cout << "Character default constructor called." << std::endl;
	this->_initializeEmptyInventory();
}

Character::Character(const Character& src) {
	std::cout << "Character copy constructor called." << std::endl;
	this->_initializeEmptyInventory();
	*this = src;
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << "Character name constructor called with name \"" << this->_name << "\"." << std::endl;
	this->_initializeEmptyInventory();
}

Character::~Character() {
	std::cout << "Character destructor called for \"" << this->_name << "\"." << std::endl;
	this->_deleteInventory();
}

Character& Character::operator=(const Character& src) {
	std::cout << "Character assignment operator overload called." << std::endl;
	this->_name = src._name;
	this->_deleteInventory();
	for (int i = 0; i < this->_inventorySize; i++) {
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return *this;
}

const std::string& Character::getName() const {
	return this->_name;
}

void Character::setName(const std::string& newName) {
	this->_name = newName;
}

void Character::equip(AMateria* materia) {
	if (!materia) {
		std::cout << this->_name << ": Can't equip something that doesn't exist!" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_inventorySize; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = materia;
			std::cout << this->_name << " equipped " << materia->getType() << " materia to inventory index " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": I can't carry any more materia!" << std::endl;
}

void Character::unequip(int index) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << this->_name << ": I can't unequip anything from inventory index " << index << ". It's not a valid index!" << std::endl;
		return ;
	}
	if (this->_inventory[index] == NULL) {
		std::cout << this->_name << ": I don't have anything at index " << index << " to unequip!" << std::endl;
		return ;
	}
	std::cout << this->_name << " unequipped " << this->_inventory[index]->getType() << " materia from inventory index " << index << "." << std::endl;
	this->_inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << this->_name << ": Can't use item at inventory index " << index << ". It's not a valid index!" << std::endl;
		return ;
	}
	if (this->_inventory[index] != NULL) {
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	} else {
		std::cout << this->_name << ": Oops, I don't have an item in my inventory at index " << index << "!" << std::endl;
	}
}

void Character::displayInventory() const {
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++) {
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[i]->getType() << " materia.";
		std::cout << std::endl;
	}
}

void Character::_initializeEmptyInventory() {
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
}

void Character::_deleteInventory() {
	for (int i = 0; i < this->_inventorySize; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}
