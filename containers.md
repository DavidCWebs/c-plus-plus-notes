Notes on C++ Containers
=======================

Template Defined
----------------
Define a template for a container of a given size:

```c++
// `std::array` container for `Size` bytes                                                                    
template<size_t Size>                                                                                         
using byte_array = std::array<uint8_t, Size>;
```

Usage: in the code below, `b` is an array of uint8_t, with space for 5 elements:

```c++
byte_array<5> b;
```
Typedef Convenience
-------------------
```c++
// Set a container size - known at compile time
static constexpr size_t hash_size = 32;

// typedef a `std::array` holding `hash_size` (i.e. 32) bytes
typedef byte_array<hash_size> hash_digest;

// Usage:
byte_array b; // same as std::array<uint8_t, 32> b;

// `std::vector` for variable length bytes container
typedef std::vector<uint8_t> Bytes; 

```
