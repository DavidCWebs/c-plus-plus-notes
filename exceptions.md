Exceptions
==========
In C++, when something "exceptional" happens in a programme, the exception-handling mechanism allows information to be passed information from the point at which the exception (error?) occured to a point at which it can be handled.

If an exception/error occurs in a function, the function can `throw` an exception which terminates the function and passes information back to the (direct or indirect) caller.

The caller can then `catch` the error and handle it appropriately - perhaps in the context of how the function was called.

The Caller
----------
The calling function specifies the kind of exceptions it can handle by defining `catch` clauses in a `try` block:

```c++
int main()
{
	try {
		// If myFunction() is inside a `try` block and can't complete it's task,
		// it can `throw` an exception
		myFunction();
	} catch (const exception& e)
	{
		// 'catch' the exception - handle the problem in the correct context.
		std::cout << "myFunction() couldn't complete it's task." << '\n';
		std::cout << "Report: " << e.what() << '\n';
	}
}
```
Exceptions thrown by functions within the `try catch` block can be caught and handled in context.

The "Thrower"
-------------
If a function can't complete it's task, it can throw an exception back up the call stack

```c++
int myFunction()
{
	...
	if (/* task completed */)
		return result;
	else
		throw myError;		
}
```

Exception Handling is Graceful
------------------------------
Exceptions allow your programme to respond appropriately to exceptional events - rather than simply terminating or blocking execution.

For example, if your programme performs a division on user supplied integers, the exception handling mechanism allows you to handle division by zero errors. Without exception handling, attempting to divide by zero results in programme termination and core dump:

```c++
#include <iostream>

int divide(int a, int b)
{
	return a / b;
}

int main()
{
	// Get user input
	int dividend, divisor;
	std::cout << "Enter dividend: ";
	std::cin >> dividend;
	std::cout << "Enter divisor: ";
	std::cin >> divisor;


	// Run this - no exception handling - if the divisor is
	// zero, programme terminates: "Floating point exception (core dumped)"
	std::cout << divide(dividend, divisor) << '\n';

	// If divisor is zero, we'll never reach this point
	std::cout << "Did we get this far?" << '\n';
	return 0;
}

``` 
The same functionality, with rudimentary exception handling:

```c++
#include <iostream>

int divide(int a, int b)
{
	if (b == 0)
		throw "Division by zero error";
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

	std::cout << "Did we get this far?" << '\n';
	return 0;
}
```
If the divisor is zero, we now get:

```bash
Enter dividend: 6
Enter divisor: 0
Division by zero error
Did we get this far?
```  
See [examples/exceptions/main.cpp][2] for a working example.

Exception Handlers
------------------
The text in the `catch` block is called a _handler_. A single `try` block can have multiple handlers for different exception types. They function a bit like overloaded functions - the handler for the received exception type is the one that will run.

Handling Different Exception Types
----------------------------------
The catch block allows you to specify an exception type - which allows the response to exceptions to be fine-tuned.

An ellipsis in the catch block indicates that the catch block will handle any exception - usually the last catch block, to mop-up any exceptions that have not been handled by specific exception handlers.

References
----------
* [Exception Handling for C++][1] Stroustrop, B & Koenig, A
* [Good Microsoft Documentation][3]

[1]: http://www.stroustrup.com/except89.pdf
[2]: examples/exceptions/main.cpp
[3]: https://docs.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?view=vs-2019
