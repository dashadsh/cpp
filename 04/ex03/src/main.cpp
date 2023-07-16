/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:18:59 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/16 20:54:33 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/MateriaSource.hpp"
#include <iostream>
#include <unistd.h>

/*
dependencies between 7 classes:
1. AMateria: 
base class for specific Materia types (Cure and Ice),
depends on the ICharacter interface, as its "use" method takes an ICharacter instance as its argument.

2. Cure and Ice: 
specific Materia types and both inherit from AMateria. 
don't have any additional dependencies outside of what they inherit from AMateria.

3. ICharacter:
interface that declares methods for handling Materias (equip, unequip, and use). 
depends on the AMateria class, as its "equip" method takes an AMateria instance as its argument.

4. Character: 
concrete class that implements the ICharacter interface. 
depends on the AMateria class (due to the methods it must implement from ICharacter), 
and it uses the AMateria instances in its own methods. 
Also has an array of AMateria pointers as part of its member data.

5. IMateriaSource: 
interface that declares methods for learning and creating Materia. 
depends on the AMateria class, as its learnMateria and createMateria methods work with AMateria instances.

6. MateriaSource: 
concrete class that implements the IMateriaSource interface. 
depends on the AMateria class (due to the methods it must implement from IMateriaSource), 
uses the AMateria instances in its own methods. 
Also has an array of AMateria pointers as part of its member data.
-----------------------------------------------------------------------------------------------
Specific Materia classes (Cure and Ice) are at the bottom of the dependency hierarchy, 
as they don't depend on any other classes in the project (except the base AMateria class). 

The Character and MateriaSource classes are at the top of the hierarchy, as they depend on all the other classes directly or indirectly. 

The interfaces (ICharacter and IMateriaSource) and the AMateria base class form a "bridge" in the middle of the hierarchy, 
allowing the top-level and bottom-level classes to interact without needing to know each other's specific implementations.
*/

void printHeader(const std::string& title) {
    std::cout << std::endl << "----------------------------------------------------" << std::endl
        << "\t" << title << std::endl
        << "----------------------------------------------------" << std::endl;
}

void	materiaSourceTest(void) {
	
	printHeader("MATERIA SOURCE TEST");
	
	std::cout << std::endl << "----- test the creation of a Materia Source -----" << std::endl << std::endl;
	MateriaSource* source = new MateriaSource();
	source->displayKnownRecipes();

	std::cout << std::endl << "---- test ability of the Materia Source to learn new recipes -----" << std::endl << std::endl;
	source->learnMateria(NULL);
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->displayKnownRecipes();

	std::cout << std::endl << "----- test the deep copy ability of a Materia Source -----" << std::endl << std::endl;
	MateriaSource* copySource = new MateriaSource(*source);
	std::cout << "original ";
	source->displayKnownRecipes();
	std::cout << "copy ";
	copySource->displayKnownRecipes();
	// verify that adding a new recipe to the original does not affect the copy
	std::cout << "original Materia Source learns another recipe:" << std::endl;
	source->learnMateria(new Cure());
	std::cout << "original ";
	source->displayKnownRecipes();
	std::cout << "copy ";
	copySource->displayKnownRecipes();
	// after testing, we delete the copied source
	std::cout << "deleting Copy Materia Source:" << std::endl;
	delete copySource;

	std::cout << std::endl << "----- test ability of the Materia Source to learn too many recipes -----" << std::endl << std::endl;
	source->displayKnownRecipes();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->displayKnownRecipes();

	std::cout << std::endl << "----- test creation of Materia from the learned recipes -----" << std::endl << std::endl;
	AMateria*	m1 = NULL;
	AMateria*	m2 = NULL;
	AMateria*	m3 = NULL;
	
	m1 = source->createMateria("ice");
	if (m1 == NULL)
		std::cout << "materia was not created." << std::endl;
	else
		std::cout << "created materia is " << m1->getType() << std::endl;
	m2 = source->createMateria("cure");
	if (m2 == NULL)
		std::cout << "materia was not created." << std::endl;
	else
		std::cout << "created materia is " << m2->getType() << std::endl;
	m3 = source->createMateria("rock");
	if (m3 == NULL)
		std::cout << "materia was not created." << std::endl;
	else
		std::cout << "created materia is " << m2->getType() << std::endl;
	if (m1 != NULL)
		delete m1;
	if (m2 != NULL)
		delete m2;
	if (m2 != NULL)
		delete m3;

	std::cout << std::endl << "----- delete the source -----" << std::endl << std::endl;
	delete source;
}

