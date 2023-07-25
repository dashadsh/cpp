/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:42:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:20:03 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

// Cat class - derived from the Animal class
class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& src);

    virtual ~Cat();

    Cat& operator=(const Cat& src);

    void makeSound() const;
};

#endif
