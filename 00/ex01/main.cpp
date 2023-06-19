#include "phonebook.hpp"
#include <sstream> // std::istringstream
#include <iostream>
#include <iomanip> 
// By using std::setw(10) and std::right manipulators, 
// each field will be displayed with a width of 10 characters and 
// will be right-aligned within that width.

//////////////////////////////////////////////////////////////////
// A minor divergence in the expected formating is not relevant. 
// The aim of this part is to use C++ iomanips and that's what you should focus on.
//////////////////////////////////////////////////////////////////


void handle_search(const PhoneBook& phonebook) {
    phonebook.print_contacts();

    std::cout << "Enter the index of the contact you want to view: ";

	// variable declaration
    std::string command;

	// reads a line of input from the standard input (std::cin) 
	// and stores it in the command variable. 
    std::getline(std::cin, command);

	// creates an input string stream (std::istringstream) named iss 
	// using the content of the command string.
	// The input string stream allows you to treat the command string as a stream, 
	// enabling you to extract values from it in a similar way to reading from std::cin.
    std::istringstream iss(command);
    int index;
 	//  iss >> index;
	//  If you enter a non-numeric value, the extraction from std::istringstream will fail
      if (!(iss >> index)) {
        std::cout << "Invalid input! Please enter a valid index." << std::endl;
        return;
    }

	// -------- WRONG -----------
	// int index;
	// std::cin >> index; - promt was 2 times 

	if (index < 0 || index > 7) {
        std::cout << "Invalid index! Only 0-7 can contain some data." << std::endl;
	} else {
    Contact found_contact = phonebook.get_contact(index);
	//  The empty() function is a member function of the std::string class. 
	// It returns a boolean value indicating whether the string is empty or not.
    if (found_contact.get_first_name().empty()) {
        std::cout << "Invalid index! Nothing is stored there." << std::endl;
    } else {        
        std::cout << "First Name: " << found_contact.get_first_name() << std::endl;
        std::cout << "Last Name: " << found_contact.get_last_name() << std::endl;
        std::cout << "Nickname: "  << found_contact.get_nickname() << std::endl;
        std::cout << "Phone Number: "  << found_contact.get_phone_nbr() << std::endl;
        std::cout << "Darkest Secret: " << found_contact.get_darkest_secret() << std::endl;
    }
}
}

//////////////////////////////////////////////////////////////////
// The field names are not relevant, nor the number of fields 
// as long as it respects the spirit of the exercise.
//////////////////////////////////////////////////////////////////

void handle_add(PhoneBook& phonebook) {
    std::string first_name, last_name, nickname, phone_nbr, darkest_secret;

    while (true) {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first_name);
        if (!first_name.empty()) {
            break;
        }
        std::cout << "First name cannot be empty. Please try again." << std::endl;
    }

    while (true) {
        std::cout << "Enter last name: ";
        std::getline(std::cin, last_name);
        if (!last_name.empty()) {
            break;
        }
        std::cout << "Last name cannot be empty. Please try again." << std::endl;
    }

    while (true) {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        if (!nickname.empty()) {
            break;
        }
        std::cout << "Nickname cannot be empty. Please try again." << std::endl;
    }

    while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone_nbr);
        if (!phone_nbr.empty()) {
            break;
        }
        std::cout << "Phone number cannot be empty. Please try again." << std::endl;
    }

    while (true) {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkest_secret);
        if (!darkest_secret.empty()) {
            break;
        }
        std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
    }
    phonebook.set_contact(first_name, last_name, nickname, phone_nbr, darkest_secret);
}

// void handle_add(PhoneBook& phonebook) {
//     std::string first_name, last_name, nickname, phone_nbr, darkest_secret;

//     std::cout << "Enter first name: ";
//     std::getline(std::cin, first_name);
//     std::cout << "Enter last name: ";
//     std::getline(std::cin, last_name);
//     std::cout << "Enter nickname: ";
//     std::getline(std::cin, nickname);
//     std::cout << "Enter phone number: ";
//     std::getline(std::cin, phone_nbr);
//     std::cout << "Enter darkest secret: ";
//     std::getline(std::cin, darkest_secret);

//     phonebook.set_contact(first_name, last_name, nickname, phone_nbr, darkest_secret);
// }

//////////////////////////////////////////////////////////////////
// The program must present a read/eval loop at some point: reading
// the input, evaluating it, then loop until an EXIT command appears in input.
//////////////////////////////////////////////////////////////////

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD") {
            handle_add(phonebook);
        } 
		else if (command == "SEARCH") {
            handle_search(phonebook);
        }
		else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}
