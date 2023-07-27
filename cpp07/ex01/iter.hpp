#pragma once
#include <iostream>

template <typename T, typename Y>
void iter(T *arr, size_t len, void (*func)(Y&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
};

template <typename T>
void iter(T *arr, size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
};