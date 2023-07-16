/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iCharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:56 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/11 22:38:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

# include "AMateria.hpp"
# include <string>

class AMateria;

// ICharacter is an interface 
// that provides common character operations

class ICharacter {
	public:
		
		// Destructor
		virtual ~ICharacter() {}

		// Get the character's name
		// @return reference to the character's name
		virtual const std::string& getName() const = 0;

		// Equip a Materia to the character
		// @param m pointer to the Materia to equip
		virtual void equip(AMateria* m) = 0;

		// Unequip a Materia from the character
		// @param idx index of the Materia to unequip
		virtual void unequip(int idx) = 0;

		// Use a Materia
		// @param idx index of the Materia to use
		// @param target reference to the character to use the Materia on
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif