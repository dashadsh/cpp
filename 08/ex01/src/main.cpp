#include "../inc/Span.hpp"

int main() {

std::cout << "\n========= subject pdf test ==================\n" << std::endl;
  
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

std::cout << "\n========= custom tests =======================" << std::endl;
std::cout << "\n----------- test empty container -------------\n" << std::endl;
	Span empty;
	try {
        empty.addNumber(42);
		// empty.fillRandomNumbers();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	empty.printElements();

std::cout << "\n------ test shortestSpan exception ----------\n" << std::endl;

	Span single(1);
	try {
        single.shortestSpan();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

std::cout << "\n-------- use addRange function ---------------\n" << std::endl;
	Span range = Span(5);

    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(4);
    
	range.addNumber(42); // add single number to 'range'
    // try to add multiple numbers from 'numbers' at once - 1 of them will be not added
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

std::cout << "\n---- use fillConsecutiveNumbers function ----\n" << std::endl;
	Span consecutive(50);
	consecutive.fillConsecutiveNumbers();
	try {
        consecutive.addNumber(42);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	consecutive.printElements();

std::cout << "\n----- use fillRandomNumbers function -------\n" << std::endl;
	
	Span random(50);
	random.fillRandomNumbers();
	try {
        random.addNumber(42);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	random.printElements();

std::cout << "\n----- test 50000 values Span -------\n" << std::endl;
	Span bigSpan(50000);
	bigSpan.fillConsecutiveNumbers();
	// bigSpan.printElements();
	try {
        bigSpan.addNumber(42);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

std::cout << "\n----- test deep copy -------\n" << std::endl;
	Span original(5);
	original.addNumber(1);
	original.addNumber(2);
	original.addNumber(3);

	Span copyConstructor(original);
	Span assignmentOperator = original;

	original.addNumber(4);
	copyConstructor.addNumber(44);
	assignmentOperator.addNumber(444);

	std::cout << std::endl;
	std::cout << "original:	\n";
	original.printElements();
	std::cout << "copy:		\n";
	copyConstructor.printElements();
	std::cout << "assignment:	\n";
	assignmentOperator.printElements();

	std::cout << std::endl;

	return 0;
}
