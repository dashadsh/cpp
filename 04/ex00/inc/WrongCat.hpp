/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:46:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 23:10:07 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

// WrongCat class - derived from the WrongAnimal class
class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& src);

    ~WrongCat();

    WrongCat& operator=(const WrongCat& src);

    void makeSound() const;
};

#endif
