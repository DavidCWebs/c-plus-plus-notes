
Explicit Conversion Constructor
===============================
Prepending the keyword `explicit` to a constructor declaration (i.e. adding the `explicit` function specifier to the constructor within the class declaration) prevents unwanted type conversions.

Without the `explicit` function specifier, a constructor is a [converting constructor][2] - the type can be initialised by assigning a variable of the appropriate type. Prior to C++11, the constructor needed to be called with a single non-default parameter. For example:

```c++
class A
{
	A(int) {}		// Converting constructor
	A(int, double) {}	// Converting constructor
};

class B
{
	explicit B(int) {}
	explicit B(int, double) {}
}

void main()
{
	// Converting constructors
	// -----------------------
	A x = 42;		// Copy initialisation
	A x1 = {42, 3.14};	// Copy list initialisation
	A x2(42);		// Direct initialisation
	A x3{42, 3.14};		// Direct list initialisation

	// Explicit conversion constructors
	// --------------------------------
	B y = 42;		// NOT ALLOWED: Error
	B y1 = {42, 3.14};	// NOT ALLOWED: Error
	B y2(42);		// Direct initalisation OK
	B y3{42, 3.14};		// Direct list initialisation OK
	B y4 = (B)1		// OK - exlicit cast does a static cast, direct initialisation
}
```

Note that prior to C++11, converting constructors needed to have a single non-default parameter.

References
----------
* [Explicit conversion constructors][1]: IBM Knowledge Centre
* [Converting constructors][2]

[1]: https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/explicit_keyword.htm
[2]: https://en.cppreference.com/w/cpp/language/converting_constructor
