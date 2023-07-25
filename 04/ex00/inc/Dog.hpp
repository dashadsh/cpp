/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:20:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// Dog class  - derived from Animal class
class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& src);

    virtual ~Dog();

    Dog& operator=(const Dog& src);

    void makeSound() const;
};

#endif
