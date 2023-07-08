/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:33 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 20:27:07 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Zombie.hpp"
// create N zombies at once through a function called zombieHorde(int N, std::string name)

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    if (horde != NULL) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }

    // test single Zombie creation
    Zombie singleZombie;
    singleZombie.setName("TestZombie");
    singleZombie.announce(); // should display "TestZombie: BraiiiiiiinnnzzzZ..."

    // TEST NEGATIVE & ZERO - 1st ver
    // no allocation occurs, so no need to assign or delete
    // zombieHorde(0, "EmptyZombie");
    // zombieHorde(-5, "NegativeZombie");

    // TEST NEGATIVE & ZERO - 2nd ver
    // Zombie* emptyHorde = zombieHorde(0, "EmptyZombie");
    // if (emptyHorde != NULL) {
    //     delete[] emptyHorde;
    // }
    // Zombie* negativeHorde = zombieHorde(-5, "NegativeZombie");
    // if (negativeHorde != NULL) {
    //     delete[] negativeHorde;
    // }

    return 0;
}

// int main() {
//     int N = 5;
//     Zombie* horde = zombieHorde(N, "Zombie");

//     for (int i = 0; i < N; i++) {
// 		// simply create custom Zombie name using it's index
//         std::string name = "Zombie" + std::to_string(i);
//         horde[i].announce();
//     }

// 	// zombieHorde created an object as an array,
// 	// normal delete => only the 1st obj will be freed. 
// 	// if you declare an obj. as an array => delete[] to release all of them.
//     delete[] horde;
//     return 0;
// }
