#include <print>
#include <iostream>

#include "dequeue.h"
#include "stack.h"
#include "string.h"
#include "vector.h"

#define LOG(x) std::cout << x << std::endl

int main() {

    Dequeue<int> x = Dequeue<int>();

    x.push(12);
    x.push(15);
    x.shift(5);
    x.unshift();
    x.unshift();
    x.unshift();
    x.unshift();
    x.unshift();

    if (x.head == nullptr) {
        LOG("undefined head");
    }

   if (x.tail == nullptr) {
        LOG("undefined tail");
    }

    LOG("head " << x.head);
    LOG("tail " << x.tail);

    return 0;
}
