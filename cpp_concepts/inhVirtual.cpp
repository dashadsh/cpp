#include <iostream>

class Animal {
public:
    virtual void sound() {
        std::cout << "animal makes a sound" << std::endl;
    }
};

// intermediate base class with virtual inheritance
class Pet : virtual public Animal {
public:
    void play() {
        std::cout << "pet plays" << std::endl;
    }
};

// another intermediate base class with virtual inheritance
class WildAnimal : virtual public Animal {
public:
    void roam() {
        std::cout << "wild animal roams" << std::endl;
    }
};

// derived class inheriting from both Pet and WildAnimal
class Dog : public Pet, public WildAnimal {
public:
    void bark() {
        std::cout << "dog barks" << std::endl;
    }
};

int main() {
    Dog dog;
    
    dog.sound();  // inh from Animal
    dog.play();   // inh from Pet
    dog.roam();   // inh from WildAnimal
    dog.bark();   // def in Dog
    
    return 0;
}
