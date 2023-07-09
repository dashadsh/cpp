/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:04:46 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/10 00:41:16 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

#include <iostream>

// An abstract class has at least one pure virtual function (a function declared in a class that has no implementation). 
// Objects of these classes cannot be created, but pointers and references of these classes can be used to achieve polymorphism, 
// which is a key concept in OOP.
//
// AAnimal is an abstract class bc it contains the pure virtual function virtual void makeSound() const = 0;. 
// This function is then implemented in the Cat and Dog classes, which are derived from AAnimal.
//
// The reason why AAnimal is made an abstract class is to ensure that no instances of AAnimal are created. 
// It doesn't make sense to create an Animal object bc the concept of an Animal is too abstract. 
// We don't know what sound an Animal makes bc that depends on the type of animal. 
// By making makeSound() a pure virtual function, we're enforcing that any class derived from AAnimal 
// (like Cat and Dog) must provide an implementation for makeSound(), making it more specific to the type of animal.
// 
// AAnimal animal will lead to compilation error: AAnimal is an abstract class

int main(void) {
	std::cout << std::endl;
    // Create Cat and Dog objects
    Cat cat("Mittens");
    Dog dog("Fido");
	// AAnimal animal("Cyborg"); - WILL GIVE AN ERROR
    std::cout << std::endl;
	
	std::cout << "-------------Make the Cat and Dog make a sound-------------------" << std::endl << std::endl;
    cat.makeSound();
    dog.makeSound();
    std::cout << std::endl;
	
	std::cout << "-------------Set some thoughts for the Cat and Dog-----------------" << std::endl << std::endl;
    cat.setThought(0, "I love summer.");
    dog.setThought(0, "I love playing fetch.");
    std::cout << std::endl;
	
	std::cout << "-------------Make a deep copy of the Cat and Dog-----------------" << std::endl << std::endl;
    Cat other_cat(cat);
    Dog other_dog(dog);
	std::cout << std::endl;
	std::cout << "------Output the first thought of the copied Cat and Dog----------------" << std::endl << std::endl;
    std::cout << "Copied Cat's first thought: " << other_cat.getThought(0) << std::endl;
    std::cout << "Copied Dog's first thought: " << other_dog.getThought(0) << std::endl;
    std::cout << std::endl;
	
	std::cout << "------------Change the first thought of the original Cat and Dog---------------" << std::endl << std::endl;
    cat.setThought(0, "I hate winter.");
    dog.setThought(0, "I hate baths.");
	std::cout << std::endl;
	
	std::cout << "-----------Output the first thought of the original and copied Cat and Dog----------" << std::endl << std::endl;
    std::cout << "Original Cat's first thought: " << cat.getThought(0) << std::endl;
    std::cout << "Original Dog's first thought: " << dog.getThought(0) << std::endl;
    std::cout << "Copied Cat's first thought: " << other_cat.getThought(0) << std::endl;
    std::cout << "Copied Dog's first thought: " << other_dog.getThought(0) << std::endl;

    return 0;
}

