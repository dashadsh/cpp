/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:44:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 23:09:08 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

// WrongAnimal class -  acts as the base class for "wrong" animals
class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);

    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& src);

    // void setType(std::string type);
    std::string getType() const;

	void makeSound() const;
	
protected:
    std::string _type;
};

#endif
