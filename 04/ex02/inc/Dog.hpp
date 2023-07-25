/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:01:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:55:58 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

/*
 * Dog is a concrete class that inherits from the abstract base class AAnimal - 
 * provides an implementation for the pure virtual function makeSound.
 */
class Dog : public AAnimal {
	
public:

    Dog(const std::string& name = "Dog"); // Constructor
    Dog(const Dog& other); // Copy constructor
    Dog& operator=(const Dog& other); // Assignment operator
	
    virtual ~Dog(); // Destructor

    void makeSound() const; // Implementation of virtual makeSound function
	// overrides the pure virtual function makeSound from AAnimal !!!
    void setThought(int idx, const std::string& thought); // Set the dog's thought
    std::string getThought(int idx) const; // Get the dog's thought

private:

    Brain* _brain; // Pointer to the dog's brain
	
};

#endif
