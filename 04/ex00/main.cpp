/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 15:07:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	// // FIRST TEST
    // const Animal *meta = new Animal();
    // const Animal *j = new Dog();
    // const Animal *i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    
    // delete meta;
    // delete j;
    // delete i;
	
	// SECOND TEST
	
	std::cout << std::endl;
    const Animal *meta = new Animal();
	// SIC! CONST KEYWORD - way to ensure an obj. isn't changed after it's created (can be useful, but limits what you can do).
	// const keyword before Animal *meta  - used to indicate that the obj. that meta points to cannot be changed. 
	// 
	// We cannot use meta to modify the Animal object after it's created.
	// Way of telling the compiler and other programmers "this object should not change after it's created".
	//
	// However, it means that we can only call const member funct's on meta. 
	// Non-const member functions might modify the object, 
	// so calling them on a const object is not allowed.
	//
	// For example, if Animal had a member function void setName(std::string name);  - 
	// we could not call meta->setName("New name"); if meta is a const Animal*, 
	// bc setName is not a const member function.
    std::cout << std::endl;

    std::cout << "Animal _type: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;

    delete meta;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    const Animal *catto = new Cat();
    std::cout << std::endl;

    std::cout << "Cat _type: " << catto->getType() << std::endl;
    catto->makeSound();
    std::cout << std::endl;

    delete catto;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    const Animal *doggo = new Dog();
    std::cout << std::endl;
	
    std::cout << "Dog _type: " << doggo->getType() <<std::endl;
    doggo->makeSound();
    std::cout << std::endl;
	
    delete doggo;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    const WrongAnimal *wrong_meta = new WrongAnimal();
    std::cout << std::endl;

    std::cout << "WrongAnimal _type: " << wrong_meta->getType() << std::endl;
    wrong_meta->makeSound();
    std::cout << std::endl;

    delete wrong_meta;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;
    
    const WrongAnimal *wrong_catto = new WrongCat();
    std::cout << std::endl;

    std::cout << "WrongCat _type: " << wrong_catto->getType() <<std::endl;
    wrong_catto->makeSound();
    std::cout << std::endl;

    delete wrong_catto;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    return 0;
}
