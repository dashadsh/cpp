/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:41:21 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

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
};

#endif
