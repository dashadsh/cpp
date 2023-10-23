#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

/*
A class template Array<T> provides a flexible container class 
that acts like an array of elements. 
The T is a placeholder for the data type, allowing you to create instances 
of the Array class with different data types, such as:
integers, floats, characters, strings, or even arrays of std::string, among others.

template <typename T>
class Array {
    // Class members and methods go here.
};

Semantics:
Template Declaration: 
You define the class template using the template <typename T> syntax, 
where T serves as a placeholder for the actual data type that the class will work with. 
You can choose any identifier as the placeholder, but T is a common and meaningful choice.

Data Type Flexibility: 
By using T in place of specific data types (e.g., int, float, char), 
the class template becomes versatile and can be instantiated with a wide range of data types. 
For instance, Array<int> represents an array of integers, 
and Array<float> represents an array of floating-point numbers.

Methods: 
You can define methods and member functions within the class template, 
just as you would with a regular class. These methods can operate on the data of type T.

Instantiation: 
When you want to create instances of the class template, 
you must specify the data type by providing it within angle brackets. For example:
Array<int> intArray;        // Instantiate an Array of integers.
Array<float> floatArray;    // Instantiate an Array of floats.

Explicit Instantiation: 
Unlike template functions, when you create instances of class templates, 
you need to explicitly specify the data type for the class. 
This ensures that the compiler knows which type T should represent for each instance. Example:
template <typename T>
class Array {
public:
    Array(size_t size) : size_(size) {
        data_ = new T[size_];
    }

    void Set(size_t index, T value) {
        data_[index] = value;
    }

    T Get(size_t index) const {
        return data_[index];
    }

    ~Array() {
        delete[] data_;
    }

private:
    T* data_;
    size_t size_;
};
In this example, the Array class template is defined with a generic type T. 
It provides methods for setting and retrieving elements of the array. 
Instances of this class template can be created with specific data types,
like Array<int> or Array<float, and these instances will behave as arrays of the specified data type.

https://isocpp.org/wiki/faq/templates#class-templates
*/

template < class T >
class Array {
		private:
		        unsigned int    _size;
		        T				*_array;

        public:
		        Array();
		        Array(unsigned int n);
		        Array(const Array &src);
                ~Array();

				// operator overload
		        Array &operator=(const Array &src);
		        T &operator[](unsigned int index);

		        // getter
		        unsigned int	size(void);

		        // member func.
				void    printArrayElements(void);

		        // exception
                class OutOfRangeException : public std::exception {
			        public:
				        virtual const char* what() const throw();
		        };

                
};

#endif
