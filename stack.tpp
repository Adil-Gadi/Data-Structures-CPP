//
// Created by Adil Gadi on 2/27/25.
//

template<typename T>
StackItem<T>* Stack<T>::stack(T data) {
    StackItem<T>* item = (StackItem<T>*)malloc(sizeof(StackItem<T>));;
    item->data = data;
    if (this->top != nullptr) {
        item->below = this->top;
    }

    this->top = item;
    return this->top;
}

template<typename T>
const StackItem<T> *Stack<T>::get_top() {
    return this->top;
}

template<typename T>
StackItem<T> *Stack<T>::pop() {
    StackItem<T>* poppedItem = this->top;
    if (poppedItem == nullptr)
        return nullptr;
    this->top = this->top->below;
    poppedItem->below = nullptr;
    return poppedItem;
}

template<typename T>
void Stack<T>::pop_and_free() {
    StackItem<T>* poppedItem = this->pop();

    if (poppedItem == nullptr)
        return;

    free(poppedItem);
    poppedItem = nullptr;
}

template<typename T>
StackItem<T> *Stack<T>::swap(T data) {
     StackItem<T>* prev = this->top;
     this->pop();
    StackItem<T>* item = (StackItem<T>*)malloc(sizeof(StackItem<T>));
    item->data = data;
    item->below = nullptr;
    if (this->top != nullptr) {
        item->below = this->top;
    }

    this->top = item;

    return prev;
}

template<typename T>
void Stack<T>::swap_and_free(T data) {
     StackItem<T>* prev = this->top;
     this->pop();
    StackItem<T>* item = (StackItem<T>*)malloc(sizeof(StackItem<T>));
    item->data = data;
    if (this->top != nullptr) {
        item->below = this->top;
    }

    this->top = item;

    if (prev == nullptr)
        return;
    free(prev);
}

template<typename T>
Stack<T>::~Stack() {
    freeStackItem(this->top);
}

template<typename T>
void Stack<T>::freeStackItem(StackItem<T> * item) {
    if (item->below != nullptr) {
        freeStackItem(item->below);
    }

    free(item);
}
