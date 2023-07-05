/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:00:51 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:24:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "aAnimal.hpp"
#include "Brain.hpp"

/*
 * Cat is a concrete class which inherits from the abstract base class AAnimal.
 * It provides an implementation for the pure virtual function makeSound.
 */
class Cat : public AAnimal {
	
public:

    Cat(const std::string& name = "Cat"); // Constructor
    Cat(const Cat& other); // Copy constructor
    Cat& operator=(const Cat& other); // Assignment operator
    ~Cat(); // Destructor
    
    // overrides the pure virtual function makeSound from AAnimal !!!
	// Implementation of virtual makeSound function
    void makeSound() const;
    void setThought(int idx, const std::string& thought); // Set the cat's thought
    std::string getThought(int idx) const; // Get the cat's thought

private:

    Brain* _brain; // Pointer to the cat's brain

};

#endif
