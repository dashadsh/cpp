/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:42:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:43:16 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

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
};

#endif
