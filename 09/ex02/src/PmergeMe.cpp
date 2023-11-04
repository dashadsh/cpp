#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) {
	std::cout << "PmergeMe copy constructor called" << std::endl;
	_vec = src._vec;
	_deq = src._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	std::cout << "PmergeMe assignment operator called" << std::endl;
	_vec = src._vec;
	_deq = src._deq;
	return (*this);
}

// fill vector and deque with input
void PmergeMe::parseInput(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		// for each argument, create a stringstream object ss
		std::stringstream ss(av[i]);
		int nb = 0;
		
		// extract integer from ss into nb
		if (!(ss >> nb) // not a valid integer like 'abc'
			|| !ss.eof()) // not at end of stream like '1a', bc 1 will be succesfully extracted!!!
			throw ErrorException();
		if (nb < 0)
			throw ErrorException();
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
}

// func. to print vector and deque
// used before and after sorting
void PmergeMe::printContainer() {
	for(size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << " ";
		if (_vec[i] != _deq[i]) // double check for print after sorting!
			throw ErrorException();
	}
	std::cout << "\n";
}

// usage for sorting a std::vector
// sort vector from start to end idx
void PmergeMe::sortVector() {
    mergeInsertSort(_vec, 0, _vec.size() - 1);
}

// iusage for sorting a std::deque
void PmergeMe::sortDeque() {
    mergeInsertSort(_deq, 0, _deq.size() - 1);
}

const char *PmergeMe::ErrorException::what() const throw() {
    return("Error\n");
}
