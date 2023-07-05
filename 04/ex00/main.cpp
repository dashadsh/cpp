/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 16:13:34 by dgoremyk         ###   ########.fr       */
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
	
	std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

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

    const Animal *cat = new Cat();
    std::cout << std::endl;

    std::cout << "Cat _type: " << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << std::endl;

    delete cat;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    const Animal *dog = new Dog();
    std::cout << std::endl;
	
    std::cout << "Dog _type: " << dog->getType() <<std::endl;
    dog->makeSound();
    std::cout << std::endl;
	
    delete dog;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    const WrongAnimal *wrong_meta = new WrongAnimal();
    std::cout << std::endl;

    std::cout << "WrongAnimal _type: " << wrong_meta->getType() << std::endl;
    wrong_meta->makeSound();
    std::cout << std::endl;

    delete wrong_meta;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;
    
    const WrongAnimal *wrong_cat = new WrongCat();
    std::cout << std::endl;

    std::cout << "WrongCat _type: " << wrong_cat->getType() <<std::endl;
    wrong_cat->makeSound();
    std::cout << std::endl;

    delete wrong_cat;

    std::cout << std::endl << "-------------------------------------------------------" << std::endl << std::endl;

    return 0;
}
