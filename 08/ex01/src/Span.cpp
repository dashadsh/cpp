#include "../inc/Span.hpp"

Span::Span() : _N(0) {	
	std::cout << "span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	std::cout << "span param. constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "span destructor called" << std::endl;
}

Span::Span(Span const &src) : _N(src._N) {
	std::cout << "span copy constructor called" << std::endl;
	this->_vec.clear();
    this->_vec.insert(_vec.begin(), src._vec.begin(), src._vec.end());
}

Span & Span::operator=(Span const &src) {
	std::cout << "span ass. operator called" << std::endl;
	if (this != & src) {
		this->_N = src._N;
		// this->_vec = src._vec; - shallow copy
		this->_vec.clear(); // deep copy
		this->_vec.insert(this->_vec.begin(), src._vec.begin(), src._vec.end());
	}
	return (*this);
}

void Span::addNumber(int number) {
    if(_vec.size() >= _N)
        throw MaxSizeException();
    _vec.push_back(number);
}

int Span::shortestSpan() {
    if (_vec.size() <= 1)
        throw NoSpanException();
    std::vector<int> sorted(_vec.size()); // create new vector 'sorted'
    std::copy(_vec.begin(), _vec.end(), sorted.begin()); // copying all elem from '_vec' to 'sorted'
    std::sort(sorted.begin(), sorted.end()); // sort 'sorted'
    int spanMin = INT_MAX; // to keep track of the smallest span found
    for(std::vector<int>::iterator i = sorted.begin(); i != sorted.end(); i++) {
        if (i + 1 != sorted.end() // while we are not at the end of 'sorted' &
		&& *(i + 1) - *i < spanMin) // diff. between curr.elem. and next elem is less than spanMin,
            spanMin = *(i + 1) - *i;  // update spanMin!
    }
    return(spanMin);
}

// for C++11 we could use more effective:
// auto [minIt, maxIt] = std::minmax_element(_vec.begin(), _vec.end());
// int minVal = *minIt;
// int maxVal = *maxIt;
// SIC - auto is C++11 feature - automatic keyword
int Span::longestSpan() {
    if (_vec.size() <= 1)
        throw NoSpanException();
	// take 2 iterators  - the range is defined by _vec.begin() and _vec.end(),
	// result is an iterator whih we can dereference to get the value
    int minVal = *std::min_element(_vec.begin(), _vec.end());
    int maxVal = *std::max_element(_vec.begin(), _vec.end());
    return (maxVal - minVal);
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    for (std::vector<int>::const_iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

// void Span::fillConsecutiveNumbers() {
//     for(int unsigned i = 0; i < _N; i++)
//             _vec.push_back(i);
// }

// void Span::fillRandomNumbers() {
//     srand(time(NULL));
//     for(int unsigned i = 0; i < _N; i++)
//             _vec.push_back(rand());
// }

// less efficien than the function above,
// but it's just for STL practice.
// avoids unnecessary memory allocation and copying
void Span::fillConsecutiveNumbers() {
    std::vector<int> consecutiveNumbers(_N);
    for (unsigned int i = 0; i < _N; i++) {
        consecutiveNumbers[i] = i;
    }
    addRange(consecutiveNumbers.begin(), consecutiveNumbers.end());
}

// less efficien than the function above,
// but it's just for STL practice
// avoids unnecessary memory allocation and copying
void Span::fillRandomNumbers() {
    std::vector<int> randomNumbers(_N);
	// srand() is used seed the random number generator rand()
    srand(time(NULL));
    for (unsigned int i = 0; i < _N; i++) {
		// rand() is called multiple times to generate pseudo-random numbers 
		// that are stored in the randomNumbers 
        randomNumbers[i] = rand();
    }
    addRange(randomNumbers.begin(), randomNumbers.end());
}

void    Span::printElements() {
	int idx = 0;
    for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << "ELEMENT " << idx << "	" << *it << std::endl;
		idx++;
	}
}

const char *Span::MaxSizeException::what() const throw() {
    return(">>>>> exception: max size reached <<<<<");
}

const char *Span::NoSpanException::what() const throw() {
    return(">>>>> exception: no span <<<<<");
}
