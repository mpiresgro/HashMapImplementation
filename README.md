# HashMap Implemention

Hash Map (hash table) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.



## Requirements

- CMake
- C++ compiler
- make


## Installation

Build with CMake

```bash
mkdir build
cd build/
cmake .. 
make
# Running GTest TestSuite 
./HashMapTest/HashMapTest
```

## Usage

```C++
#include "hashMap.h"

int main ()
{
    // Create hash map object to hold keys of type int and values of type std::string
    HashMap<int, std::string> hashmap;

    // Add key value
    int key = 123;
    std::string value = "Value";
    hashmap.add(key, &value); 

    // Size returns the number of keys
    int size = hash.size();

    // Keys returns a vector of all keys
    std::vector<int> result = hashMap.keys();
    
    // Values returns a vector of all values
    std::vector<std::string> result = hashMap.values();

    // Get fills the value given a specific key
    // If key exists returns true otherwise returns false
    std::string expected;
    bool get_result = hash.get(value.name, expected);

    // Removes all entries
    hashmap.clear();

    // Remove a single entry by key
    // If key exists returns true otherwise returns false
    bool remove_result = hash.remove(key);

}

```
