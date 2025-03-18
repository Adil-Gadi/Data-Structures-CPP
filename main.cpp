#include <print>
#include <iostream>

#include "stack.h"
#include "string.h"
#include "vector.h"

#define LOG(x) std::cout << x << std::endl

int main() {

    Vector<int> x = Vector<int>();

    for (int i = 1; i < 20; i++) {
        x.push(i);
    }

    for (int i = 0; i < x.get_size(); i++) {
        std::println("Index {}, Item {}", i, x.get_ptr()[i]);
    }

    std::println("Size: {}", x.get_size());
    std::println("Len: {}", x.length());

    return 0;
}
