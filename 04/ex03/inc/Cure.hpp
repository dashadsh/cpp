/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/11 22:21:37 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_MATERIA_CLASS_H
# define CURE_MATERIA_CLASS_H

# include "AMateria.hpp"

// Cure class, inheriting from AMateria.
// represents a specific type of materia which is capable of healing wounds.

class Cure : public AMateria {
	public:
		// Default constructor initializes the Cure materia with type "cure".
		Cure();

		// Copy constructor creates a new Cure materia by copying an existing one.
		Cure(const Cure& src);

		// Destructor cleans up the Cure materia.
		~Cure();

		// Overloaded assignment operator assigns the type of another Cure materia to the current one.
		Cure& operator=(const Cure& src);

		// clone creates a new Cure materia and returns a pointer to it.
		AMateria* clone() const;

		// use applies the effect of the Cure materia on a character.
		void use(ICharacter& target);
};


#endif