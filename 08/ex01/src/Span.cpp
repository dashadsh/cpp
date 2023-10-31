#include "../inc/Span.hpp"

Span::Span() : _N(0) {	
	std::cout << "span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	std::cout << "span param. constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "span sestructor called" << std::endl;
}

Span::Span(Span const &src) {
	std::cout << "span copy constructor called" << std::endl;
	*this = src;
}

Span & Span::operator=(Span const &src) {
	std::cout << "span ass. operator called" << std::endl;
	this->_N = src._N;
	this->_vec = src._vec;
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
    std::vector<int> sorted(_vec.size());
    std::copy(_vec.begin(), _vec.end(), sorted.begin()); 
    std::sort(sorted.begin(), sorted.end());
    int spanMin = INT_MAX;
    for(std::vector<int>::iterator i = sorted.begin(); i != sorted.end(); i++) {
        if (i + 1 != sorted.end() && *(i + 1) - *i < spanMin)
            spanMin = *(i + 1) - *i;
    }
    return(spanMin);
}

int Span::longestSpan() {
    if (_vec.size() <= 1)
        throw NoSpanException();
    int minVal = *std::min_element(_vec.begin(), _vec.end());
    int maxVal = *std::max_element(_vec.begin(), _vec.end());
    return (maxVal - minVal);
}

void Span::fillConsecutiveNumbers() {
    for(int unsigned i = 0; i < _N; i++)
            _vec.push_back(i);
}

void Span::fillRandomNumbers() {
    srand(time(NULL));
    for(int unsigned i = 0; i < _N; i++)
            _vec.push_back(rand());
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    for (std::vector<int>::const_iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
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
