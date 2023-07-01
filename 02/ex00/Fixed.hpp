#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 _value; // this int stores raw value of the fixed-point number
    static const int    _fractionalBits = 8; // this is the number of fractional bits

public:
    // DEFAULT CONSTRUCTOR:
    Fixed();    
	// COPY CONSTRUCTOR: 
    Fixed(const Fixed &src);   
	// DESTRUCTOR
	~Fixed();

	// ASSIGNMENT OPERATOR: 
    Fixed& operator=(const Fixed &rhs);  

    int getRawBits(void) const; // getRawBits function returns raw value of the fixed-point number
    void setRawBits(int const raw); // setRawBits function sets the raw value of the fixed-point number

};

#endif

// DEFAULT CONSTRUCTOR: 
// called when an object of the class is created w/o any arguments

// -----------------------------------------------------------------------------------------------------------------------

// COPY CONSTRUCTOR: 
// Making the param. a reference (const Fixed &src) means that copy constructor gets a reference to the existing obj, 
// rather than creating new copy. 
// This allows the copy constructor to access the original object's data without triggering another call to the copy constructor.
// The const keyword is used to ensure that the original object cannot be modified by the copy constructor. 
// This provides a safeguard against accidental modifications to the original object.

// The reason we need to use the copy constructor in this project is that we are creating new Fixed objects that are copies of existing Fixed objects.

// In the main function, this line:
// Fixed b(a);
// creates a new Fixed object b that is a copy of Fixed object a. 
// The compiler needs to know how to create b from a, and the copy constructor is where we specify how this is done.

// Without a copy constructor, the compiler would simply copy all of the fields in a to b. This is known as a shallow copy. 
// For many classes, especially those that contain pointers, this shallow copy behavior is not correct.

// Although our Fixed class does not contain pointers and could technically rely on the default copy constructor provided by the compiler,
// defining our own copy constructor is a good practice. It allows us to control the copying process, which can be vital in more complex classes.

// Additionally, it gives us an opportunity to log when a copy constructor is called, which can be useful for debugging and understanding the program's flow, 
// as seen with the statement std::cout << "Copy constructor called" << std::endl; in our code.

// -----------------------------------------------------------------------------------------------------------------------

// ASSIGNMENT OPERATOR
// (operator=) is used to assign the values from one object to another already existing object.
// breakdown:
//
// Fixed&: 
// operator returns reference to a Fixed object, what allows chain assignments like a = b = c;
//
// operator=: 
// C++ syntax to indicate that we're overloading the assignment operator (=).
// 
// SIC! Operator overloading:
// is a feature in C++ where you can redefine or customize the behavior of standard operators (like =, +, -, *, etc.) 
// when they're used with user-defined types (like objects of a class that you've defined).
// When you overload the assignment operator (=), you define how an object of your class should be assigned from another object of the same class.
//
// (const Fixed &rhs): 
// operator takes a reference to a constant Fixed object as its parameter. 
// rhs stands for "right-hand side", which is conventional in the context of assignment, as in lhs = rhs;
// Const keyword is used to ensure that the original object (rhs in this case) cannot be modified by the assignment operator.
// Inside the assignment operator, there's typically code that copies the state from the right-hand side object to the left-hand side object. 
// For instance, in the case of the Fixed class, it could look like this:
//
// Fixed& Fixed::operator=(const Fixed &rhs) {
//     std::cout << "Assignment operator called" << std::endl;
//   
//     // Protect against invalid self-assignment (i.e., a = a;).
//     if (this != &rhs) {
//         // Copy the value.
//         this->_value = rhs.getRawBits();
//     }
//    
//     // By convention, always return *this.
//     return *this;
// }
//
// Here, I'm using the assignment operator in the main function on this line:
//
// c = b;
// This assigns the values of Fixed object b to the already existing Fixed object c using your custom assignment operator.

// Defining own assignment operator is crucial when dealing with dynamically allocated memory or resources. 
// For a class like Fixed, which doesn't manage such resources, you could also use the default assignment operator generated by the compiler. 

// -----------------------------------------------------------------------------------------------------------------------

// OPERATOR OVERLOAD

// Operator overloading is a feature in C++ where you can redefine or customize the behavior of standard operators (like =, +, -, *, etc.) 
// when they're used with user-defined types (like objects of a class that you've defined).

// When you overload the assignment operator (=), you define how an object of your class should be assigned from another object of the same class.

// Here's a simple example. Suppose we have a class Foo:

// class Foo {
// private:
//     int _value;

// public:
//     Foo(int value) : _value(value) { }

//     // This is the overloaded assignment operator.
//     Foo& operator=(const Foo& other) {
//         if (this != &other) {
//             _value = other._value;
//         }
//         return *this;
//     }

//     int getValue() const { return _value; }
// };

// In this example, the assignment operator is being overloaded to assign the _value from one Foo object to another. 
// The line Foo& operator=(const Foo& other) declares the overloaded assignment operator. 
// Inside the function, we first check that we're not assigning an object to itself (a common error), 
// then we copy the _value from the other object to the current object (this).

// The result of overloading the assignment operator is that you can now use the = operator with Foo objects, like this:
// Foo a(10);
// Foo b = a;  // Uses the overloaded assignment operator.

// In this line, b is assigned the same _value as a, thanks to the overloaded assignment operator.