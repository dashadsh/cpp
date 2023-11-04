#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <deque>
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
		std::vector<int> _vec;
		std::deque<int> _deq;

	// Merge and insert sort a container of integers
    template <typename Container>
    void mergeInsertSort(Container& container, int start, int end) {
        if (start < end) {
            if (end - start < 10) {
                insertSort(container, start, end);
            } else {
                int mid = start + (end - start) / 2;

                mergeInsertSort(container, start, mid);
                mergeInsertSort(container, mid + 1, end);

                merge(container, start, mid, end);
            }
        }
    }

    // Insert sort a container of integers
    template <typename Container>
    void insertSort(Container& container, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            int key = container[i];
            int j = i - 1;

            for (; j >= start && container[j] > key; --j)
                container[j + 1] = container[j];

            container[j + 1] = key;
        }
    }

    // Merge two halves of a container of integers
    template <typename Container>
    void merge(Container& container, int start, int mid, int end) {
        int i, j, k;
        int n1 = mid - start + 1;
        int n2 = end - mid;

        Container left(n1);
        Container right(n2);

        for (i = 0; i < n1; ++i)
            left[i] = container[start + i];
        for (j = 0; j < n2; ++j)
            right[j] = container[mid + 1 + j];

        i = 0;
        j = 0;
        k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j])
                container[k++] = left[i++];
            else
                container[k++] = right[j++];
        }
        while (i < n1)
            container[k++] = left[i++];

        while (j < n2)
            container[k++] = right[j++];
    }
};

#endif
