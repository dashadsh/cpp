#include "../inc/easyfind.hpp"

/*
std::list (Doubly-linked list) - efficient insertions and deletions in the middle

>>>>> ALGORITHMS
std::insert: inserting elements at specified positions.
std::erase: remove elements by providing iterators.
std::splice: transfers elements from one list to another.

>>>>> ITERATORS
begin(), end(): forward traversal.
rbegin(), rend(): reverse traversal.

>>>>> MEMBER FUNCTIONS
push_back: adds an element to the end.
push_front: adds an element to the front.
pop_back: removes the last element.
pop_front: removes the first element.
size: returns the number of elements.
empty: checks if the list is empty.
--------------------------------
std::vector (Dynamic array) - fast random access

>>>>> ALGORITHMS
std::at and operator[]: For random access by index.
std::find: Useful for searching elements.

>>>>> ITERATORS
begin(), end(): For forward traversal.

>>>>> MEMBER FUNCTIONS
push_back: Adds an element to the end.
pop_back: Removes the last element.
at and operator[]: Provides random access by index.
size: Returns the number of elements.
empty: Checks if the vector is empty.
resize: Changes the size of the vector.
--------------------------------
std::array (Fixed-size array) - fixed-size array with fast access

>>>>> ALGORITHMS
std::at and operator[]: For direct access to elements.
std::sort and std::binary_search: For sorting and searching.

>>>>> ITERATORS
begin(), end(): For forward traversal.

>>>>> MEMBER FUNCTIONS
at and operator[]: Provides direct access to elements.
size: Returns the number of elements.
empty: Checks if the array is empty.
--------------------------------
std::deque (Double-ended queue) - efficient insertions and deletions at both ends

>>>>> ALGORITHMS
push_front and push_back: Efficient for inserting elements at the front and back.
pop_front and pop_back: For removing elements from the front and back.
std::at, operator[], and std::find: Suitable for random access.

>>>>> ITERATORS
begin(), end(): For forward traversal.
rbegin(), rend(): For reverse traversal.

>>>>> MEMBER FUNCTIONS
push_back: Adds an element to the end.
push_front: Adds an element to the front.
pop_back: Removes the last element.
pop_front: Removes the first element.
at and operator[]: Provides random access by index.
size: Returns the number of elements.
empty: Checks if the deque is empty.
*/

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
	::easyfind(vecInt, 10); // :: - global scope, not a member of a class
	::easyfind(vecInt, 20);
	::easyfind(vecInt, 30);
	::easyfind(vecInt, 40);
	::easyfind(vecInt, 50);

	std::cout << "\n>>>>> try to find non-existing element in vecInt" << std::endl;
	::easyfind(vecInt, 100);
    
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

/*
**1. std::list:**
   - Data Structure: Doubly-linked list with each element in a node containing pointers to the previous and next elements.
   - Memory Allocation: Allocates memory for each element separately.
   - Access Time: Slower access by index, involving linear traversal.
   - Insertion and Deletion: Efficient insertions and deletions in the middle.
   - Dynamic Sizing: Easily grows or shrinks without reallocation.
   - Iterators: Bidirectional iterators.
   - Use Cases: Efficient for insertions and deletions in the middle without requiring fast random access.

**2. std::vector:**
   - Data Structure: Dynamic array storing elements in contiguous memory locations.
   - Memory Allocation: Allocates memory for a block of elements.
   - Access Time: Fast and constant-time access by index.
   - Insertion and Deletion: Slower for insertions within the vector.
   - Dynamic Sizing: Can grow dynamically but may involve reallocation.
   - Iterators: Random access iterators.
   - Use Cases: Fast random access is required, and less efficient insertions and deletions in the middle are acceptable.

**3. std::array:**
   - Data Structure: Fixed-size array storing elements in contiguous memory locations.
   - Memory Allocation: Allocates memory for a fixed number of elements.
   - Access Time: Fast and constant-time access by index.
   - Insertion and Deletion: Not applicable; size is fixed.
   - Dynamic Sizing: Cannot change size dynamically.
   - Iterators: Random access iterators.
   - Use Cases: When you need a fixed-size array with fast random access and efficient memory usage.

**4. std::deque:**
   - Data Structure: Double-ended queue with memory allocated in blocks.
   - Memory Allocation: Allocates memory for multiple blocks.
   - Access Time: Fast random access to elements.
   - Insertion and Deletion: Efficient at both ends.
   - Dynamic Sizing: Supports dynamic sizing by allocating memory in blocks.
   - Iterators: Random access iterators.
   - Use Cases: When you need a double-ended queue with efficient insertions and deletions at both ends, such as implementing a queue or stack.
*/
