/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/10 00:25:50 by dgoremyk         ###   ########.fr       */
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
        doggo.setThought(0, "Is that bacon I smell?");
        doggo.setThought(1, "Time to take another nap.");
        doggo.makeSound();
        doggo.setThought(2, "Wait, was that a squirrel?!");
        doggo.setThought(3, "What if I never find out who's a good boy?");
        for (int i = 0; i < 4; i++)
            std::cout << "Dog's thought #" << i+1 << ": " << doggo.getThought(i) << std::endl;
        for (int i = 4; i < 100; i++)
            doggo.setThought(i, "I am dog, hear me bark!");
        std::cout << "Dog's thought #69: " << doggo.getThought(68) << std::endl;
		// declaration of Dog doggo multiple times is OK in my case bc each declaration is within a separate scope: 
		// each is within its own block of code (enclosed by {}), so they are considered separate variables.
		// Each time we enter a new block, it creates a new scope, and variables declared within that block are local to that scope. 
		// Once we exit the block, those variables are destroyed. 
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

        // here we create a new Dog object named copyBraian that is a copy of the braian object. 
        // The = operator triggers COPY CONSTRUCTOR, which is responsible for creating the new object.
        // Copy constructor performs here a deep copy. 
        // It copies all the data members of the Dog obj, including the data member that is a ptr to Brain. 
        // However, it does not just copy the pointer (which would result in a shallow copy); 
        // it creates a new Brain object on the heap and then copies all the thoughts (strings) 
        // from the original Brain to the new one.
        //
        // This way, changes to the original Dog object's Brain do not affect the copied Dog object's Brain, 
        // and vice versa. This is the essence of a deep copy.
        //
        // This is also why you need to define your own copy constructor (and assignment operator, if needed) 
        // whenever your class has data members that are pointers: 
        // the default copy constructor provided by C++ only does a shallow copy,
        // which can lead to various problems, such as double deletions or dangling ptr's.
        Dog copyDoggo = doggo;
        copyDoggo.makeSound();
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;

        std::cout << std::endl << "----- change the original's thought and confirm it doesn't change the copy ----" << std::endl << std::endl;
		
        doggo.setThought(0, "Is it dinner time yet?");
        std::cout << "Original Dog's thought #1: " << doggo.getThought(0) << std::endl;
        std::cout << "Copied Dog's thought #1: " << copyDoggo.getThought(0) << std::endl;
		std::cout << "----------------------------- 2nd test ---------------------------------" << std::endl << std::endl;
		Dog basic;
		basic.setThought(0, "BASIC THOUGHT");
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
   
    // {
    //     /*
    //         This block of code tests the functionality of the Animal class by creating an array of Animal objects. 
    //         Half of the array is filled with Dog objects and the other half with Cat objects. 
    //         The makeSound() method is called on each object, and then each object is deleted. 
    //         The appropriate destructors are called in the expected order, demonstrating 
    //         the polymorphic behavior of these classes.
    //     */
    //     std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
    //     std::cout << "--------------------------  array of Animal obj -------------------------------" << std::endl;
    //     std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

	// 	// The provided code segment involves creating an array of Animal pointers and then assigning them to point to new Dog and Cat objects. 
	// 	// Because Dog and Cat both inherit from Animal, this is perfectly legal. 
	// 	// However, when you want to use the setThought and getThought methods (which are unique to Dog and Cat, and not present in Animal), 
	// 	// you need to cast your Animal pointers back to their derived types.
		
	// 	// Declare an array of 10 Animal pointers:
    //     Animal *array[10];
    //     for (int i  = 0; i < 10; i++)
    //     {
	// 		// If i is less than 5, assign the i-th Animal pointer to point to a new Dog object.
   	// 	 	// Else, assign it to a new Cat object.
 	// 	  	// Use static_cast to cast the Animal pointer to a Dog* or Cat* respectively, 
	// 	    // so we can call setThought on it, which isn't a method of Animal.
 	// 	 	// The first thought of the animal is set to a string specific to its type and number.
    //         if (i < 5) {
    //             array[i] = new Dog();
    //             static_cast<Dog*>(array[i])->setThought(0, "I am Dog #" + std::to_string(i+1));
    //         } else {
    //             array[i] = new Cat();
    //             static_cast<Cat*>(array[i])->setThought(0, "I am Cat #" + std::to_string(i-4));
    //         }
    //     }
	// 	// Loop through the array of Animal pointers.
    //     for (int i = 0; i < 10; i++)
    //     {
	// 		// Have the i-th animal make a sound. Because makeSound is a virtual method in Animal,
    // 		// this will correctly call the Dog's makeSound if the animal is a Dog, or Cat's makeSound if it's a Cat.
    //         array[i]->makeSound();
	// 		// Use static_cast to cast the Animal pointer to a Dog* or Cat* respectively, 
	// 	  	// so we can call getThought on it, which isn't a method of Animal.
 	// 		// Print the first thought of the animal.
    //         if (i < 5)
    //             std::cout << "Dog's thought: " << static_cast<Dog*>(array[i])->getThought(0) << std::endl;
    //         else
    //             std::cout << "Cat's thought: " << static_cast<Cat*>(array[i])->getThought(0) << std::endl;
	// 		// Delete the i-th animal to free memory. Because Animal's destructor is virtual,
    // 		// this will correctly call the Dog's destructor if the animal is a Dog, or Cat's destructor if it's a Cat.
    //         delete array[i];
    //     }
	// 	// The casting is necessary in this context because setThought and getThought are 
	// 	// not present in the Animal class, but are unique to Dog and Cat. 
	// 	// Therefore, to call these methods, the Animal ptr's need to be cast back to their original derived type (Dog or Cat).
	// 	// 
	// 	// Casting in C++ allows you to convert a data type or obj from one type to another. 
	// 	// The static_cast is used when the casting path is well-defined, such as for upcasts (from derived to base) 
	// 	// and downcasts (from base to derived) in a class hierarchy, like here. 
	// 	// Static casting is performed at compile-time.
	// 	// 
	// 	// However, that using static_cast for downcasting is generally discouraged because it can be unsafe. 
	// 	// If we try to downcast an object to a type that it is not, the behavior is undefined. 
	// 	// In this specific context, it's okay because we know the exact types of your objects. 
	// 	// But in a more general context, it would be better to use dynamic_cast and check for null 
	// 	// to ensure the cast succeeded.
    // }

	{
    std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------  array of Animal obj -------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl << std::endl;

    // Declare an array of 10 Animal pointers.
    Animal *array[10];

    // Loop from 0 to 9.
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
		
	// In this version of the code, there's no need for casting because we're only using the makeSound function, 
	// which is defined in the Animal class and overridden in the Dog and Cat classes. 
	// As such, we can call it directly on any Animal ptr, and because it's a virtual function, 
	// the correct version (Dog or Cat) will be called based on the actual type of the object. 
	// This feature is called polymorphism.
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

		// declare ptr to an instance of the Cat class
        Cat *cyborg = new Cat();
        cyborg->setThought(0, "I'm a cat with an identity crisis.");
		
		// delete the instance. 
		// SIC! 'animal_four' is a ptr to a Cat, 
        // but it could also be treated as a pointer to an Animal bc Cat is derived from Animal.
        delete cyborg; 
		
		// if base class destructor (Animal's destructor in this case) is not declared virtual, 
        // when deleting an object of a derived class (Cat) through a ptr of type base class (Animal*), 
        // then the base class destructor is invoked instead of the derived class destructor. 
        // This is problematic bc it can lead to resources acquired by the derived class not being released correctly, 
        // causing memory leaks.

        // But when the destructor is declared virtual in the base class, 
        // the most derived class's destructor (in this case, Cat's destructor) is invoked first, 
        // followed by the base class's destructor. 
        // This ensures proper cleanup of all resources that the obj. might have acquired.

        // Here, since destructors in both Animal and Cat are declared as virtual, 
        // deleting 'animal_four' calls the destructor of Cat first (releasing any resources that Cat might have acquired), 
        // and then the destructor of Animal (releasing any resources that Animal might have acquired).
		std::cout << std::endl;
    }

    return 0;
}
