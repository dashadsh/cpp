#include "../inc/PmergeMe.hpp"
// ---------------------------------------------------------
// Merge Sort: efficient and stable sorting algorith suitable for large datasets.
// Efficient random access and cache locality, making it highly compatible with std::vector.
// ---------------------------------------------------------
// Insertion Sort: simple and efficient for small datasets. Compatible with both std::vector and std::deque, 
// and it is particularly efficient for small datasets.
// ---------------------------------------------------------
// Merge-Insert Sort: hybrid sorting algorithm that uses merge sort for larger subarrays and insertion sort for
// smaller subarrays. Highly compatible with std::vector due to its efficient random access and cache locality during
// merge steps. Also compatible with std::deque and can efficiently handle insertion sort for small subarrays.
// ---------------------------------------------------------
// Compatibility with std::vector:
// - Merge Sort: Highly compatible, benefits from efficient random access and cache locality.
// - Insertion Sort: Compatible, efficient for small datasets.
// - Merge-Insert Sort: Highly compatible, benefits from efficient random access and cache locality for merge steps.
// ---------------------------------------------------------
// Compatibility with std::deque:
// - Merge Sort: Compatible, but may not be as memory-efficient as std::deque.
// - Insertion Sort: Compatible, benefits from efficient insertions at both ends.
// - Merge-Insert Sort: Compatible, can efficiently handle Insertion Sort for small subarrays.
// ---------------------------------------------------------

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
