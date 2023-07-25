/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 14:38:26 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_MATERIA_CLASS_H
# define CURE_MATERIA_CLASS_H

# include "AMateria.hpp"

// concrete class that inherits from AMateria and implements its 
// clone() and use() functions.

class Cure : public AMateria {
	public:
		// initializes the Cure materia with type "cure".
		Cure();

		// creates a new Cure materia by copying an existing one.
		Cure(const Cure& src);

		~Cure();

		// Overloaded assignment operator assigns the type of another Cure materia to the current one.
		Cure& operator=(const Cure& src);

		// clone creates a new Cure materia and returns a pointer to it.
		AMateria* clone() const;

		// use applies the effect of the Cure materia on a character.
		void use(ICharacter& target);
};


#endif