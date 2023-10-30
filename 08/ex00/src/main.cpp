#include "../inc/easyfind.hpp"

// 2 containers:

// std::vector<int> vecInt: This is a vector of integers.
// std::array<int, 5> arrInt: This is an array of integers with a FIXED size of 5.

// >>>> std::list 
// if you need frequent insertions and deletions in the middle of a sequence. 
// >>>> std::vector 
// if you need fast random access and efficient memory usage.

int main(void) {
	std::cout << "\n============= Test 1 =============" << std::endl;
    std::vector<int> vecInt;

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

	std::cout << "\n============= Test 2 =============" << std::endl;
    std::array<int, 5> arrInt = {111, 222, 333, 444, 222};
	std::cout << "arrInt.size(): " << arrInt.size() << std::endl;
	printContainer(arrInt);

	std::cout << "\n>>>>> find existing element in arrInt" << std::endl;
    ::easyfind(arrInt, 222);

	std::cout << "\n>>>>> try to find non-existing element in arrInt" << std::endl;
    ::easyfind(arrInt, 666);
	std::cout << std::endl;
    return(0);
}

// ---- DATA STRUCTURE ----
// >>>> std::list: 
// doubly-linked list - each element is in a node that contains pointers to the previous and next elements.
// >>>> std::vector: 
// dynamic array, which means elements are stored in contiguous memory locations.
// >>>> std::array:
// fixed-size array with elements stored in contiguous memory locations.

// ---- MEMORY ALLOCATION ----
// >>>> std::list: 
// allocates memory for each element separately, which can lead to some overhead in terms of memory usage due to the additional pointers.
// >>>> std::vector:
// allocates memory for a block of elements, making it more memory-efficient in most cases, as it doesn't have the overhead of separate nodes.
// >>>> std::array:
// allocates memory for a fixed number of elements, making it memory-efficient with no overhead.

// ---- ACCESS TIME ----
// >>>> std::list: 
// Accessing elements by index in a std::list is slower compared to std::vector bc it involves traversing 
// the list from the beginning or end, which takes linear time.
// >>>> std::vector: 
// accessing elements by idx in a std::vector is fast and constant time, as it uses direct memory addressing.
// >>>> std::array:
// accessing elements by idx in a std::array is also fast and constant time, similar to std::vector.

// ---- INSERTION AND DELETION ----
// >>>> std::list: 
// in the middle of the list are efficient (constant time) bc they involve changing a few pointers. 
// However, inserting or deleting at the beginning or end is faster in std::vector.
// >>>> std::vector: 
// within the vector (not at the beginning or end) can be slower because they require moving elements to accommodate the change.
// >>>> std::array:
// has a fixed size, so you cannot insert or delete elements in the middle. You can only modify existing elements.

// ---- DYNAMIC SIZING ----
// >>>> std::list: 
// can easily grow or shrink as elements are added or removed, without reallocation.
// >>>> std::vector:
// can also grow dynamically, but it may require reallocation of memory when it reaches its capacity, 
// which can be an expensive operation in terms of time and may involve copying elements.
// >>>> std::array:
// has a fixed size and cannot change its size dynamically.

// ---- ITERATORS ----
// >>>> std::list: 
// provides bidirectional iterators, allowing efficient traversal in both directions.
// >>>> std::vector:
// provides random access iterators, allowing efficient random access to elements but not efficient traversal in reverse.
// >>>> std::array:
// provides random access iterators similar to std::vector.

// ---- USE CASES ----
// >>>> std::list 
// when you need efficient insertions and deletions in the middle of a sequence, and you don't require fast random access.
// >>>> std::vector 
// when you need fast random access, and you can tolerate less efficient insertions and deletions in the middle.
// >>>> std::array:
// when you need a fixed-size array with fast random access and efficient memory usage.
