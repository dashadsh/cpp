#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string> // std::string
#include <algorithm> // _vec.size, _deq.size
#include <vector> // std::vector
#include <deque> // std::deque
#include <sstream> // std::stringstream
#include <ctime> // std::clock_t, std::clock, CLOCKS_PER_SEC

class PmergeMe {

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
	
		void parseInput(int ac, char **av);
		void printContainer();
		void sortVector();
		void sortDeque();

		class ErrorException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

 	private:
		std::vector<int> _vec; // std::vector is a sequence container that encapsulates dynamic size arrays.
		std::deque<int> _deq; // std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end.

		// mergeInsertSort - hybrid sorting func. that uses both 
		// merge sort and insertion sort. 
		// It uses insertion sort when the size of the subarray is less than 10, 
		// and merge sort otherwise.
    	template <typename Container>
    	void mergeInsertSort(Container& container, int start, int end) {
       		if (start < end) { // if start idx is less than end idx - container with 1 elem. is 'sorted' already
				// if container size is small, we use the insert sort algorithm
            	if (end - start < 10) {
                	insertSort(container, start, end);
				// for larger containers, we use the merge sort algorithm
            	} else {
                	int mid = start + (end - start) / 2;

					// recursively sort the two halves !!!
                	mergeInsertSort(container, start, mid);
                	mergeInsertSort(container, mid + 1, end);

					// merge the two halves together
                	merge(container, start, mid, end);
            	}
       		}
    	}

    	// insert sort for a container of integers
		// example: 3 2 1
    	template <typename Container>
    	void insertSort(Container& container, int start, int end) { // start = 0, end = 2
        	for (int i = start + 1; i <= end; ++i) { // i = 1

            	int key = container[i]; // store current elem in 'key' (key = 2)
            	int j = i - 1; // start 2nd loop with idx j (j = 1)

				// compare 'key' (2) to elements in sorted portion of the container from 'start' to 'j'.
        		// If element in sorted portion is greater than key, move it 1 position to the right
        		// to make room for key.
            	for (; j >= start && container[j] > key; --j) // no initialisation, just condition !!!!
                	container[j + 1] = container[j];  // Shift elements to the right
 				// in 1st iteration, 2 is compared with 3. since 3 > 2, we move 3 to the right.
        		// container becomes "3, 3, 1" & j becomes 0.
        		// continue until 'key' (2) >= container[j] or j reaches 'start'

				// put key (2) at its correct position in the sorted sequence
            	container[j + 1] = key; // containter becomes "2, 3, 1"
        	}
    	}

    	// merge two halves of a container of integers
    	template <typename Container>
    	void merge(Container& container, int start, int mid, int end) {
        	int i, j, k;
        	int n1 = mid - start + 1;
        	int n2 = end - mid;

			// temp. containers for the left and right halves
        	Container left(n1);
        	Container right(n2);

			// cpy data from the main container to temp. containers
        	for (i = 0; i < n1; ++i)
            	left[i] = container[start + i];
        	for (j = 0; j < n2; ++j)
            	right[j] = container[mid + 1 + j];

        	i = 0;
        	j = 0;
        	k = start;

			// merge 2 halves back into main container
        	while (i < n1 && j < n2) {
            	if (left[i] <= right[j])
                	container[k++] = left[i++];
            	else
                	container[k++] = right[j++];
        	}

			// copy any remaining elem. from the left and right halves
        	while (i < n1)
            	container[k++] = left[i++];

        	while (j < n2)
            	container[k++] = right[j++];
    	}
	};

#endif

/* Insert Sort: 
Here's how the values change based on the example 3 2 1:

Original array: 3 2 1 (As it is)
In the first iteration:
key becomes 2 (from index 1, since i is 1)
j starts at 0 (from i - 1)
The inner loop compares key (2) to the elements in the sorted portion (only 3) and shifts 3 to the right.
Array: 3 3 1
Finally, key (2) is inserted at index 0.
Array: 2 3 1
In the second iteration:
key becomes 1 (from index 2, since i is 2)
j starts at 1 (from i - 1)
The inner loop compares key (1) to the elements in the sorted portion (3 and 2) and shifts 3 and 2 to the right.
Array: 2 3 3
Finally, key (1) is inserted at index 0.
Array: 1 2 3
After the sorting process is complete, the sorted array is {1, 2, 3}.

*/
