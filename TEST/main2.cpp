#include <iostream>
//#include <iomanip>

int main()
{
	float annualSalary;
	std::cout << "enter your annual salary ";
	std::cin >> annualSalary;
	float monthlySalary = annualSalary / 12;
	// std::cout << std::fixed << std::setprecision(2); // optional
	std::cout << "monthly salary is " << monthlySalary << std::endl;
}

// c++ main2.cpp