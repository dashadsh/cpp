/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:15 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 13:09:01 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP


#include "ClapTrap.hpp"

// class FragTrap : public ClapTrap {
class FragTrap : virtual public ClapTrap {
public:

	FragTrap(void); // Default constructor
	FragTrap(std::string name); // Parameterized constructor
	FragTrap(FragTrap const &src); // Copy constructor

	~FragTrap(void); // Destructor

	FragTrap& operator=(FragTrap const &rhs); // Assignment operator

    // Overridden attack function
    void attack(const std::string& target);

    void highFivesGuys();

};

#endif
