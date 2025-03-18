//
// Created by Adil Gadi on 2/27/25.
//

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
public:
    Vector();

    virtual ~Vector() {
        free(ptr);
    }

    explicit Vector(size_t len);

    void push(T item);

    T* get(int index) const;

    T get_as_copy(int index) const;

    T* get_safely(int index) const;

    void set(int index, T item);

    void set_safely(int index, T item);

    [[nodiscard]] size_t length() const;

    [[nodiscard]] int get_size() const;

    T *get_ptr() const {
        return this->ptr;
    }

    // Vector<T>& operator[](int index);

private:
    T* ptr = nullptr;
    size_t len;
    int size = 0;

    void resize(size_t new_len);

};

#include "vector.tpp"
#endif //VECTOR_H
