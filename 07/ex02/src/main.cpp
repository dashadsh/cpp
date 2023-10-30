#include "../inc/Array.tpp"

# define MAX_VAL 100 // subject test

int main() {
	{
	std::cout << std::endl;

    // Test 1: Default constructor (empty array)
    Array<int> emptyArray;
    std::cout << "TEST 1 - Size of emptyArray: " << emptyArray.size() << std::endl;
	std::cout << std::endl;

    // Test 2: Parameterized constructor (array with Fibonacci numbers)
    Array<int> fibonacciArray(10);  // Let's create an array with 10 elements
	std::cout << "Try to print empty array: ";
	fibonacciArray.printArrayElements();
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

	// std::cout << "------------------------------------------" << std::endl;

	// {
	// // Test 1: Default constructor (empty array of characters)
    // Array<char> emptyCharArray;
    // std::cout << "TEST 1 - Size of emptyCharArray: " << emptyCharArray.size() << std::endl;
	// std::cout << std::endl;

    // // Test 2: Parameterized constructor (array of characters with "Hello")
    // Array<char> helloArray(5);  // Create an array with 5 characters
    // helloArray[0] = 'H';
    // helloArray[1] = 'e';
    // helloArray[2] = 'l';
    // helloArray[3] = 'l';
    // helloArray[4] = 'o';
    // std::cout << "TEST 2 - Hello Array: ";
    // helloArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 3: Copy constructor
    // Array<char> copiedCharArray(helloArray);
    // copiedCharArray[0] = 'W'; // Modify the copy
    // std::cout << "TEST 3 - Copied array: ";
    // copiedCharArray.printArrayElements();
    // std::cout << "Original Hello Array: ";
    // helloArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 4: Assignment operator
    // Array<char> assignedCharArray;
    // assignedCharArray = helloArray;
    // assignedCharArray[1] = 'O'; // Modify the assigned array
    // std::cout << "TEST 4 - Assigned array: ";
    // assignedCharArray.printArrayElements();
    // std::cout << "Original Hello Array: ";
    // helloArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 5: Accessing out of bounds index (should throw an exception)
    // try {
    //     helloArray[10] = 'X'; // Index is out of bounds
    // } catch (const Array<char>::OutOfRangeException& e) {
    //     std::cerr << "TEST 5 - Exception: " << e.what() << std::endl;
    // }
	// std::cout << std::endl;
	// }

	// std::cout << "------------------------------------------" << std::endl;

	// {
	// // Test 1: Default constructor (empty array of strings)
    // Array<std::string> emptyStringArray;
    // std::cout << "TEST 1 - Size of emptyStringArray: " << emptyStringArray.size() << std::endl;
	// std::cout << std::endl;

    // // Test 2: Parameterized constructor (array of strings)
    // Array<std::string> stringArray(3);  // Create an array with 3 strings
    // stringArray[0] = "Hello";
    // stringArray[1] = "World";
    // stringArray[2] = "Array";
    // std::cout << "TEST 2 - String Array: ";
    // stringArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 3: Copy constructor
    // Array<std::string> copiedStringArray(stringArray);
    // copiedStringArray[0] = "New";
    // std::cout << "TEST 3 - Copied array: ";
    // copiedStringArray.printArrayElements();
    // std::cout << "Original String Array: ";
    // stringArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 4: Assignment operator
    // Array<std::string> assignedStringArray;
    // assignedStringArray = stringArray;
    // assignedStringArray[1] = "Universe";
    // std::cout << "TEST 4 - Assigned array: ";
    // assignedStringArray.printArrayElements();
    // std::cout << "Original String Array: ";
    // stringArray.printArrayElements();
	// std::cout << std::endl;

    // // Test 5: Accessing out of bounds index (should throw an exception)
    // try {
    //     stringArray[5] = "Exception"; // Index is out of bounds
    // } catch (const Array<std::string>::OutOfRangeException& e) {
    //     std::cerr << "TEST 5 - Exception: " << e.what() << std::endl;
    // }
	// std::cout << std::endl;
	// }

    {
    std::cout << "---------- subject pdf tests -----------" << std::endl; 

    Array<int> numbers(MAX_VAL);
	// array of ints "mirror" is allocated on the heap (with the same size as numbers!),
	// intended to serve as a mirror/reference for the "numbers" arr.
    int* mirror = new int[MAX_VAL];

	// random number generator for random ints.
    srand(time(NULL));
	// fills both "numbers" arr. and "mirror" arr. with random ints, 
	// both arrays contain same set of values => "mirror" is a copy of "numbers"
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
	// two more Array objects, "tmp" and "test", are created. 
	// "tmp" uses copy constructor
	// "test" uses assignment operator
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	// perfom check if they're the same
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	std::cout << std::endl;
	numbers.printArrayElements();
	std::cout << std::endl;

	// try to access out-of-bounds idx
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	// try to access out-of-bounds idx (may idx is MAX_VAL-1)
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	// "numbers" arr. is filled with new random ints, and the dynamically allocated mirror array is deleted to release the memory.
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
	std::cout << std::endl;
	numbers.printArrayElements();
	std::cout << std::endl;
	
    delete [] mirror;//
	std::cout << std::endl;

    return 0;
	}
}
