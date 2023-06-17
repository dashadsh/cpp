#include "phonebook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

// set_contact function enables adding new contacts to the phone book by finding an empty slot 
// in the array and setting the contact information for that slot.
void PhoneBook::set_contact(const std::string& first_name, const std::string& last_name, const std::string& nickname,
                            const std::string& phone_nbr, const std::string& darkest_secret) {
    static int index = 0; // Static index variable to keep track of the current position

    contacts[index].set_first_name(first_name);
    contacts[index].set_last_name(last_name);
    contacts[index].set_nickname(nickname);
    contacts[index].set_phone_nbr(phone_nbr);
    contacts[index].set_darkest_secret(darkest_secret);

    index = (index + 1) % 8; // Move the index to the next position in a circular manner
}

// contacts in the phone book will be displayed as a list with each field aligned in its respective column
void PhoneBook::print_contacts() const {
    for (int i = 0; i < 8; ++i) {
		// current index i is converted to a string using std::to_string(i). 
		// to display the index in the formatted output
        std::string index = std::to_string(i);

		// truncate() is called for each field (first_name, last_name, and nickname) of the current contact, 
		// if a field is longer than 10 characters, it will be truncated and the last character will be replaced with a dot,
		// truncated strings are stored in the respective variables 
        std::string first_name = truncate(contacts[i].get_first_name(), 10);
        std::string last_name = truncate(contacts[i].get_last_name(), 10);
        std::string nickname = truncate(contacts[i].get_nickname(), 10);

		// formatted output is then printed using std::cout. 
		// Each line of the output represents a contact and consists of four columns: 
		// index, first name, last name, and nickname. 
		// The std::setw(10) manipulator is used to set the width of each column to 10 characters, ensuring consistent alignment. 
		// The | character is used as a separator between the columns.
        std::cout << "|" << std::setw(10) << index << "|" << std::setw(10) << first_name << "|" << std::setw(10)
                  << last_name << "|" << std::setw(10) << nickname << "|" << std::endl;
    }
}

// responsible for retrieving a specific contact from the phone book based on the given idx
Contact PhoneBook::get_contact(int index) const {
    if (index < 0 || index > 7) {
        return Contact(); // Return a default-constructed Contact object,
		// which can be used to indicate an error or non-existent contact
    }
    return contacts[index];
}

std::string PhoneBook::truncate(std::string str, size_t width) const {
    if (str.length() > width) {
        str = str.substr(0, width - 1);
        str += ".";
    }
    return str;
}
