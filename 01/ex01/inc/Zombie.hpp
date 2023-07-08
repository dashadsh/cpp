/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:46 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:47 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
	~Zombie();

	// member function takes a std::string parameter name and 
	// sets the NAME of the Zombie object to the provided value
    void setName(std::string name);
    void announce();

private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
