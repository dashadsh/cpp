/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:52 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 12:09:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_MATERIA_CLASS_H
# define ICE_MATERIA_CLASS_H

# include "AMateria.hpp"

// concrete class that inherits from AMateria and implements its 
// clone() and use() functions.

class Ice : public AMateria {
	public:
		// Default constructor initializes the Ice materia with type "ice".
		Ice();

		// Copy constructor creates a new Ice materia by copying an existing one.
		Ice(const Ice& src);

		// Destructor cleans up the Ice materia.
		~Ice();

		// Overloaded assignment operator assigns the type of another Ice materia to the current one.
		Ice& operator=(const Ice& src);

		// clone creates a new Ice materia and returns a pointer to it.
		AMateria* clone() const;

		// use applies the effect of the Ice materia on a character.
		void use(ICharacter& target);
};


#endif