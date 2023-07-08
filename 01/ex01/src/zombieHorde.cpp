/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:50 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 20:21:30 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <iostream>
#include <sstream>

// dynamically allocates an array of N Zombie objects 
// points to the first Zombie object in the dynamically allocated array
Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
        std::cerr << "Invalid number of zombies: " << N << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N];
    // for (int i = 0; i < N; i++) {
    //     horde[i].setName(name + std::to_string(i));
    // }
	for (int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << name << i;
        horde[i].setName(ss.str());
    }

    return horde;
}
