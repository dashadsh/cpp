/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:47:30 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include <iostream>

int main (void) 
{
	// {
	// const WrongAnimal* i = new WrongCat();
	// std::cout << i->getType() << " " << std::endl; 
	// i->makeSound(); // will output WrongSound
	// }

    /* -------------------------------------
    Testing Block: Basic Animal Class 
    ------------------------------------- */
    std::cout << "\n---------- Testing basic implementation of Animal ----------\n";

    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << "Dog's Type: " << j->getType() << std::endl;
        std::cout << "Dog makes sound: "; 
        j->makeSound(); //will output the cat sound!
        
        std::cout << "Cat's Type: " << i->getType() << std::endl;
        std::cout << "Cat makes sound: "; 
        i->makeSound();
        
        std::cout << "Animal makes sound: ";
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }

    /* -------------------------------------
    Testing Block: Wrong Animal Class 
    ------------------------------------- */
    std::cout << "\n---------- Testing basic implementation of WrongAnimal ----------\n";

    {
        const WrongAnimal *wrongMeta = new WrongAnimal();
        const WrongCat     *wrongGatto = new WrongCat();

        std::cout << "WrongAnimal makes sound: ";
        wrongMeta->makeSound();
        
        std::cout << "WrongCat makes sound: ";
        wrongGatto->makeSound();

        delete wrongMeta;
        delete wrongGatto;
    }

    /* -------------------------------------
    Testing Block: Assignment operator 
    ------------------------------------- */
    std::cout << "\n---------- Testing assignment operator ----------\n";

    {
        Cat     gatto; // Create a Cat object
        Animal  animal_one; // Create an Animal object

        animal_one = gatto; // Object slicing occurs, the Cat part of gatto is "sliced" off,
                    // and only the Animal part is assigned to animal_one.
        std::cout << "Animal assigned from Cat makes sound: ";
        animal_one.makeSound(); //output: animal sound, not cat sound.
					// it only has the Animal behavior and outputs "Animal sound."
					
		//this is not possible: gatto = animal_one;
		//cannot assign a base class object to a derived class object.
    }

    /* -------------------------------------
    Testing Block: Polymorphism 
    ------------------------------------- */
    std::cout << "\n---------- Testing Polymorphism ----------\n";

    {
        Animal *gatto = new Cat(); 

        std::cout << "Dynamic type Cat assigned to base type Animal makes sound: ";
        gatto->makeSound();// meaow --> although it is animal, the sound is cat sound bcz it is dynamic polymorphism.
							// thanks to PTR!
		
        delete gatto;
    }

    /* -------------------------------------
    Testing Block: Basic Cat and Dog Class 
    ------------------------------------- */
    std::cout << "\n---------- Testing basic implementation of Cat and Dog ----------\n";

    {
        Cat cat;
        Dog dog;
        
        std::cout << "Cat makes sound: ";
        cat.makeSound();
        
        std::cout << "Dog makes sound: ";
        dog.makeSound();
    }

    /* -------------------------------------
    Testing Block: WrongCat Class and Non-polymorphism
 test to see what happens when the makeSound function is not virtual in wrongAnimal  
    ------------------------------------- */
    std::cout << "\n---------- Testing WrongCat and non-polymorphism ----------\n";

    {
        WrongAnimal *animal_two = new WrongCat();
        std::cout << "Dynamic type WrongCat assigned to base type WrongAnimal makes sound: ";
        animal_two->makeSound();
		// WRONG ANIMAL'S NOISES --> although it is allocated dynamically, since it is not a virtual function, it is not polymorphic.
        // so we wont see meaw.
		// Since the makeSound() function in the WrongAnimal class is not declared as virtual, 
		// the call to makeSound() on a WrongCat object through a WrongAnimal pointer will invoke the function from the WrongAnimal class, 
		// not the one from the WrongCat class.

        WrongCat    gatto;
        WrongAnimal animal_three;
        
        animal_three = gatto;
        std::cout << "WrongAnimal assigned from WrongCat makes sound: ";
        animal_three.makeSound(); //  WRONG ANIMAL'S NOISES as we expected, animal sound, not cat sound.

        std::cout << "WrongCat makes sound: ";
        gatto.makeSound(); // WrongCat' sound is only outputed when using the WrongCat. because we have no polymorphism here

        delete animal_two;
    }
}
