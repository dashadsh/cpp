/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:46:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:47:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// WrongCat class - derived from the WrongAnimal class
class WrongCat : public WrongAnimal {
public:
    // def. constructor
    WrongCat();

    // copy constructor
    WrongCat(const WrongCat& src);

    // destructor
    ~WrongCat();

    // assignment operator
    WrongCat& operator=(const WrongCat& src);

    // func. to make WrongCat sound
    void makeSound() const;
};

#endif
