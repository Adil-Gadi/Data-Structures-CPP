//
// Created by Adil Gadi on 2/27/25.
//

#include <cstdlib>
constexpr static size_t INIT_LEN = 5;

template<typename T>
void Vector<T>::resize(const size_t size) {

    this->ptr = realloc(this->ptr, size);
}

template<typename T>
Vector<T>::Vector() {
    this->ptr = (T*)malloc(sizeof(T) * INIT_LEN);
    this->len = INIT_LEN;
    this->size = 0;
}

template<typename T>
Vector<T>::Vector(size_t len) {
    this->ptr = (T*)malloc(sizeof(T) * len);
    this->len = len;
    this->size = 0;
}

template<typename T>
void Vector<T>::push(T item) {

    if (this->size >= this->len) {
        this->resize(this->len * 2);
    }

    this->ptr[this->size] = item;
    ++this->size;
}

template<typename T>
T *Vector<T>::get(int index) const {
    return ptr + index;
}

template<typename T>
T *Vector<T>::get_safely(int index) const {
    if (index >= this->len) {
        return nullptr;
    }

    return ptr + index;
}
