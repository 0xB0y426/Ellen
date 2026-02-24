#ifndef ELLEN_HPP
#define ELLEN_HPP

#include <iostream>
#include <cstdint>
#include <unistd.h>
#include <chrono>
#include <thread>

static uint64_t xorshift64(uint64_t x) {
    x ^= x << 13;
    x ^= x >> 7; 
    x ^= x << 17;
    return x;
}

class Ellen {
    private:
        uint64_t state;
    public:
        uint64_t choice() {
            return this->rand() % 2;
        }

        Ellen() {
            state = std::chrono::high_resolution_clock::now().time_since_epoch().count() ^ getpid() ^ 0xdeadbeef ^ 0xCAFEBEBE;
        }

        void seed(uint64_t s) {
            state = s;
            if (s == 0) {
                state = 0xdeadbeef;
            }
        }

        uint64_t rand() {
            state = xorshift64(state); 
            return state;
        }
    }; 

#endif