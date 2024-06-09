// Compile-time Polymorphism can be achieved using:

// Operator overloading
// Function overloading
#include <iostream>

class Math {
private:
	int value;
public:
	Math(int newValue) : value(newValue) {};
	Math operator+(Math& other) {
		return Math(value + other.value);
	}
    // Overload the '<<' operator as a member function
	// friend !!!
    friend std::ostream& operator<<(std::ostream& out, const Math& num) {
        out << num.value;
        return out;
    }
};

int main() {
	Math num1(4);
	Math num2(3);
	std::cout << num1 << " " << num2 << std::endl;

    // use overloaded '+' operator to add two MyNumber objects
	Math sum = num1 + num2;
	std::cout << sum << std::endl;
}

