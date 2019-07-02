Const Declared Functions
========================

Declare functions/member functions as const unless you can't - or in other words, unless they specifically serve to change member variables.

If the member function does not change a member variable, declare it `const`:

```cpp

...

private:
	int m_number;
public:
	int GetNumber() const {
		return m_number;
	}
```

This causes the compiler to error if you try to change a member variable within the function.

TL;DR;
-----
Getters: declare `const`. Setters: not.
