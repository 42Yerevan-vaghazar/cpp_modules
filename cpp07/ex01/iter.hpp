#pragma once
#include <iostream>

template <typename T>
void iter(const T *arr, size_t len, void (*func)(const T&)) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
};