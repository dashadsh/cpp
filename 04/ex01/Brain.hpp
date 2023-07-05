/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:13:12 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 01:26:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
    Brain();
    ~Brain();
    Brain(const Brain& src);
	
    Brain& operator=(const Brain& src);

    // func. to set an idea
    void setIdea(int idx, const std::string& idea);
    // getter for an idea
    std::string getIdea(int idx) const;

private:
    // array of ideas
    std::string _ideas[100];
};

#endif
