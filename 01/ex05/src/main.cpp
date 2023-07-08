/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:55 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 20:48:01 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ------------------------------------------------------------------------------------------------------------
// PTR member func. allows to store a reference to a func. that belongs to a class. 
//
// useful to call a func. dynamically based on some condition, 
// w/o use of conditional statements like if/else/switch. 
// ------------------------------------------------------------------------------------------------------------

// call the appropriate complaint function based on a level string, 
// without using conditionals.
// function pointers allow you to decide at runtime which function to call.
//
// This is the main reason they're used in the Harl exercise: 
// to choose the appropriate complaint function based on the level string.
#include "../inc/Harl.hpp"

int main() {
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
// 	harl.complain("YOU BETTER BURN IN HELL");

    return 0;
}

// ------------------------------------------------------------------------------------------------------------
// This technique allows the program to decide at runtime which function to call, 
// based on the level string. 
// It avoids a "forest of if/else if/else" because there are no conditional statements; 
// the function to call is determined solely by the map lookup.

// For example, if the level string is "ERROR", 
// the map lookup funcMap[level] retrieves the pointer to the error function, 
// and (this->*funcMap[level])() calls this->error().

// In summary, the PTRs to member functions provide a way to encapsulate 
// the behavior of the Harl obj and select the appropriate behavior at runtime 
// based on the level of the complaint. 
// This makes the code more flexible and maintainable, 
// as adding or changing complaint levels would only require changes to the map 
// and not a series of conditional statements.
// ------------------------------------------------------------------------------------------------------------


/* --------- func ptr example in C ---------------
#include <stdio.h>

void debug() {
    printf("This is a debug message.\n");
}

void error() {
    printf("This is an error message.\n");
}

void process_message(void (*func)()) {
    func();
}

int main() {
    void (*func_ptr)() = debug;
    process_message(func_ptr);
    func_ptr = error;
    process_message(func_ptr);
    return 0;
}
*/