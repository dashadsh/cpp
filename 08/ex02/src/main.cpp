// #include "../inc/MutantStack.hpp"
#include "../inc/MutantStack.tpp"

int main() {

std::cout << "\n===================================" << std::endl;
std::cout << "Testing MutantStack" << std::endl;

MutantStack<int> mstack;

	// Pushing elements onto MutantStack
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3); 
mstack.push(5); 
mstack.push(737); //[...] 
mstack.push(0);

	// Iterating through MutantStack
MutantStack<int>::iterator it = mstack.begin(); 
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite) {
    std::cout << "Element:	" << *it << std::endl;
	++it; 
}

std::stack<int> s(mstack); 

std::cout << "\n===================================" << std::endl;
std::cout << "Testing std::list" << std::endl;
std::list<int> l;

    // Pushing elements onto std::list
l.push_back(5);
l.push_back(17);
std::cout << "Top of std::list: " << l.back() << std::endl;
l.pop_back(); // std::list does not have pop(), so use pop_back()
std::cout << "Size of std::list: " << l.size() << std::endl;
l.push_back(3);
l.push_back(5);
l.push_back(737);
// [...] 
l.push_back(0);

    // Iterating through std::list
std::list<int>::iterator lit = l.begin();
std::list<int>::iterator lite = l.end();
++lit;
--lit;
while (lit != lite) {
    std::cout << "Element: " << *lit << std::endl;
    ++lit;
}
std::cout << "\n===================================" << std::endl;

std::cout << "Testing std::vector" << std::endl;
std::vector<int> v;

    // Pushing elements onto std::vector
v.push_back(5);
v.push_back(17);
std::cout << "Top of std::vector: " << v.back() << std::endl;
v.pop_back();
std::cout << "Size of std::vector: " << v.size() << std::endl;
v.push_back(3);
v.push_back(5);
v.push_back(737);
// [...] 
v.push_back(0);

    // Iterating through std::vector
std::vector<int>::iterator vit = v.begin();
std::vector<int>::iterator vite = v.end();
++vit;
--vit;
while (vit != vite) {
    std::cout << "Element: " << *vit << std::endl;
    ++vit;
}

return 0;
}
