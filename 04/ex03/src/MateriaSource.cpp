/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:31 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/16 19:19:49 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/MateriaSource.hpp"
#include <iostream>


MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called." << std::endl;
	this->_initializeEmptyRecipes();
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
	this->_initializeEmptyRecipes();
	*this = src;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called." << std::endl;
	this->_deleteRecipes();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	std::cout << "MateriaSource assignment operator overload called." << std::endl;
	this->_deleteRecipes();
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (src._recipes[i] != NULL)
			this->_recipes[i] = src._recipes[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) {
		std::cout << "MateriaSource was not provided with a materia to learn." << std::endl;
		return;
	}
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] == NULL) {
			this->_recipes[i] = materia;
			std::cout << "MateriaSource learned the " << materia->getType() << " materia recipe." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource can't learn any more materia." << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] && this->_recipes[i]->getType() == type) {
			return this->_recipes[i]->clone();
		}
	}
	std::cout << "MateriaSource does not know the type \"" << type << "\"." << std::endl;
	return NULL;
}

void MateriaSource::_initializeEmptyRecipes() {
	for (int i = 0; i < this->_maxRecipes; i++)
		this->_recipes[i] = NULL;
}

void MateriaSource::_deleteRecipes() {
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] != NULL) {
			delete this->_recipes[i];
			this->_recipes[i] = NULL;
		}
	}
}

void MateriaSource::displayKnownRecipes() {
	std::cout << "MateriaSource knows the following recipes:" << std::endl;
	for (int i = 0; i < this->_maxRecipes; i++) {
		std::cout << "\t[" << i << "] ";
		if (this->_recipes[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_recipes[i]->getType() << " materia.";
		std::cout << std::endl;
	}
}