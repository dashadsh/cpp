/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:44:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 18:12:29 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

// WrongAnimal class -  acts as the base class for "wrong" animals
class WrongAnimal {
public:
    // default constructor
    WrongAnimal();

    // copy constructor
    WrongAnimal(const WrongAnimal& src);

    // destructor
    virtual ~WrongAnimal();

    // assignment operator
    WrongAnimal& operator=(const WrongAnimal& src);

    // virtual function to make a sound
  	// virtual void makeSound() const;
	void makeSound() const;

    // getter for type of the WrongAnimal
    std::string getType() const;

protected:
    // protected member variable for type of the WrongAnimal
    std::string _type;
};

#endif
