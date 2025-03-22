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
    x.shift(8);
    x.pop();

    if (x.getHeadItem() == nullptr) {
        LOG("undefined head");
    }

   if (x.getTail() == nullptr) {
        LOG("undefined tail");
    }

    LOG("head " << x.getHeadItem());
    LOG("tail " << x.getTail());

    return 0;
}
