/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:13:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 01:26:33 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// default constructor - initializes ideas to ""
Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "";
    }
}

// copy constructor
Brain::Brain(const Brain& src) {
    *this = src;
}

// destructor
Brain::~Brain() {}

// assignment operator
Brain& Brain::operator=(const Brain& src) {
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = src._ideas[i];
        }
    }
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
    return "";
}