void	characterTest(void)
{
	printHeader("CHARACTER TEST");
	std::cout << std::endl << "----- create Materias to be used in following test -----" << std::endl << std::endl;
	AMateria *	m1 = new Cure();
	AMateria *	m2 = new Cure();
	AMateria *	m3 = new Cure();
	AMateria *	m4 = new Ice();
	AMateria *	m5 = new Ice();
	AMateria *	m6 = new Ice();

	std::cout << std::endl << "----- test the creation of a Character -----" << std::endl << std::endl;
	Character*	emily = new Character("Emily");
	emily->displayInventory();

	std::cout << std::endl << "----- tests the ability of a Character to equip items -----" << std::endl << std::endl;
	emily->equip(NULL);
	emily->equip(m1);
	emily->equip(m2);
	emily->displayInventory();

	std::cout << std::endl << "----- test the deep copy ability of a Character -----" << std::endl << std::endl;
	Character*	emilyCopy = new Character(*emily);
	std::cout << "changing copy's name from \"" << emilyCopy->getName()
		<< "\" to \"copy\"." << std::endl;
	emilyCopy->setName("copy");
	emily->displayInventory();
	emilyCopy->displayInventory();
	emily->equip(m3);
	emily->displayInventory();
	emilyCopy->displayInventory();
	std::cout << "deleting copy character:" << std::endl;
	delete emilyCopy;

	std::cout << std::endl << "----- test the Character's ability to handle equipping too many items -----" << std::endl << std::endl;
	emily->displayInventory();
	emily->equip(m4);
	emily->equip(m5);
	emily->equip(m6);
	emily->displayInventory();

	std::cout << std::endl << "----- tests the Character's ability to unequip items -----" << std::endl << std::endl;
	emily->unequip(-1);
	emily->unequip(10000);
	emily->unequip(4);
	emily->unequip(2);
	emily->displayInventory();
	emily->equip(m5);
	emily->displayInventory();
	emily->unequip(1);
	emily->unequip(2);
	emily->displayInventory();
	emily->unequip(2);

	std::cout << std::endl << "----- test the unequip operation does not delete the item -----" << std::endl << std::endl;
	std::cout << "1. creating a tmp materia of type cure:" << std::endl;
	AMateria* tmp = new Cure();
	std::cout << "2. equipping the tmp materia:" << std::endl;
	emily->equip(tmp);
	std::cout << "3. unequipping the tmp materia:" << std::endl;
	emily->unequip(1);
	std::cout << "4. deleting the tmp materia:" << std::endl;
	delete tmp;

	std::cout << std::endl << "----- delete the Character -----" << std::endl << std::endl;
	delete emily;

	std::cout << std::endl << "----- clean up any remaining unequipped Materia -----" << std::endl << std::endl;
	delete m2;
	delete m3;
	delete m5;
	delete m6;
}

void	actionTest(void) {
	printHeader("BATTLE MODE");
	std::cout << std::endl << "----- create MateriaSource -----" << std::endl << std::endl;
	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	std::cout << std::endl << "----- MateriaSource creates items -----" << std::endl << std::endl;
	int const	nb_items = 6;
	AMateria* materias[nb_items + 1];
	materias[nb_items] = NULL;

	std::cout << "----- creating an array of " << nb_items << " materias. -----" << std::endl << std::endl;
	for (int i = 0; i < nb_items; i++)
	{
		if (i % 2)
			materias[i] = source->createMateria("ice");
		else
			materias[i] = source->createMateria("cure");
	}
	std::cout << std::endl;

	std::cout << std::endl << "----- creating characters -----" << std::endl << std::endl;
	ICharacter* igor = new Character("Igor");
	Character*	jessica = new Character("Jessica");

	std::cout << std::endl << "----- equipping characters -----" << std::endl << std::endl;
	for (int i = 0; i < nb_items / 2; i++)
		igor->equip(materias[i]);
	for (int i = nb_items / 2; i < nb_items; i++)
		jessica->equip(materias[i]);

	std::cout << std::endl << "----- battle -----" << std::endl << std::endl;
	igor->use(-42, *igor);
	igor->use(42, *igor);
	jessica->use(3, *igor);
	igor->use(2, *igor);
	igor->use(1, *jessica);
	igor->use(1, *jessica);
	jessica->use(1, *jessica);
	jessica->use(2, *igor);
	jessica->use(1, *igor);
	igor->use(0, *jessica);

	std::cout << std::endl << "----- delete characters -----" << std::endl << std::endl;
	delete igor;
	delete jessica;

	std::cout << std::endl << "----- delete MateriaSource -----" << std::endl << std::endl;
	delete source;
}

