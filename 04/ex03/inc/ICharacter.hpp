/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iCharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:56 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 13:48:57 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

# include "AMateria.hpp"
# include <string>

class AMateria;

// ICharacter is an interface 
// that provides common character operations
// Contains pure virtual functions that need to be implemented by its derived classes.

// Character will implement ICharacter interface

class ICharacter {
	public:
		virtual ~ICharacter() {}

		// @return reference to the character's name
		virtual const std::string& getName() const = 0;

		// @param m pointer to the Materia to equip
		virtual void equip(AMateria* m) = 0;

		// @param idx index of the Materia to unequip
		virtual void unequip(int idx) = 0;
		
		// @param idx index of the Materia to use
		// @param target reference to the character to use the Materia on
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif