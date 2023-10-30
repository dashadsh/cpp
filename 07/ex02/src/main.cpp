#include "../inc/Array.tpp"

#include <cstdlib> // rand()
#include <ctime> // time()

# define MAX_VAL 750 // subject test

int main() {
	{
	std::cout << std::endl;

    // Test 1: Default constructor (empty array)
    Array<int> emptyArray;
    std::cout << "TEST 1 - Size of emptyArray: " << emptyArray.size() << std::endl;
	std::cout << std::endl;

    // Test 2: Parameterized constructor (array with Fibonacci numbers)
    Array<int> fibonacciArray(10);  // Let's create an array with 10 elements
    int a = 0, b = 1;
    for (unsigned int i = 0; i < fibonacciArray.size(); ++i) {
        fibonacciArray[i] = a;
        int temp = a + b;
        a = b;
        b = temp;
    }
    std::cout << "TEST 2 - Fibonacci Array: ";
    fibonacciArray.printArrayElements();
	std::cout << std::endl;

    // Test 3: Copy constructor
    Array<int> copiedArray(fibonacciArray);
    copiedArray[0] = 100; // Modify the copy
    std::cout << "TEST 3 - Copied array: ";
    copiedArray.printArrayElements();
    std::cout << "Original Fibonacci Array: ";
    fibonacciArray.printArrayElements();
	std::cout << std::endl;

    // Test 4: Assignment operator
    Array<int> assignedArray;
    assignedArray = fibonacciArray;
    assignedArray[1] = 200; // Modify the assigned array
    std::cout << "TEST 4 - Assigned array: ";
    assignedArray.printArrayElements();
    std::cout << "Original Fibonacci Array: ";
    fibonacciArray.printArrayElements();
	std::cout << std::endl;

    // Test 5: Accessing out of bounds index (should throw an exception)
    try {
        fibonacciArray[15] = 42; // Index is out of bounds
    } catch (const Array<int>::OutOfRangeException& e) {
        std::cerr << "TEST 5 - Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;

	{
	// Test 1: Default constructor (empty array of characters)
    Array<char> emptyCharArray;
    std::cout << "TEST 1 - Size of emptyCharArray: " << emptyCharArray.size() << std::endl;
	std::cout << std::endl;

    // Test 2: Parameterized constructor (array of characters with "Hello")
    Array<char> helloArray(5);  // Create an array with 5 characters
    helloArray[0] = 'H';
    helloArray[1] = 'e';
    helloArray[2] = 'l';
    helloArray[3] = 'l';
    helloArray[4] = 'o';
    std::cout << "TEST 2 - Hello Array: ";
    helloArray.printArrayElements();
	std::cout << std::endl;

    // Test 3: Copy constructor
    Array<char> copiedCharArray(helloArray);
    copiedCharArray[0] = 'W'; // Modify the copy
    std::cout << "TEST 3 - Copied array: ";
    copiedCharArray.printArrayElements();
    std::cout << "Original Hello Array: ";
    helloArray.printArrayElements();
	std::cout << std::endl;

    // Test 4: Assignment operator
    Array<char> assignedCharArray;
    assignedCharArray = helloArray;
    assignedCharArray[1] = 'O'; // Modify the assigned array
    std::cout << "TEST 4 - Assigned array: ";
    assignedCharArray.printArrayElements();
    std::cout << "Original Hello Array: ";
    helloArray.printArrayElements();
	std::cout << std::endl;

    // Test 5: Accessing out of bounds index (should throw an exception)
    try {
        helloArray[10] = 'X'; // Index is out of bounds
    } catch (const Array<char>::OutOfRangeException& e) {
        std::cerr << "TEST 5 - Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;

	{
	// Test 1: Default constructor (empty array of strings)
    Array<std::string> emptyStringArray;
    std::cout << "TEST 1 - Size of emptyStringArray: " << emptyStringArray.size() << std::endl;
	std::cout << std::endl;

    // Test 2: Parameterized constructor (array of strings)
    Array<std::string> stringArray(3);  // Create an array with 3 strings
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Array";
    std::cout << "TEST 2 - String Array: ";
    stringArray.printArrayElements();
	std::cout << std::endl;

    // Test 3: Copy constructor
    Array<std::string> copiedStringArray(stringArray);
    copiedStringArray[0] = "New";
    std::cout << "TEST 3 - Copied array: ";
    copiedStringArray.printArrayElements();
    std::cout << "Original String Array: ";
    stringArray.printArrayElements();
	std::cout << std::endl;

    // Test 4: Assignment operator
    Array<std::string> assignedStringArray;
    assignedStringArray = stringArray;
    assignedStringArray[1] = "Universe";
    std::cout << "TEST 4 - Assigned array: ";
    assignedStringArray.printArrayElements();
    std::cout << "Original String Array: ";
    stringArray.printArrayElements();
	std::cout << std::endl;

    // Test 5: Accessing out of bounds index (should throw an exception)
    try {
        stringArray[5] = "Exception"; // Index is out of bounds
    } catch (const Array<std::string>::OutOfRangeException& e) {
        std::cerr << "TEST 5 - Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;

    // {
    // std::cout << "------ subject pdf tests -------" << std::endl; 

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];

    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++) {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++) {
    //     if (mirror[i] != numbers[i]) {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }
    // try {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++) {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
	// std::cout << std::endl;

    // return 0;
	// }
}
