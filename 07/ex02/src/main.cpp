#include "../inc/Array.tpp"

#include <cstdlib> // rand()
#include <ctime> // time()

# define SIZE 10 // own tests
# define MAX_VAL 750 // subject test

int main(void) {
    std::cout << "------ custom tests -------" << std::endl; 
	{	
		std::cout << "##### ARRAY CREATION TESTING:" << std::endl;
        std::cout << "##### arr1 w/o parameter:" << std::endl;
        Array<int> arr1; // Explicitly specifying template parameters for class instantiation
        std::cout << "arr1 elements: ";
        arr1.printArrayElements();
    }
	std::cout << std::endl;
    {
		std::cout << "##### ARRAY CREATION TESTING-2:" << std::endl;
        std::cout << "##### arr2 (contains 3 unsigned int):" << std::endl;
        Array<int> arr2(3);
        std::cout << "arr2 elements: ";
        arr2.printArrayElements();
    }
	std::cout << std::endl;
    {
        std::cout << "##### ESXEPTION TESTING:" << std::endl;
        std::cout << "##### arr3 (contains 3 unsigned int):" << std::endl;
        Array<int> arr3(3);
        std::cout << "arr3 elements: ";
        arr3.printArrayElements();
        try {
            std::cout << "try to access arr3[-5]" << std::endl;
            std::cout << arr3[-5] << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << "try to access arr3[4]" << std::endl;
            std::cout << arr3[4] << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
		try {
            std::cout << "try to access arr3[1]" << std::endl;
            std::cout << arr3[1] << std::endl;
        }
        catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
	std::cout << std::endl;
    {
        std::cout << "##### COPY CONSTRUCTOR TESTING " << std::endl;
		std:: cout << "##### arr4 (contains SIZE amt of obj):" << std::endl;
        Array<int>	arr4(SIZE);
        std::cout << "arr4 elements: ";
        arr4.printArrayElements();

// initializes the random number generator using the current time as the seed. 
// done to ensure that the random numbers generated in the following loop are 
// different each time the program is run.
        std::srand(std::time(NULL));

        for (int i = 0; i < SIZE; i++) {
            const int	value = std::rand() % 100; 
			// int rand (void) returns a pseudo-random integral number 
			// in the range between 0 and RAND_MAX. 
			// % 100 makes random numbers in the range 0 to 99.
            arr4[i] = value;
        }
        std::cout << "##### arr4 with 0-100 values: " << std::endl;
        arr4.printArrayElements();
        std::cout << "##### create array by copy of arr4 w arr4CopyConstructor" << std::endl;
        Array<int> arr4CopyConstructor = arr4;
        std::cout << "print copied elem: " << std::endl;
        arr4CopyConstructor.printArrayElements();
    }
	std::cout << std::endl;
    {
        std::cout << "##### ASSIGNMENT OPERATOR TESTING" << std::endl;
        std::cout << "arr5 (contain 4 ints):" << std::endl;
        Array<int>	arr5(4);
        std::cout << "arr5 elements: ";
        arr5.printArrayElements();
        
        std::cout << "arr6 (contains SIZE amt of int)" << std::endl;
        Array<int>	arr6(SIZE);
        std::cout << "arr6 elements: ";
        arr6.printArrayElements();
        
        arr5 = arr6;
        std::cout << "arr5 elements: ";
        arr5.printArrayElements();
    }
	std::cout << std::endl;
    {
        std::cout << "##### OTHER DATA TYPES TESTING" << std::endl;
        std::cout << "arr7 (contains 10 strings):" << std::endl;
        Array<std::string> arr7(SIZE);
        std::cout << "arr7 elements: ";
        arr7.printArrayElements();
        
        arr7[0] = "Hi";
        arr7[1] = ",";
        arr7[2] = "Tinkerbell!";
        arr7[3] = "_";
        arr7[4] = "Hi";
        arr7[5] = "";
        arr7[6] = "baby";
        arr7[7] = "_";
        arr7[8] = "girl";
        arr7[9] = "!";
        std::cout << "arr7 elements: " << std::endl;
        arr7.printArrayElements();
    }
	std::cout << std::endl;
    {
        std::cout << "##### new[]" << std::endl;
        std::cout << "arr8 (10 int): " << std::endl;
        Array<int> arr8(SIZE);
        std::srand(std::time(NULL));
        for (int i = 0; i < SIZE; i++) {
            const int	value = std::rand() % 100;
            arr8[i] = value;
        }
        std::cout << "arr8 elements: ";
        arr8.printArrayElements();

        std::cout << "newArray (10 int): " << std::endl;
        int *newArray = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            newArray[i] = arr8[i];
			std::cout << newArray[i];
			if (i < SIZE - 1)
        		std::cout << " - ";
			else
        		std::cout << std::endl;
    }
        delete[] newArray;
    }
    std::cout << std::endl;
	std::cout << std::endl;


    {
    std::cout << "------ subject pdf tests -------" << std::endl; 
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//

    return 0;
}
}
