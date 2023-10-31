#include "../inc/easyfind.hpp"

// 2 containers:

// std::vector<int> vecInt: This is a vector of integers.
// std::array<int, 5> arrInt: This is an array of integers with a FIXED size of 5.

// >>>> std::list 
// if you need frequent insertions and deletions in the middle of a sequence. 
// >>>> std::vector 
// if you need fast random access and efficient memory usage.

// (Associative containers provide efficient ways 
// to store and retrieve data based on key-value pairs)

int main(void) {
	std::cout << "\n============= VECTOR TEST =============" << std::endl;
    std::vector<int> vecInt;

	// adds a new element at the end of the vector, after its current last element.
	vecInt.push_back(10); // idx 0
	vecInt.push_back(20); // idx 1
	vecInt.push_back(30); // idx 2
	vecInt.push_back(20); // idx 3
	vecInt.push_back(20); // idx 4
	vecInt.push_back(30); // idx 5
	vecInt.push_back(40); // idx 6
	vecInt.push_back(50); // idx 7
	vecInt.push_back(50); // idx 8
	vecInt.push_back(40); // idx 9

	std::cout << "vecInt.size(): " << vecInt.size() << std::endl;
	printContainer(vecInt);
	std::cout << "\n>>>>> find existing element in vecInt" << std::endl;
	::easyfind(vecInt, 10);
	::easyfind(vecInt, 20);
	::easyfind(vecInt, 30);
	::easyfind(vecInt, 40);
	::easyfind(vecInt, 50);

	std::cout << "\n>>>>> try to find non-existing element in vecInt" << std::endl;
	::easyfind(vecInt, 100);

	std::cout << "\n============= ARRAY TEST =============" << std::endl;
    std::array<int, 5> arrInt = {111, 222, 333, 444, 222};
	std::cout << "arrInt.size(): " << arrInt.size() << std::endl;
	printContainer(arrInt);

	std::cout << "\n>>>>> find existing element in arrInt" << std::endl;
    ::easyfind(arrInt, 222);

	std::cout << "\n>>>>> try to find non-existing element in arrInt" << std::endl;
    ::easyfind(arrInt, 666);
	std::cout << std::endl;
    
	std::cout << "\n============= LIST TEST =============" << std::endl;
    std::list<int> listInt;

    listInt.push_back(15);
    listInt.push_back(25);
    listInt.push_back(35);
    listInt.push_back(45);
    listInt.push_back(55);
    listInt.push_back(35);
    listInt.push_back(45);

    std::cout << "listInt.size(): " << listInt.size() << std::endl;
    printContainer(listInt);
    std::cout << "\n>>>>> find existing element in listInt" << std::endl;
    ::easyfind(listInt, 25);
    ::easyfind(listInt, 35);

    std::cout << "\n>>>>> try to find non-existing element in listInt" << std::endl;
    ::easyfind(listInt, 100);

    std::cout << "\n============= DEQUE TEST =============" << std::endl;
    std::deque<int> dequeInt;

    dequeInt.push_back(10);
    dequeInt.push_back(20);
    dequeInt.push_back(30);
    dequeInt.push_back(40);
    dequeInt.push_back(50);
    dequeInt.push_back(60);

    std::cout << "dequeInt.size(): " << dequeInt.size() << std::endl;
    printContainer(dequeInt);
    std::cout << "\n>>>>> find existing element in dequeInt" << std::endl;
    ::easyfind(dequeInt, 20);
    ::easyfind(dequeInt, 50);

    std::cout << "\n>>>>> try to find non-existing element in dequeInt" << std::endl;
    ::easyfind(dequeInt, 70);

    std::cout << std::endl;
    return 0;
}

// ---- DATA STRUCTURE ----
// >>>> std::list: 
// Doubly-linked list - each element is in a node that contains pointers to the previous and next elements.
// >>>> std::vector: 
// Dynamic array, which means elements are stored in contiguous memory locations.
// >>>> std::array:
// Fixed-size array with elements stored in contiguous memory locations.
// >>>> std::deque:
// Double-ended queue - a dynamic array-like container that supports efficient insertion and deletion at both ends.

// ---- MEMORY ALLOCATION ----
// >>>> std::list: 
// Allocates memory for each element separately, which can lead to some overhead in terms of memory usage due to the additional pointers.
// >>>> std::vector:
// Allocates memory for a block of elements, making it more memory-efficient in most cases, as it doesn't have the overhead of separate nodes.
// >>>> std::array:
// Allocates memory for a fixed number of elements, making it memory-efficient with no overhead.
// >>>> std::deque:
// Allocates memory for multiple blocks, allowing for efficient dynamic sizing and insertion at both ends.

// ---- ACCESS TIME ----
// >>>> std::list: 
// Accessing elements by index in a std::list is slower compared to std::vector because it involves traversing 
// the list from the beginning or end, which takes linear time.
// >>>> std::vector: 
// Accessing elements by index in a std::vector is fast and constant time, as it uses direct memory addressing.
// >>>> std::array:
// Accessing elements by index in a std::array is also fast and constant time, similar to std::vector.
// >>>> std::deque:
// Provides fast random access to elements, similar to std::vector, but also supports efficient access and insertion at both ends.

// ---- INSERTION AND DELETION ----
// >>>> std::list: 
// Insertions and deletions in the middle of a list are efficient (constant time) because they involve changing a few pointers. 
// However, inserting or deleting at the beginning or end is faster in std::vector.
// >>>> std::vector: 
// Insertions within the vector (not at the beginning or end) can be slower because they require moving elements to accommodate the change.
// >>>> std::array:
// Has a fixed size, so you cannot insert or delete elements in the middle. You can only modify existing elements.
// >>>> std::deque:
// Supports efficient insertions and deletions at both ends, making it suitable for use cases requiring dynamic queue-like behavior.

// ---- DYNAMIC SIZING ----
// >>>> std::list: 
// Can easily grow or shrink as elements are added or removed, without reallocation.
// >>>> std::vector:
// Can also grow dynamically, but it may require reallocation of memory when it reaches its capacity, 
// which can be an expensive operation in terms of time and may involve copying elements.
// >>>> std::array:
// Has a fixed size and cannot change its size dynamically.
// >>>> std::deque:
// Supports dynamic sizing by allocating memory in blocks, allowing for efficient expansion and contraction as needed.

// ---- ITERATORS ----
// >>>> std::list: 
// Provides bidirectional iterators, allowing efficient traversal in both directions.
// >>>> std::vector:
// Provides random access iterators, allowing efficient random access to elements but not efficient traversal in reverse.
// >>>> std::array:
// Provides random access iterators similar to std::vector.
// >>>> std::deque:
// Provides random access iterators, similar to std::vector, enabling efficient random access to elements at both ends.

// ---- USE CASES ----
// >>>> std::list 
// When you need efficient insertions and deletions in the middle of a sequence, and you don't require fast random access.
// >>>> std::vector 
// When you need fast random access, and you can tolerate less efficient insertions and deletions in the middle.
// >>>> std::array:
// When you need a fixed-size array with fast random access and efficient memory usage.
// >>>> std::deque:
// When you need a double-ended queue with efficient insertions and deletions at both ends, such as implementing a queue or stack.
