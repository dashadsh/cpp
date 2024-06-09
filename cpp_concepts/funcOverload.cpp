// Compile-time Polymorphism can be achieved using:

// Operator overloading
// Function overloading
#include <iostream>

class Math {
public:	
	int add(int a, int b) {
		return a + b;
		}

	int add(int a, int b, int c) {
		return a + b + c;
		}

	double add(double a, double b) {
		return a + b;
		}
};

int main() {
	Math math;

	std::cout << math.add(5,7) << std::endl;
	std::cout << math.add(5,7,777) << std::endl;
}