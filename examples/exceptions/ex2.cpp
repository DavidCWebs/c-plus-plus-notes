#include <iostream>
#include <typeinfo> // For typeid

class ZeroDivException : public std::exception {
private:
	const char* msg = "Divide by zero error!";
public:
	const char* what() const noexcept {
		return msg;
	}
};

int divide(int a, int b)
{
	if (b == 0)
		throw ZeroDivException();
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
	} catch (const ZeroDivException& e) {
		std::cout << "Exception type: " << typeid(e).name() << '\n';
		std::cout << e.what() << '\n';
	}

	std::cout << "Did we get this far?" << '\n';
	return 0;
}
