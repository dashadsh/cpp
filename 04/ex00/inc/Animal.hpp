/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:32:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 23:09:01 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// The Animal class acts as the base class for diff.types of animals
class Animal {
	
public:

    Animal();
    Animal(const Animal& src);
	
    virtual ~Animal();

    Animal& operator=(const Animal& src);

    virtual void makeSound() const;
	
    std::string getType() const;
	// void setType(std::string type);

protected:
    std::string _type;
};

#endif
