//
// Created by Adil Gadi on 2/27/25.
//
#include <iostream>

constexpr static size_t INIT_LEN = 2;

template<typename T>
void Vector<T>::resize(const size_t new_len) {

    T* temp = (T*)realloc(this->ptr, new_len * sizeof(T));
    if (temp == nullptr) {
        std::cout << "Error" << std::endl;
        throw 'Error';
    }
    this->ptr = temp;
    this->len = new_len;
}

template<typename T>
Vector<T>::Vector() {
    this->ptr = (T*)malloc(sizeof(T) * INIT_LEN);
    this->len = INIT_LEN;
    this->size = 0;
}

template<typename T>
void Vector<T>::set(int index, T item) {
    this->ptr[index] = item;
}

template<typename T>
void Vector<T>::set_safely(int index, T item) {
    if (index >= this->len)
        return;
    this->ptr[index] = item;
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
        this->len *= 2;
        this->resize(this->len);
    }

    this->ptr[this->size] = item;
    // std::cout << this->ptr[this->size] << std::endl;
    size++;
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

    return this->get(index);
}

template<typename T>
size_t Vector<T>::length() const {
    return this->len;
}

template<typename T>
T Vector<T>::get_as_copy(int index) const {
    return *(this->get(index));
}

template<typename T>
int Vector<T>::get_size() const {
    return this->size;
}

template<typename T>
void Vector<T>::pop() {
    if (this->size < 1) {
        return;
    }

    --this->size;
}
