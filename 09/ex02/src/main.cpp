#include "../inc/PmergeMe.hpp"
// ----------------------------------------------------------------------------------------------
// Merge-Insertion Sort:
// 1. input list is divided into smaller sublists, typically using a recursion, 
// until each sublist becomes small enough for efficient sorting -> GOOD MEMORY MANAGEMENT
// 2. When size of the sublists reaches certain threshold, switch to insertion sort to sort the sublists.
// Insertion sort works by inserting elements into the correct positions within the sorted part of the list.
// 3. Merge sort: after sublists are sorted using insertion sort, they are merged
// back together using the merge step of the merge sort algorithm.

// std::vec  - dynamic arrays, efficient random access to elements.
// contiguous storage of elements allows constant time random access to any element in the sequence.
// Random access is essential for merge sort since it frequently divides and merges lists.
// Merge sort can benefit from vectors due to efficient indexing, making it a preferred choice for this algorithm.

// std::deque - double-ended queue, efficient insertion and deletion at both its beginning and its end.
// Deques isn't required to store its elements in contiguous storage -> LESS GOOD MEMORY MANAGEMENT
// Insertion sort benefits from efficient insertions since it frequently inserts elements into their correct positions.
// Insertion sort can perform better with deques when it comes to maintaining the partially sorted portion of the list, 
// making it a preferred choice for this algorithm.
// ----------------------------------------------------------------------------------------------

// std::vector is better for merge sort / merge-insert sort & bigger containers
// std::deque is better used for insertion sort & smaller containers

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
