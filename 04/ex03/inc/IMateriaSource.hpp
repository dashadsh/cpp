/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:59 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 12:12:47 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMATERIASOURCE_CLASS_H
# define IMATERIASOURCE_CLASS_H

# include "AMateria.hpp"
# include <string>

// interface with pure virtual functions that need to be implemented by its derived classes.

// Will be implemented by MateriaSource
class IMateriaSource {
	public:
	
		virtual ~IMateriaSource() {}

		// Learn a new Materia
		// @param m pointer to the Materia to learn
		virtual void learnMateria(AMateria* m) = 0;

		// Create a Materia
		// @param type reference to the type of the Materia to create
		// @return pointer to the newly created Materia
		virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif