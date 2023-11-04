#include "../inc/PmergeMe.hpp"

// -------------------------------------------------------------------------------------------------------------
// std::vector is implemented as a dynamic array, where elements are stored in a contiguous block of memory. 
// This makes it very efficient for accessing elements by their index. 
// Insertions and deletions at the beginning or middle of the vector can be slower 
// because all elements after the insertion point need to be shifted.
// -------------------------------------------------------------------------------------------------------------
// std::deque is implemented as a double-ended queue, which allows for efficient insertions and deletions 
// at both the beginning and end. It typically consists of multiple blocks of memory, 
// so it is not as memory-efficient as a vector but provides faster insertions at both ends.
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// MERGE sort is an efficient and stable sorting algorithm that is well-suited for containers like vectors
// because it relies on efficient random access to elements. It's a divide-and-conquer algorithm that is efficient for larger datasets.
// -------------------------------------------------------------------------------------------------------------
// INSERTION sort is a simple sorting algorithm that works well for small datasets and is particularly 
// efficient when the number of elements to sort is small. It has good cache locality and can take advantage 
// of the efficient insertions available in std::deque.
// -------------------------------------------------------------------------------------------------------------
// FORD-JOHNSON ALGORITHM  - merge-insertion sort is an in-place sorting algorithm designed to perform as few comparisons 
// as possible to sort a collection. 
// Unfortunately, the algorithm needs some specific data structures to keep track of the order of the elements and is 
// generally too slow to be practical. Anyway, it's an interesting algorithm from a computer science point of view; 
// while not performing an optimal number of comparisons, it's still a reference and one of the best known comparison sorts 
// when it comes to reducing the number of comparisons.
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// For small datasets or when the size of the subarray being sorted is small, std::deque might perform better
// due to its efficient insertion characteristics, making insertion sort more effective.
// For larger datasets, or when the subarray size is larger, std::vector might perform better with merge sort, 
// as it can take advantage of better cache locality and efficient random access.
// -------------------------------------------------------------------------------------------------------------

int main(int ac, char **av) {	
	if (ac < 2) {
		std::cout << "Input example: ./PmergeMe 3 5 9 7 4\n";
		return 1;
	}
	
	PmergeMe sorter;
	
	try  {
		sorter.parseInput(ac, av);
		std::cout << "Before:	";
		sorter.printContainer(); 
		
		// std::clock returns processor time consumed by the program, return value is expressed in clock ticks,
		// we declare start_vec of type std::clock_t and initializing it with the current processor time.  
		std::clock_t start_vec = std::clock();
		sorter.sortVector();
		std::clock_t end_vec = std::clock();

		std::clock_t start_deq = std::clock();
		sorter.sortDeque();
		std::clock_t end_deq = std::clock();
		
		std::cout << "After:	";
		sorter.printContainer();

		// CLOCKS_PER_SEC is a macro defined in <ctime> header, it represents the number of clock ticks per second.
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " 
			<< ((end_vec - start_vec) * 1000000 / CLOCKS_PER_SEC) << "us\n";
			// divide by CLOCKS_PER_SEC to convert clock ticks to seconds
			// multiply by 1000000 to convert seconds to microseconds
		
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " 
			<< ((end_deq - start_deq) * 1000000  / CLOCKS_PER_SEC) << "us\n";
	
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
