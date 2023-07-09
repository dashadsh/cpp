/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:13:12 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:58:47 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	
public:

    Brain(); // default constructor - initializes ideas to ""
    ~Brain();
    Brain(const Brain& src); // copy constructor

    Brain& operator=(const Brain& src); // assignment operator

    void setIdea(int idx, const std::string& idea);	// func. to set an idea
    std::string getIdea(int idx) const;	// getter for an idea

private:

    std::string _ideas[100];	// array of ideas
	
};

#endif
