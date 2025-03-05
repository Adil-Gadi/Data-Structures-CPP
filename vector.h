//
// Created by Adil Gadi on 2/27/25.
//

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
public:
    Vector();

    virtual ~Vector();

    explicit Vector(size_t size);

    void push(T item);

    T* get(int index) const;

    T* get_safely(int index) const;

    Vector& operator[](int index);

private:
    T* ptr = nullptr;
    int len;
    int size = 0;

    void resize(size_t size);

};

#include "vector.tpp"
#endif //VECTOR_H
