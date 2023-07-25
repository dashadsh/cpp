/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 14:38:08 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

// concrete class that implements the ICharacter interface. 
// It has an inventory of AMateria* to hold the Materias.

class Character : public ICharacter {
	public:
		// initializes the character with the name "Unnamed" and an empty inventory.
		Character();

		// creates a new character by copying an existing one.
		Character(const Character& src);

		// initializes a character with a specified name and an empty inventory.
		Character(const std::string& name);

		// deletes the inventory of materias and outputs a message.
		~Character();

		// assigns the name and inventory of another character to the current one.
		Character& operator=(const Character& src);

		// --------------------------------------------------------
		const std::string& getName() const;

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

		// // initializes all the slots in the inventory to null
		void _initializeEmptyInventory(); // PRIVATE HENCE WO DONT CALL IT FROM MAIN()

		// // deletes all the materias in the inventory and sets their slots to null.
		void _deleteInventory();  // PRIVATE HENCE WO DONT CALL IT FROM MAIN()
};

#endif