int	main(void) {
	std::cout << std::endl;
	// materiaSourceTest();
	// characterTest();
	// actionTest();
	
	/* declare src as PTR to an IMateriaSource, which is an interface,
	BUT
	actual object that src points to is a MateriaSource, 
	which is a concrete class implementing the IMateriaSource interface.
	
	code is not tightly coupled to the MateriaSource implementation. 
	we can change the actual class of the object that src points to (as long as it implements IMateriaSource), 
	and the rest of the code won't need to change:

	IMateriaSource* src = new AdvancedMateriaSource(); */
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	
	/* calling the learnMateria method on the MateriaSource obj and passing it a new Ice object - 
	Ice object is also on the heap. 
	learnMateria method will store the Ice obj inside the MateriaSource so that it can create copies of it later */
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	/* creating new Character object on the heap and storing its address in a pointer me of type ICharacter*. 
	Character obj is where you will store and use Materia objects.*/
	ICharacter* me = new Character("me");
	std::cout << std::endl;
	
	/* declares a pointer of type AMateria* but does not initialize it. 
	this pointer will be used to hold the addresses of new Materia obj's that are created. */
    AMateria* tmp;
	/* calls the createMateria method on the MateriaSource object and passes it the string "ice".
	createMateria method will create a new Ice object on the heap and return its address. 
	this address is then stored in tmp.*/
    tmp = src->createMateria("ice");
	/* calls the equip method on the Character object and passes it the address of the Ice object,	
	equip method will store the Ice object inside the Character so that it can be used later.*/
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	std::cout << std::endl;
	
	ICharacter* bob = new Character("bob"); 
	std::cout << std::endl;
	
	/* calls the use method on the Character object, indicating that it should use the 
	first equipped Materia (idx 0) on the character bob.*/
	me->use(0, *bob);
    me->use(1, *bob);
	std::cout << std::endl;
	
	delete bob; 
	delete me; 
	delete src;
	
	return 0;
}

/*
interfaces are typically used to define a minimum set of methods that a class must implement.
-------------------------------------------------------
ICharacter interface provides a common blueprint for character-like objects in the game
& specifies that any class implementing it must have:
getName(), equip(), unequip(), and use() methods.

Character class is an implementation of ICharacter, it defines these methods in its own way according to its own needs. 
when the method use() in the AMateria class is called, it takes an ICharacter type as its parameter:
			virtual void use(ICharacter& target);
this doesn't mean it only takes the Character class as its parameter =>
it can take any class object that implements the ICharacter interface because the specific implementation doesn't matter. 
What's important is that the class has the required use() method !!!

Let's add a new class, SuperCharacter, that has additional abilities compared to a regular Character - 
as long as this SuperCharacter class implements the ICharacter interface, 
we can use AMateria on it just like a regular Character, and we don't need to change anything in the AMateria class or its use() method:
			SuperCharacter superHero("SuperHero");
			Ice iceMateria;
			iceMateria.use(superHero);  // this is perfectly valid !!!
-------------------------------------------------------
IMateriaSource interface ensures that any class implementing it, like MateriaSource, 
has the learnMateria() and createMateria() methods - 
this allows for flexible use of different materia source implementations in your code.

If we decide to add a SuperMateriaSource class which learns and creates materias in a different way, we can do so easily. 
As long as SuperMateriaSource implements the IMateriaSource interface, 
we can use it anywhere in your code where IMateriaSource is required:
			SuperMateriaSource superSource;
			superSource.learnMateria(new Cure());
*/
