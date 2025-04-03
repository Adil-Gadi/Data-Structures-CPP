//
// Created by Adil Gadi on 2/27/25.
//

#include <iostream>

#ifndef STRING_H
#define STRING_H

typedef unsigned long size_t;

class String {

public:
    String() = default;

    explicit String(const char* init);

    explicit String(size_t reserve);

    String(const String& other);

    virtual ~String();

    [[nodiscard]] char* get_ptr() const;

    [[nodiscard]] const char* get_const_ptr() const;

    void set(const char* ptr);

    void concat(const char* ptr);

    void concat(const String& other);

    String& operator=(const char* ptr);

    String& operator=(const String& other);

    String& operator+=(const char* ptr);

    String& operator+=(const String& other);

    [[nodiscard]] size_t get_amount_reserved() const;

    [[nodiscard]] bool has_reserved_amount() const;

    [[nodiscard]] size_t length() const;

private:
    char* buffer = nullptr;
    size_t len = 0;
    size_t amountReserved{};
    bool hasReserved = false;

};

#endif //STRING_H
