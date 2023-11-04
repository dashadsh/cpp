#include "../inc/PmergeMe.hpp"

// • The name of the program is PmergeMe.
// • Your program must be able to use a positive integer sequence as argument.
// • Your program must use the merge-insert sort algorithm to sort the positive integer sequence.

// Ford-Johnson algorithm
// also known as merge-insertion sort is an in-place sorting algorithm designed
// to perform as few comparisons as possible to sort a collection. 
// Unfortunately, the algorithm needs some specific data structures to keep track 
// of the order of the elements and is generally too slow to be practical.
// Anyway, it is an interesting algorithm from a computer science point of view; 
// while not performing an optimal number of comparisons, it's still a reference and 
// one of the best known comparison sorts when it comes to reducing the number of comparisons.

// you must use at least two different containers in your code to validate this exercise.  
// Your program must be able to handle at least 3000 different integers.

// On the first line you must display an explicit text followed by the unsorted positive integer sequence.
// On the second line you must display an explicit text followed by the sorted positive integer sequence.
// On the third line you must display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the positive integer sequence.
// On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.

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

		//std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " 
    	//	<< static_cast<double>(end_vec - start_vec) * 1000000.0 / CLOCKS_PER_SEC << "us\n";
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " 
			<< ((end_vec - start_vec) * 1000000 / CLOCKS_PER_SEC) << "us\n";
			// divide by CLOCKS_PER_SEC to convert clock ticks to seconds
			// multiply by 1000000 to convert seconds to microseconds
		
		//std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " 
    	//	<< static_cast<double>(end_deq - start_deq) * 1000000.0 / CLOCKS_PER_SEC << "us\n";
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " 
			<< ((end_deq - start_deq) * 1000000  / CLOCKS_PER_SEC) << "us\n";
	
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
