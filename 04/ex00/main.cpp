/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:48:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 14:44:16 by dgoremyk         ###   ########.fr       */
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

// -------------------------------- DEEP COPY ----------------------------------------
// deep copy involves duplicating not only the obj but also the obj's or values it references or contains. 
// This is in contrast to a shallow copy where the copied object still references the same locations as the original.

// Here, the assignment operator (operator=) and copy constructor for EACH class take care of creating a deep copy.

// In the operator= function, if the source obj is not the same as the destination obj (determined by if (this != &src)), 
// the assignment operator copies the member variable _type from the source obj to the destination obj. 
// The this->_type = src._type; code line does this.

// For copy constructor, it makes use of the assignment operator to ensure that deep copy is made. 
// Animal::Animal(const Animal& src) calls *this = src; to use the assignment operator to make the copy.

// In the Cat and Dog derived classes, the base class's assignment operator and copy constructor are 
// called in their respective assignment operator and copy constructor implementations, 
// which ensures that the _type member var from the Animal class is correctly copied.

// These steps ensure that each obj copy gets its own version of the _type variable, which is a deep copy. 
// If we were only making a shallow copy, then changing _type in one object would affect the other object 
// bc they would both be referring to the same underlying data, but that's not the case here.

//  Here, each object has its own copy of _type, so they can be modified independently!!!

// SIC! in C++, when dealing with raw pointers, the concept of deep and shallow copy becomes critical. 
// If our class contains a ptr and your copy constructor and assignment operator are not properly taking care 
// of copying the pointed-to value, then you could end up with multiple objects thinking they own the same 
// dynamically-allocated object, which is usually not what you want. 
// But here the Animal (and derived classes) do not contain any pointers or complex resources, 
// so the default behavior (memberwise copy) is sufficient.



