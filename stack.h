//
// Created by Adil Gadi on 2/27/25.
//

#ifndef STACK_H
#define STACK_H

template <typename T>
struct StackItem {
    StackItem<T>* below = nullptr;
    T data;
};

template <typename T>
class Stack {
public:
    Stack() = default;

    const StackItem<T>* get_top();

    StackItem<T>* stack(T data);

    StackItem<T>* pop();

    void pop_and_free();

    StackItem<T>* swap(T data);

    void swap_and_free(T data);

    virtual ~Stack();
private:
    StackItem<T>* top = nullptr;

    static void freeStackItem(StackItem<T>* item);
};

#include "stack.tpp"

#endif //STACK_H
