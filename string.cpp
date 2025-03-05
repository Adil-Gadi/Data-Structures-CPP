//
// Created by Adil Gadi on 2/27/25.
//

#include "string.h"

#include <print>

#include "cstdlib"
#include "cstring"

String::String(const char *init) {
    size_t len = strlen(init);
    this->buffer = (char *) malloc(len + 1);
    strcpy(this->buffer, init);
    this->buffer[len] = 0;
    this->len = len;
}

String::String(size_t reserve) {
    this->amountReserved = reserve + 1;
    this->hasReserved = true;
    size_t len = reserve;
    this->buffer = (char *) malloc(len + 1);
    this->buffer[len] = 0;
    this->len = len;
}

char *String::get_ptr() const {
    return this->buffer;
}

const char * String::get_const_ptr() const {
    return this->buffer;
}

void String::set(const char *ptr) {
    const size_t len = strlen(ptr);

    std::println("{}", this->hasReserved);
    if (this->hasReserved != true) {
        free(this->buffer);
        this->buffer = (char *) malloc(len + 1);
    }
    strcpy(this->buffer, ptr);
    this->buffer[len] = 0;
    this->len = len;
}

String::~String() {
    if (this->buffer == nullptr)
        return;
    free(this->buffer);
    this->buffer = nullptr;
    this->len = 0;
}

String::String(const String &other) {
    const size_t len = other.length();
    this->buffer = (char *) malloc(len + 1);
    strcpy(this->buffer, other.get_ptr());
    this->buffer[len] = 0;
    this->len = len;
}

size_t String::length() const {
    return this->len;
}

String &String::operator=(const char *ptr) {
    this->set(ptr);
    return *this;
}

String &String::operator=(const String &other) {
    this->set(other.get_ptr());
    return *this;
}

void String::concat(const char *ptr) {
    this->buffer = (char *) realloc(this->buffer, this->len + strlen(ptr) + 1);
    strcat(this->buffer, ptr);
}

void String::concat(const String &other) {
    this->buffer = (char *) realloc(this->buffer, this->len + other.length() + 1);
    strcat(this->buffer, other.get_ptr());
}

String &String::operator+=(const char *ptr) {
    this->concat(ptr);
    return *this;
}

String &String::operator+=(const String &other) {
    this->concat(other);
    return *this;
}

size_t String::get_amount_reserved() const {
    return this->amountReserved;
}

bool String::has_reserved_amount() const {
    return this->hasReserved;
}
