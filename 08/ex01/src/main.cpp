#include "../inc/Span.hpp"

int main() {

std::cout << "\n---------- subject pdf test -------\n" << std::endl;
  
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

std::cout << "\n---------------------\n" << std::endl;
	Span consecutive(100);
	consecutive.fillConsecutiveNumbers();
	try {
        consecutive.addNumber(42);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	// consecutive.printElements();

std::cout << "\n---------------------\n" << std::endl;
	
	Span random(100);
	random.fillRandomNumbers();
	// random.printElements();
	try {
        random.addNumber(42);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

std::cout << "\n---------------------\n" << std::endl;

	Span single(1);
	try {
        single.shortestSpan();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

std::cout << "\n---------------------\n" << std::endl;
	Span empty;
	try {
        empty.addNumber(42);
		// empty.fillRandomNumbers();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	empty.printElements();

std::cout << "\n---------------------\n" << std::endl;
	Span range = Span(5);
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(4);
    
	range.addNumber(42);
    // add multiple numbers at once
	try {
   		range.addRange(numbers.begin(), numbers.end());
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // range.addRange(numbers.begin(), numbers.end());
	range.printElements();
	std::cout << "shortest span:	" << range.shortestSpan() << std::endl;
	std::cout << "longest span:	" << range.longestSpan() << std::endl;
	return 0;
}
