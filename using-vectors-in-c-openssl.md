Using C++ Vectors in C Functions
================================

You can use C utilities in C++ code. For example, you may be using openssl to perform hashing algorithms.

In this case, the openssl code is C rather than C++. It can't operate on vectors of bytes - instead it uses basic C style data structures like `const void *` - an array of void pointers.

Example: `SHA256_update()`
--------------------------
The `SHA256_update()` function is part of the openssl library. The signature of this function is: `int SHA256_Update(SHA256_CTX *c, const void *preimageBytes, size_t len);`.

It serves to fill the bytes of `c` with the hash of `preimageBytes`.  

Note that 2nd parameter is a `const void *`. This means that the caller must provide a pointer to data rather than a `std::vector` or a vector iterator.

The caller can either pass `v.data()` or a pointer to the first element in the vector: `&v[0]`.

Code Example
------------
```c++
// main.cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/ripemd.h>

#define HASH_LEN 32

int sha256(const uint8_t preimageBytes[], size_t len, std::vector<uint8_t>& res)
{
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, preimageBytes, len); 
	int ret = SHA256_Final(res.data(), &sha256);
	return ret;
}

int main()
{
	std::vector<uint8_t> preimageBytes{0xde, 0xad, 0xbe, 0xef};
	std::vector<uint8_t> hash(HASH_LEN);
	sha256(preimageBytes.data(), preimageBytes.size(), hash);
	
	for (auto& el : hash)
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)el;
	std::cout << '\n';

	return 0;
}
```

To compile:
```bash
g++ -W -Wall -std=c++17 -g -o prog main.cpp -lssl -lcrypto
```
