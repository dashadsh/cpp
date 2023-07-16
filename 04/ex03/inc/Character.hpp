/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/11 22:19:44 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

// Character class inherits from ICharacter.
// represents a character in the game with a name and inventory to hold materias.

class Character : public ICharacter {
	public:
		// Default constructor 
		// initializes the character with the name "Unnamed" and an empty inventory.
		Character();

		// Copy constructor 
		// creates a new character by copying an existing one.
		Character(const Character& src);

		// Name constructor 
		// initializes a character with a specified name and an empty inventory.
		Character(const std::string& name);

		// Destructor 
		// deletes the inventory of materias and outputs a message.
		~Character();

		// Overloaded assignment operator 
		// assigns the name and inventory of another character to the current one.
		Character& operator=(const Character& src);

		// --------------------------------------------------------
		// returns the name of the character.
		const std::string& getName() const;

		// sets the name of the character to a new value.
		void setName(const std::string& newName);

		// adds a materia to the first empty slot in the inventory.
		void equip(AMateria* m);

		// removes a materia from a specified index in the inventory.
		void unequip(int idx);

		// applies a materia on a target character.
		void use(int idx, ICharacter& target);

		// outputs the content of the inventory to the console.
		void displayInventory() const;

	private:
		static const int _inventorySize = 4;
		std::string _name;
		AMateria* _inventory[_inventorySize];

		// initializes all the slots in the inventory to null
		void _initializeEmptyInventory();

		// deletes all the materias in the inventory and sets their slots to null.
		void _deleteInventory();
};

#endif