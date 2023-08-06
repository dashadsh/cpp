### C04

#### ex00: Polymorphism

Polymorphism in C++ is a concept in object-oriented programming that allows objects of different types to be treated as if they were objects of the same type. It enables the same function or object to behave differently in different scenarios.

There are two main types of polymorphism:

1. Compile-time polymorphism, also known as **static polymorphism**, occurs during the compilation of the program. It is achieved through function overloading and templates. Function overloading allows the same function name to have multiple implementations based on the number, types, and order of arguments passed to it. Templates allow the same code to work with different data types.

Example of function overloading:

```cpp
#include <iostream>
using namespace std;

void print(int num) {
    cout << "Printing integer: " << num << endl;
}

void print(float num) {
    cout << "Printing float: " << num << endl;
}

int main() {
    int a = 5;
    float b = 5.5;

    print(a);  // Output: Printing integer: 5
    print(b);  // Output: Printing float: 5.5

    return 0;
}
```

2. Runtime polymorphism, also known as **dynamic polymorphism** or **sub-type polymorphism**, occurs during program execution. It is achieved through function overriding and virtual functions. Function overriding allows a derived class to provide its own implementation of a function that is already defined in the base class. Virtual functions are declared in the base class as "virtual" and can be overridden in the derived class, enabling dynamic binding of functions based on the actual object type at runtime.

Example of virtual functions:

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "This is an animal." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "This is a dog." << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "This is a cat." << endl;
    }
};

int main() {
    Animal* ptr;
    Dog dog;
    Cat cat;

    ptr = &dog;
    ptr->speak();  // Output: This is a dog.

    ptr = &cat;
    ptr->speak();  // Output: This is a cat.

    return 0;
}
```

#### ex01: Dynamic Cast & Inheritance

In C++, when you have a base class pointer pointing to a derived class object, you can use dynamic casting to convert the pointer to the derived class type if the object being pointed to is actually of the derived class type.

```cpp
Animal* animalPtr = new Dog();
Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

if (dogPtr != nullptr) {
    // Casting successful, use dogPtr
    dogPtr->bark();
} else {
    // Casting failed, animalPtr does not point to a Dog object
}
```

The dynamic_cast operator checks if the type conversion is valid and returns a pointer of the derived class type if successful, or nullptr if the conversion is not possible. It ensures that you safely access the members and functions of the derived class without causing undefined behavior.

#### ex02: Abstract Class

An abstract class in C++ is a class that contains at least one pure virtual function, marked with the "= 0" syntax. A pure virtual function is a function that has no implementation in the abstract class and must be overridden in the derived classes.

Abstract classes cannot be instantiated directly, but they can be used as base classes to create concrete subclasses. The main purpose of an abstract class is to provide an interface that defines a set of functions that must be implemented by its derived classes.

For example:

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function, no implementation
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    Shape* shapePtr;
    Circle circle;
    Square square;

    shapePtr = &circle;
    shapePtr->draw(); // Output: Drawing a circle.

    shapePtr = &square;
    shapePtr->draw(); // Output: Drawing a square.

    return 0;
}
```

#### ex03: Interface

In C++, an interface is typically an abstract class that contains only pure virtual functions (functions with "= 0" syntax) and no data members. The purpose of an interface is to provide a contract or template for derived classes to implement.

```cpp
class Printable {
public:
    virtual void print() = 0; // Pure virtual function, no implementation
};

class Document : public Printable {
public:
    void print() override {
        cout << "Printing a document." << endl;
    }
};

class Image : public Printable {
public:
    void print() override {
        cout << "Printing an image." << endl;
    }
};

int main() {
    Printable* printablePtr;
    Document doc;
    Image img;

    printablePtr = &doc;
    printablePtr->print(); // Output: Printing a document.

    printablePtr = &img;
    printablePtr->print(); // Output: Printing an image.

    return 0;
}
```

#### ex04: Materia and MateriaSource

In this exercise, we have a game with characters and materia. Materia are stored in a MateriaSource, and characters can equip and use the materia.

- `iCharacter` is an interface that defines the common behavior expected from character classes. It acts as a template for character implementation and ensures that certain functions are available in character classes.
- `Character` is a concrete class that implements the `iCharacter` interface. It represents a character in the game and can equip and use materias.
- `aMateria` is an abstract class representing the base class for all materias. It contains pure virtual functions that must be overridden by derived classes.
- `Ice` and `Cure` are concrete classes that implement specific types of materias.
- `iMateriaSource` is an interface that defines the functions for managing materias in the MateriaSource.
- `MateriaSource` is a concrete class that implements the `iMateriaSource` interface. It stores a collection of materias and allows characters to learn and create materias.

The exercise demonstrates the use of polymorphism, abstract classes, and interfaces to create a flexible and extensible system for characters and materias in the game.