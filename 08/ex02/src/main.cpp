// #include "../inc/MutantStack.hpp"
#include "../inc/MutantStack.tpp"

int main() {

	std::cout << "\n===================================" << std::endl;
	std::cout << "\n------- Testing MutantStack -------\n" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "\nTop element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); 
	//[...] 
	mstack.push(0);

	std::cout << "\nTesting iterator (begin and end)" << std::endl;
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "Iterating through MutantStack:" << std::endl;
	while (it != ite) {
    	std::cout << "Element: " << *it << std::endl;
		++it; // 5 -> 3 (17 was popped) -> 5 -> 737 -> 0
	}

	std::cout << "\nTesting reverse iterator (rbegin and rend)" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;

	std::cout << "Iterating through MutantStack in reverse:" << std::endl;
	while (rit != rite) {
    	std::cout << "Element: " << *rit << std::endl;
   		++rit;
	}

	// std::stack<int> s(mstack); 
    std::cout << "\nTesting copyConstructor:" << std::endl;
    MutantStack<int> copyConstructor(mstack); // copy constructor

    // addresses of original container elements
    std::cout << "Original container addresses:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << &(*it) << std::endl;
    }

    // addresses of copied container elements
    std::cout << "Deep copy using copy constructor addresses:" << std::endl;
    for (MutantStack<int>::iterator deepIt = copyConstructor.begin(); deepIt != copyConstructor.end(); ++deepIt) {
        std::cout << &(*deepIt) << std::endl;
    }

    std::cout << "\nTesting assignmentOperator:" << std::endl;
	MutantStack<int> assignmentOperator;
    assignmentOperator = mstack; // assignment operator
	// print addresses of copied container elements
    std::cout << "Deep copy using assignment operator addresses:" << std::endl;
    for (MutantStack<int>::iterator deepIt = assignmentOperator.begin(); deepIt != assignmentOperator.end(); ++deepIt) {
        std::cout << &(*deepIt) << std::endl;
    }

	mstack.push(42);
	copyConstructor.push(4242);
	assignmentOperator.push(424242);

	std::cout << "\nChanges made to the original MutantStack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << "Element: " << *it << std::endl;
    }

    // Check that the copied MutantStacks are not affected by the changes
    std::cout << "\nValues in the copied MutantStack using copy constructor:" << std::endl;
    for (MutantStack<int>::iterator copyIt = copyConstructor.begin(); copyIt != copyConstructor.end(); ++copyIt) {
        std::cout << "Element: " << *copyIt << std::endl;
    }

    std::cout << "\nValues in the copied MutantStack using assignment operator:" << std::endl;
    for (MutantStack<int>::iterator assignIt = assignmentOperator.begin(); assignIt != assignmentOperator.end(); ++assignIt) {
        std::cout << "Element: " << *assignIt << std::endl;
    }


	std::cout << "\n===================================" << std::endl;
	std::cout << "\n-------- Testing std::list --------\n" << std::endl;
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);
	std::cout << "Top of std::list: " << l.back() << std::endl; // std::list has back() and front() member functions
	l.pop_back(); // std::list has pop_back() and pop_front() member functions
	std::cout << "Size of std::list: " << l.size() << std::endl;
	std::cout << "Top element: " << l.back() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	// [...] 
	l.push_back(0);

	std::cout << "\nTesting iterator (begin and end)" << std::endl;
	std::list<int>::iterator lit = l.begin();
	std::list<int>::iterator lite = l.end();
	++lit;
	--lit;
	std::cout << "Iterating through std::list:" << std::endl;
	while (lit != lite) {
	    std::cout << "Element: " << *lit << std::endl;
	    ++lit;
	}

	std::cout << "\nTesting reverse iterator (rbegin and rend)" << std::endl;
	std::list<int>::reverse_iterator rlit = l.rbegin();
	std::list<int>::reverse_iterator rlite = l.rend();
	++rlit;
	--rlit;
	std::cout << "Iterating through std::list in reverse order:" << std::endl;
	while (rlit != rlite) {
    	std::cout << "Element (in reverse): " << *rlit << std::endl;
    	++rlit;
	}

	std::cout << "\n===================================" << std::endl;
	std::cout << "\n------- Testing std::vector -------\n" << std::endl;

	std::vector<int> v;

	v.push_back(5);
	v.push_back(17);
	std::cout << "Top of std::vector: " << v.back() << std::endl;
	v.pop_back();
	std::cout << "Size of std::vector: " << v.size() << std::endl;
	std::cout << "Top element: " << v.back() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	// [...] 
	v.push_back(0);

	std::cout << "\nTesting iterator (begin and end)" << std::endl;
	std::vector<int>::iterator vit = v.begin();
	std::vector<int>::iterator vite = v.end();
	++vit;
	--vit;
	std::cout << "Iterating through std::vector:" << std::endl;
	while (vit != vite) {
	    std::cout << "Element: " << *vit << std::endl;
	    ++vit;
	}

	std::cout << "\nTesting reverse iterator (rbegin and rend)" << std::endl;
	std::vector<int>::reverse_iterator rvit = v.rbegin();
	std::vector<int>::reverse_iterator rvite = v.rend();
	++rvit;
	--rvit;
	std::cout << "Iterating through std::vector in reverse order:" << std::endl;
	while (rvit != rvite) {
    	std::cout << "Element (in reverse): " << *rvit << std::endl;
    	++rvit;
	}
	
	std::cout << std::endl;
	return 0;
}
