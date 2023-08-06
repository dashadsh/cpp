### C03

#### Inheritance Modes:

In C++, there are three modes of inheritance:

1. Public Mode: If we derive a subclass from a public base class, the public members of the base class become public in the derived class, and the protected members of the base class become protected in the derived class.

```cpp
class Base {
public:
    int publicMember;
protected:
    int protectedMember;
};

class Derived : public Base {
    // publicMember remains public in Derived
    // protectedMember remains protected in Derived
};
```

2. Protected Mode: If we derive a subclass from a protected base class, both public and protected members of the base class become protected in the derived class.

```cpp
class Base {
protected:
    int protectedMember;
};

class Derived : protected Base {
    // protectedMember becomes protected in Derived
};
```

3. Private Mode: If we derive a subclass from a private base class, both public and protected members of the base class become private in the derived class.

```cpp
class Base {
private:
    int privateMember;
};

class Derived : private Base {
    // privateMember becomes private in Derived
};
```

In C++, the default mode of inheritance is private, meaning that if no mode is specified, the inheritance is private.

#### Diamond Problem:

The Diamond Problem occurs in C++ when multiple inheritance is used, and a derived class inherits from two or more classes that have a common base class. This creates a diamond-shaped inheritance hierarchy, and it leads to ambiguity in the function and data member access of the common base class.

To resolve the Diamond Problem, we can use virtual inheritance. Virtual inheritance allows the creation of a single instance of the common base class, shared among all the derived classes. This way, the ambiguity is resolved, and the classes can access the common base class without any issues.

Example:

```cpp
class ClapTrap {
public:
    int health;
};

class FragTrap : virtual public ClapTrap {
public:
    // Other functions and data members
};

class ScavTrap : virtual public ClapTrap {
public:
    // Other functions and data members
};

class DiamondTrap : public FragTrap, public ScavTrap {
    // Other functions and data members
};
```

In the above example, `FragTrap` and `ScavTrap` virtually inherit from `ClapTrap`, and `DiamondTrap` inherits from both `FragTrap` and `ScavTrap`. This avoids the Diamond Problem, and there is only one instance of the `ClapTrap` base class shared among `FragTrap` and `ScavTrap`.

#### Ambiguity:

Ambiguity can occur in multiple inheritance when there is a naming conflict between the members of the base classes. For example, if both base classes have a function with the same name, calling the function on the derived class object can result in ambiguity.

Example:

```cpp
class Base1 {
public:
    void func() {
        cout << "Base1 function" << endl;
    }
};

class Base2 {
public:
    void func() {
        cout << "Base2 function" << endl;
    }
};

class Derived : public Base1, public Base2 {
    // Other functions and data members
};
```

In the above example, the `Derived` class inherits from both `Base1` and `Base2`, both of which have a function named `func()`. When we call `func()` on a `Derived` object, it becomes ambiguous which `func()` should be called.

To resolve the ambiguity, you can use scope resolution to specify which `func()` you want to call:

```cpp
Derived d;
d.Base1::func(); // Calls the func() from Base1
d.Base2::func(); // Calls the func() from Base2
```

#### Set-Get Encapsulation:

Set and get methods (also known as setter and getter methods) are used to encapsulate access to private data members of a class. They allow controlled access to these private data members and ensure that any changes to the data members go through these methods.

The set method is used to set the value of a private data member, and the get method is used to retrieve the value of the private data member.

Example:

```cpp
class MyClass {
private:
    int myData;

public:
    void setData(int value) {
        myData = value;
    }

    int getData() const {
        return myData;
    }
};

int main() {
    MyClass obj;
    obj.setData(42);
    int value = obj.getData(); // value is now 42
    return 0;
}
```

By using set and get methods, you can control how the private data members are accessed and modified, ensuring that the class maintains its internal integrity and providing a clear interface for interacting with the class.

#### Copy Constructor in Subclasses:

When creating a copy constructor for a subclass, it's essential to call the copy constructor of the base class(es) explicitly. This ensures that the base class members are also copied correctly, creating a complete copy of the derived class object.

If you don't call the base class copy constructor, the base class members might not be copied properly, leading to unexpected behavior. Additionally, if the base class has non-default constructors or requires special handling during copying, you need to make sure those constructors or functions are called explicitly in the derived class copy constructor.

Example

:

```cpp
class Base {
public:
    Base(int value) {
        // Base class constructor
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base(value) {
        // Derived class constructor, calls the Base class constructor explicitly
    }

    Derived(const Derived& other) : Base(other) {
        // Derived class copy constructor, calls the Base class copy constructor explicitly
    }
};
```

In the above example, the `Derived` class's copy constructor explicitly calls the `Base` class's copy constructor to ensure that the `Base` class members are copied correctly.

#### The _clap_trap Suffix:

In the given example, the `_clap_trap` suffix is used to distinguish the names of the `_name_` attributes between the `FragTrap` and `ScavTrap` classes when creating a `DiamondTrap` object. By using this suffix, the `DiamondTrap` class has its own `_name_` attribute separate from the `FragTrap` and `ScavTrap` classes.

When setting the name for `DiamondTrap`, you should call the `setName()` method for both the `FragTrap` and `ScavTrap` classes since they have their separate `_name_` attributes. This is why you see `this->FragTrap::setName(name + "_clap_trap")` and `this->ScavTrap::setName(name + "_clap_trap")` in the `DiamondTrap` constructor.

By using virtual inheritance, the `DiamondTrap` class will have a single instance of the `ClapTrap` class shared between `FragTrap` and `ScavTrap`. This ensures that the `_name_` attribute is not duplicated, and there is no ambiguity in accessing the members from the base class.