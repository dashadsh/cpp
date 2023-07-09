/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:13:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 21:46:38 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>

// default constructor - initializes ideas to ""
Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "";
    }
	std::cout << "A brain is formed, filled with empty thoughts." << std::endl;
}

// copy constructor
Brain::Brain(const Brain& src) {
    *this = src;
	 std::cout << "A brain is copied, inheriting all of its thoughts." << std::endl;
}

// destructor
Brain::~Brain() {
	std::cout << "A brain destroyed, taking all its thoughts with it." << std::endl;
}

// assignment operator
Brain& Brain::operator=(const Brain& src) {
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = src._ideas[i];
        }
    }
	std::cout << "Brain's assignment operator called, adopting new thoughts." << std::endl;
    return *this;
}

// func. to set an idea
void Brain::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100) {
        _ideas[idx] = idea;
    }
}

// getter for an idea
std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100) {
        return _ideas[idx];
    }
	std::cout << "No thought can be found in this part of a brain." << std::endl;
    return "";
}
