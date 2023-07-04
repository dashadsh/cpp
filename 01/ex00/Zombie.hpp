/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:28 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:30 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	// constructor
    Zombie(std::string name);

	// Function that announces the zombie by printing
    void announce();

	// destructor
    ~Zombie();

private:
	// private attribute 'name'
    std::string name;
};

#endif
