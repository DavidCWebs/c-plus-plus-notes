#include <iostream>

int divide(int a, int b)
{
	if (b == 0)
		throw "Division by zero error";
	return a / b;
}

int noThrowDivide(int a, int b)
{
	return a / b;
}

int main()
{
	int dividend, divisor;
	std::cout << "Enter dividend: ";
	std::cin >> dividend;
	std::cout << "Enter divisor: ";
	std::cin >> divisor;

	try {
		std::cout << divide(dividend, divisor) << '\n';
	} catch (const char* e) {
		std::cout << e << '\n';
	}

	// Run this - no exception handling - if the divisor is
	// zero, programme terminates: "Floating point exception (core dumped)"
	// std::cout << noThrowDivide(dividend, divisor) << '\n';

	std::cout << "Did we get this far?" << '\n';
	return 0;
}
