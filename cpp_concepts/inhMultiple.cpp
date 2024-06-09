#include <iostream>

class Base1 {
public:
    void displayBase1() {
        std::cout << "Base1::displayBase1()" << std::endl;
    }
};

class Base2 {
public:
    void displayBase2() {
        std::cout << "Base2::displayBase2()" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void displayDerived() {
        std::cout << "Derived::displayDerived()" << std::endl;
    }
};

int main() {
    Derived obj;

    obj.displayBase1();
    obj.displayBase2();
    obj.displayDerived();

    return 0;
}
