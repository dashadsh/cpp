/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:33 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// create N zombies at once through a function called zombieHorde(int N, std::string name)
int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
		// simply create custom Zombie name using it's index
        std::string name = "Zombie" + std::to_string(i);
        horde[i].announce();
    }

	// zombieHorde created an object as an array,
	// normal delete => only the 1st obj will be freed. 
	// if you declare an obj. as an array => delete[] to release all of them.
    delete[] horde;
    return 0;
}
