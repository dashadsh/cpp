/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:32:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:37:37 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// The Animal class acts as the base class for diff.types of animals
class Animal {
public:
    // default constructor
    Animal();
    // copy constructor
    Animal(const Animal& src);

    // destructor
    virtual ~Animal();

    // assignment operator
    Animal& operator=(const Animal& src);

    // virtual function to make a sound
    virtual void makeSound() const;
    // getter for the type of the animal
    std::string getType() const;

protected:
    // protected member variable for the type of the animal
    std::string _type;
};

#endif
