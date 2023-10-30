#include "../inc/whatever.hpp"

// this class is meant to illustrate how swap, min, and max 
// template functions can work with user-defined types:
// -------- evaluation sheet --------------
class Awesome {
  public:
	// default constructor
    Awesome(void) : _n(0) {}
	// param. constructor
    Awesome( int n ) : _n( n ) {}
	// ass.operator overload
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	// ---------------------------------------------------------------------------
	// Equality and OTHER operator overloading
	// compare _n member variable of the current obj to _n of another Awesome obj,
	// returns a boolean value.
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	// ---------------------------------------------------------------------------
	// getter
    int get_n() const { return _n; }
  private:
    int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }
// -------- evaluation sheet end --------------

int main(void) {
		std::cout << std::endl;
		{
		std::cout << "-------- tests from subject pdf -------" << std::endl;

		int	a = 3;
		int	b = 2;
        std::cout << "Input: a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "Swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
        std::cout << "\nInput: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "Swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		std::cout << std::endl;
	}

	{	// -------- evaluation sheet --------------
		std::cout << "-------- tests from eval sheet -------" << std::endl;
		Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
		
		std::cout << std::endl;
		// -------- evaluation sheet  end --------------
	}
	return 0;
}

