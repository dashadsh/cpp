// Runtime Polymorphism can be achieved using:

// Function overriding
// Virtual Functions
#include <iostream>

class Animal {
	public:
		// can be not a virtual one, if we want to be able instantiate Animal
		virtual void makeSound() = 0;
		virtual ~Animal() {}
};

class Cat: public Animal {
	public:
		void makeSound() override {
		std::cout << "meow\n";
	}
};

int main() {
	Animal* animal = new Cat();
	animal->makeSound();

	Cat cat;
	cat.makeSound();
}
