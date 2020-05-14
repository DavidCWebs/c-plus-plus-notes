# Access Specifiers
By default, all members of a class are `private` - this means that they can only be accessed by other members of the class.

In contrast, `public` members can be accessed from outside the struct or class.

Note that in C++ Structs are basically the same as Classes, except members are `public` by default.

The `public` or `private` keyword followed by a colon is an __access specifier__.

Access Control is Per-Class Not Per-Object
------------------------------------------
A member function has access to private members of the __class__ - which means it can access the private members of __any__ object of the class that it can see.

If a member function receives an object of the same class, it has access to the member variables of that object.

Example:

```c++
#include <iostream>

class Thing
{
private:
	const char* name;
public:
	Thing(const char* inName) : name(inName) {}
	void printName(Thing a) {
		std::cout << "this Thing is " << name
			<< ", the function parameter Thing is "
			<< a.name << '\n';
	}
};

int main()
{
	Thing a("Alice");
	Thing b("Bob");
	a.printName(b);
	b.printName(a);
	return 0;
}
```

Access To Base Fields
---------------------
To access `protected` fields that are defined in the base class from a Derived class you can:

* Define getters and setters in the Derived class
* Access via the Derived class constructor
* Access via the Derived class constructor member initializer list - pass parameters to the Base constructor for initialisation

