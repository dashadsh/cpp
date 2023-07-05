/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 01:41:51 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp" // new

// We need to add the Brain attribute to the Dog and Cat classes.
// And also override the copy constructor and assignment operator 
// to ensure deep copy.

// Dog class  - derived from Animal class
class Dog : public Animal {
public:
    // default constructor
    Dog();
    // copy constructor
    Dog(const Dog& src);

    // destructor
    ~Dog();

    // assignment operator
    Dog& operator=(const Dog& src);

    // function to make a dog sound
    void makeSound() const;
	
	// void think(int idx, const std::string& thought); // new
	
	// This function sets the thought of the dog at the given index
    void setThought(int idx, const std::string& thought);

    // This function retrieves the thought of the dog at the given index
    std::string getThought(int idx) const;
	
private: // new

    Brain* _brain; // new
	
};

#endif
