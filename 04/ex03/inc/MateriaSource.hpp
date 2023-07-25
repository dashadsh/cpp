/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:20:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 12:14:00 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include "IMateriaSource.hpp"

// This class represents a source of Materia, 
// where each Materia has a type and can be created or learned. 
// The class keeps track of known Materias and allows for creation of a Materia of a specific type. 
// If a type is not known, it returns a null pointer.

// has an array of AMateria* to store the learned Materias.

// implementation of the IMateriaSource interface.
class MateriaSource : public IMateriaSource {
	public:
		//Default constructor
		MateriaSource();

		//Copy constructor
		MateriaSource(const MateriaSource& src);

		~MateriaSource();

		// Assignment operator
		MateriaSource& operator=(const MateriaSource& src);

		// Learn a new Materia
		// @param m pointer to the Materia to learn
		void learnMateria(AMateria* m);

		// Create a Materia
		// @param type the type of the Materia to create
		// @return pointer to the newly created Materia
		AMateria* createMateria(const std::string& type);

		// Display known Materia recipes
		void displayKnownRecipes();

	private:
		// Maximum amount of Materias this MateriaSource can know
		static const int _maxRecipes = 4;

		// Array of pointers to known Materias
		AMateria* _recipes[_maxRecipes];

		// Initialize the known Materia array with NULL pointers
		void _initializeEmptyRecipes();

		// Delete all known Materias and set their pointers to NULL
		void _deleteRecipes();
};

#endif
