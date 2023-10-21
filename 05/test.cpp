#include <iostream>
#include <stdexcept> // standard exception header

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
        if (_grade < 1 || _grade > 150) {
            throw std::runtime_error("Invalid grade");
        }
    }

    int getGrade() const { return _grade; }
};

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 160);
        // attempt to create bureaucrat with invalid grade
    } catch (const std::exception &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}

