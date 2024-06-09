#include <iostream>

class Animal {
public:
    void sound() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Dog barks" << std::endl;
    }
};

class GermanShepherd : public Dog {
public:
    void guard() {
        std::cout << "German Shepherd guards" << std::endl;
    }
};

int main() {
    GermanShepherd dog;
    
    dog.sound();
    dog.bark();
    dog.guard();
    
    return 0;
}
