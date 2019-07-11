User Input with std::cin in C++
===============================

If an input variable is declared, and the value collected by `std::cin` does not match, `std::cin` returns false.

For example:
```c++
int input = 0;

std::cin >> input;

// Entering an integer at this point works.
// Entering a value which is not an integer and not numeric std::cin returns false.
// Entering a real number (with a decimal point): fractional part is discarded and integer is saved.

```
Better to take input within a loop, with some input validation:

```c++

#include <iostream>
#include <typeinfo>
#include <limits>

int main()
{
	int input = 0;
	while (1) {
		std::cout << "Enter an int:\n";
	
		// Enter this block if taking input from cin has failed.
		if (!(std::cin >> input)) {
	
			// The error flag is set on std::cin - future attempts to
			// get input will fail unless the error is cleared.
			std::cin.clear();

			// The failed input is in the input buffer. The default for `ignore` is
			// to skip a single character. To be sure, remove the max streamsize
			// number of chars up until a newline is encountered
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	std::cout << "You entered: " << input << '\n';
	return 0;
}
```
`std::cin` returns false if the input can't match the expected type (in this case, int).

`std::cin.ignore()` extracts and discards unwanted values.

`std::cin.clear()` changes the internal state of the stream - unsets the error flag.

For a working example, see [input.cpp][1] in this repo.

References
----------
* [Entertaining SO Answer][2]

[1]: examples/input.cpp
[2]: https://stackoverflow.com/a/53013577/3590673
