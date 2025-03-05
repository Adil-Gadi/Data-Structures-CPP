#include <print>

#include "stack.h"
#include "string.h"
#include "vector.h"

int main() {

    Stack<int>* x = new Stack<int>();

    x->stack(5);
    x->stack(5);
    x->stack(5);
    x->stack(5);
    x->stack(5);

    delete x;

    x->stack(5);

    return 0;
}
