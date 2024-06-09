// Single Inheritance: When a derived class inherits the properties of a single base class, it is known as Single Inheritance.
// Multiple Inheritance: When a derived class inherits the properties of multiple base classes, it is known as Multiple Inheritance.
// Multilevel Inheritance: When a derived class inherits the properties of another derived class, it is known as Multilevel Inheritance.
// Hierarchical Inheritance: When more than one derived class inherits the properties of a single base class, it is known as Hierarchical Inheritance.
// Hybrid (Virtual) Inheritance: When we combine more than one type of inheritance, it is known as Hybrid (Virtual) Inheritance. Example: Combining Multilevel and Hierarchical inheritance.

#include <iostream>

class Shape {
public:
    virtual double area() const = 0;
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Rectangle rectangle(5, 4);
    std::cout << "Area of Rectangle: " << rectangle.area() << std::endl;

    Circle circle(3);
    std::cout << "Area of Circle: " << circle.area() << std::endl;

    return 0;
}
