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
