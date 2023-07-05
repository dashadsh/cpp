/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:42:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 01:41:53 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp" // new

// We need to add the Brain attribute to the Dog and Cat classes.
// And also override the copy constructor and assignment operator 
// to ensure deep copy.

// Cat class - derived from the Animal class
class Cat : public Animal {
	
public:
    // default constructor
    Cat();

    // copy constructor
    Cat(const Cat& src);

    // destructor
    ~Cat();

    // assignment operator
    Cat& operator=(const Cat& src);

    // func. to make cat sound
    void makeSound() const;
	
	// void think(int idx, const std::string& thought);  // new
	
	// This function sets the thought of the cat at the given index
    void setThought(int idx, const std::string& thought);

    // This function retrieves the thought of the cat at the given index
    std::string getThought(int idx) const;

private:  // new

    Brain* _brain;  // new

};

#endif
