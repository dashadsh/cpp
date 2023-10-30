#include "../inc/iter.hpp"
// #include <functional>

// -------- evaluation sheet --------------
class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { // takes constant refr to a value of data type T
	std::cout << x << std::endl; 
	return; 
}
// -------- evaluation sheet  end --------------

int main(void)
{
	{
		std::cout << std::endl;
		std::cout << "------ Custom Test 1 -------" << std::endl;
		std::cout << std::endl;
		int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
		std::cout << "elements of array:" << std::endl;
		for (int i = 0; i < 8; i++)
			std::cout << array[i] << "  ";
		std::cout << std::endl << std::endl;

		std::cout << "output of func. template iter:" << std::endl;
		iter(array, 8, myPrint);
		std::cout << std::endl;
	}  

	{
		std::cout << "------ Custom Test 2 ------" << std::endl;
    	const char *strings[] = {
        "Hello",
        "World",
        "C++",
        "Coding"
    	};

    	std::cout << "\nUsing iter function template with strings:" << std::endl;
    	iter(strings, 4, myPrint);
		std::cout << std::endl;
	}

    {
		std::cout <<  "------ Eval Sheet Test -------" << std::endl;
		std::cout << std::endl;
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];

		iter(tab, 5, print<int>);
		std::cout << std::endl;

		iter(tab2, 5, print<Awesome>);
		std::cout << std::endl;
	}
}

