/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:37 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/16 20:39:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include <string>
# include "ICharacter.hpp"

// Forward declaration of the ICharacter class. 
// bc ICharacter type is used in the declaration of the AMateria class - 
// follows before it is actually defined.
class ICharacter;

class AMateria
{
	public:
		// Default constructor.
		AMateria(void);

		// Copy constructor.
		// AMateria(AMateria const & src);
		AMateria(const AMateria& src);

		// Parameterized constructor.
		// AMateria(std::string const & type);
		AMateria(const std::string& type);

		// virtual destructor
		virtual ~AMateria(void);

		// assignment operator overload.
		AMateria& operator=(const AMateria& src);

		// returns the type of the AMateria object.
		std::string const & getType(void) const;

		// pure virtual function for cloning the AMateria object. 
		// must be overridden in all non-abstract derived classes!
		virtual AMateria* clone(void) const = 0;

		// uses the AMateria on the given character. 
		// exact effects may depend on the specific type of AMateria and character.
		// virtual void use(ICharacter & target);
		virtual void use(ICharacter& target);

	protected:
		// type of the AMateria. may be used to determine its effects when used on a character.
		std::string	_type; // NEW

};

#endif
