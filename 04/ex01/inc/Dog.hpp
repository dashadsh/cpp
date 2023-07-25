/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:03:00 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp" // NEW

// We need to add the Brain attribute to the Dog and Cat classes.
// And also override the copy constructor and assignment operator 
// to ensure deep copy.

// Dog class  - derived from Animal class
class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& src);

    virtual ~Dog();

    Dog& operator=(const Dog& src);

    void makeSound() const;

	// This function sets the thought of the dog at the given index - NEW
    void setThought(int idx, const std::string& thought);
    // This function retrieves the thought of the dog at the given index - NEW
    std::string getThought(int idx) const;
	
private: // NEW

    Brain* _brain; // NEW
	
};

#endif
