/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:56:59 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:57:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

/*
 * AAnimal is an abstract base class that provides a common interface for all animals.
 * Abstract means that we cannot create an instance of this class, 
 * we can only inherit from it and create instances of the subclasses.
 *
 * 'Virtual' keyword means that the function can be overridden in a subclass.
 * 
 * The '= 0' at the end of the function declaration makes this function a "pure virtual function",
 * which means it MUST be overridden in any non-abstract subclass. 
 * 
 * A class with at least one pure virtual function is considered abstract.
 */
class AAnimal
{
public:
    AAnimal(); // Default constructor
    AAnimal(const std::string& name); // Parameterized constructor
    AAnimal(const AAnimal& other); // Copy constructor
    AAnimal& operator=(const AAnimal& other); // Assignment operator
    virtual ~AAnimal(); // Destructor

    std::string getName() const; // Getter for name
    void setName(const std::string& name); // Setter for name
    
    // This function is a pure virtual function, which makes AAnimal an abstract class.
    virtual void makeSound() const = 0;

protected:
    std::string name;
};

#endif

