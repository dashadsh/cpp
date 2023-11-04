#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm> // _vec.size, _deq.size
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

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

		class ErrorException: public std::exception { // Add this class definition
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
       		if (start < end) {
				// if container size is small, we use the insert sort algorithm
            	if (end - start < 10) {
                	insertSort(container, start, end);
				// for larger containers, we use the merge sort algorithm
            	} else {
                	int mid = start + (end - start) / 2;

					// recursively sort the two halves
                	mergeInsertSort(container, start, mid);
                	mergeInsertSort(container, mid + 1, end);

					// merge the two halves together
                	merge(container, start, mid, end);
            	}
       		}
    	}

    	// insert sort for a container of integers
    	template <typename Container>
    	void insertSort(Container& container, int start, int end) {
        	for (int i = start + 1; i <= end; ++i) {
            	int key = container[i];
            	int j = i - 1;

				// shift elem. greater than key to the right
            	for (; j >= start && container[j] > key; --j)
                	container[j + 1] = container[j];
			
				// insert key into right position
            	container[j + 1] = key;
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
