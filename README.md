# Ellen
Ellen is a simple library for C++ with some simple PRNG (Pseudo Random Number Generator) functions

It uses the simple xorshift64 algorithm and it has 3 functions.

Simple library only for studying RNGs and exploration.

The initial Seed mixes the current time in milliseconds with the PID of the program and mixes it with hexadecimal values from the computer such as 0xdeadbeef and 0xCAFEBEBE

# Example Usage

```cpp
#include "ellen.hpp"
#include <iostream>
using namespace std;

int main() {
    Ellen ellen; // Init ellen and init the initial state of default seed.

    ellen.seed(1234); // Function to define seed to generate numbers.

    int choice = ellen.choice(); // Function to choose between 0 or 1.
    cout << choice << endl;

    int random = ellen.rand(); // Pseudo-random function to generate numbers.
    cout << random << endl;
    
    return 0;
}
```
