/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:19:07 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"
#include <iostream>

int main (void) 
{
    {
        /*
            this block tests the basic functionality of the Brain class and
            its integration with the Dog class. A Dog object named "doggo" is created,
            and then thoughts are added to its Brain using the setThought() method.
            
            These thoughts can be retrieved and displayed using the getThought() method.
            We can observe the functioning of these methods and the interaction between 
            the Dog and Brain classes in this part of the code.
        */
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "------------------- test the basic implementation of brain ---------------------" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;
        
        Dog doggo;
		doggo.makeSound();
        doggo.setThought(0, "Is that bacon I smell?");
        doggo.setThought(1, "Time to take another nap.");
        doggo.setThought(2, "Wait, was that a squirrel?!");
        doggo.setThought(3, "What if I never find out who's a good boy?");
        for (int i = 0; i < 4; i++)
            std::cout << "Dog's thought #" << i+1 << ": " << doggo.getThought(i) << std::endl;
        for (int i = 4; i < 100; i++)
            doggo.setThought(i, "I am dog!");
        std::cout << "Dog's thought #69: " << doggo.getThought(68) << std::endl;
    }
    
    {
         /*
            This block of code tests the deep copy functionality of the Dog class using the copy constructor. 
            A Dog object named "braian" is created and a deep copy of this object is made 
            using the COPY CONSTRUCTOR. Then, the original dog's thought is changed and 
            the thoughts of the original and the copy are printed to confirm that the copy 
            is not affected by changes in the original object, confirming deep copy functionality.
        */
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "---------------------- test for deep copy of copy constructor ---------------------" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;
        
        Dog doggo;
        doggo.setThought(0, "Who left this shoe here? Free chew toy!");
        Dog copyDoggo = doggo;
        copyDoggo.makeSound();
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;

        std::cout << std::endl << "----- change the original's thought and confirm it doesn't change the copy ----" << std::endl << std::endl;
		
        doggo.setThought(0, "Is it dinner time yet?");
        std::cout << "Original Dog's thought #1: " << doggo.getThought(0) << std::endl;
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;
		std::cout << "----------------------------- 2nd test ---------------------------------" << std::endl << std::endl;
		Dog basic;
		basic.setThought(0, "HMMMMMMMMMMMMMMMM..........................");
		{
			Dog tmp = basic;
		}
		std::cout << "Basic Dog's thought #1: " << basic.getThought(0) << std::endl;
    }

    {
        /*
            This block of code tests the deep copy functionality of the Dog class using the 
			ASSIGNMENT OPERATOR(copy assignment). 
            A Dog object named "braian" is created and a deep copy of this object is made 
            using the assignment operator. Then, the original dog's thought is changed and 
            the thoughts of the original and the copy are printed to confirm that the copy 
            is not affected by changes in the original object, confirming deep copy functionality.
        */
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "-----------------  test for deep copy of assignment operator ------------------" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

        Dog doggo;
        doggo.setThought(0, "This tail just won't stop following me!");
		// This triggers the assignment operator, which makes a deep copy of `braian`
        Dog copyDoggo(doggo);
        copyDoggo.makeSound();
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;

        std::cout << std::endl << "----- change the original's thought and confirm it doesn't change the copy ----" << std::endl << std::endl;
		
        doggo.setThought(0, "I should bark at the mailman again.");
        std::cout << "Original Dog's thought #1: " << doggo.getThought(0) << std::endl;
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;
    }

	{
    std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------  array of Animal obj -------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

    // Declare an array of 10 Animal pointers.
    Animal *array[10];

    for (int i  = 0; i < 10; i++)
    	{
        	// If i is less than 5, assign the i-th Animal pointer to point to a new Dog object.
       		// Else, assign it to a new Cat object.
    	    if (i < 5) {
         	   array[i] = new Dog();
     	 	} else {
        	    array[i] = new Cat();
      		}
    	}

    // Loop through the array of Animal pointers.
    for (int i = 0; i < 10; i++)
    	{
       		// Have the i-th animal make a sound. Because makeSound is a virtual method in Animal,
    	    // this will correctly call the Dog's makeSound if the animal is a Dog, or Cat's makeSound if it's a Cat.
     		array[i]->makeSound();

       		// Delete the i-th animal to free memory. Because Animal's destructor is virtual,
        	// this will correctly call the Dog's destructor if the animal is a Dog, or Cat's destructor if it's a Cat.
        	delete array[i];
    	}
		
	// DYNAMIC POLYMORPHISM
	// makeSound is defined in the Animal class and overridden in the Dog and Cat classes. 
	// So we can call it directly on any Animal ptr, bcs it's a virtual function, 
	// the correct version (Dog or Cat) will be called based on the actual type of the object. 
	// W/o virtual functions, the calls to makeSound() would not be dynamically bound, 
	// and the base class's version of makeSound() would be called for all objects.
	// Here we're allowing objects of different derived classes to be treated uniformly 
	// through a ptr to the base class.
	}


    {
        /*
            This block of code tests for potential memory leaks. Dog and Cat objects are created and immediately deleted. 
            If there are no memory leaks, the Dog and Cat destructors will correctly report the destruction of the objects. 
            This block thus serves as a simple memory management test for our program.
        */
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "------------------------ extra tests for leak ----------------------------------" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
 
    {
        /*
            This block of code highlights the importance of declaring destructors as virtual in base classes. 
            An instance of Cat is created and then deleted through a pointer of type Cat. 
            As the destructors in both Animal and Cat are declared as virtual, the most derived class's destructor 
            (in this case, Cat's destructor) is invoked first, followed by the base class's destructor. 
            This ensures proper cleanup of all resources that the object might have acquired.
        */
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "------------------ if the destructor is not virtual ----------------------------" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

        Cat *cyborg = new Cat();
		// create a pointer cyborg that points to a dynamically allocated object of the Cat class.
		
        cyborg->setThought(0, "I'm a cat with an identity crisis.");
        delete cyborg; 
		std::cout << std::endl;
    }

    return 0;
}
