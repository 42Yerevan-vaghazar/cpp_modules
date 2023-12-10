#pragma once
#include <iostream>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        ~Array();
        Array &operator=(const Array &obj);
        T &operator[](const size_t index);
        const T &operator[](const size_t index) const;
        size_t size() const;
    private:
        size_t m_size;
        T *m_elems;
};

template <typename T>
Array<T>::Array() {
    m_elems = NULL;
    m_size = 0;
};

template <typename T>
Array<T>::Array(unsigned int n) {
    m_elems = new T[n + 1];
    m_size = n;
};

template <typename T>
Array<T>::Array(const Array &obj) {
    m_size = obj.m_size;
    m_elems = new T[m_size + 1];
    for (size_t i = 0; i < m_size; i++) {
        m_elems[i] = obj.m_elems[i];
    }
};

template <typename T>
Array<T>::~Array() {
    delete [] m_elems;
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj) {
    if (this != &obj) {
        delete [] m_elems;
        m_size = obj.m_size;
        m_elems = new T[m_size + 1];
        for (size_t i = 0; i < m_size; i++) {
            m_elems[i] = obj.m_elems[i];
        }
    }
    return (*this);
};

template <typename T>
T &Array<T>::operator[](const size_t index) {
    if (index > m_size - 1 || m_elems == NULL) {
        throw std::range_error("out of range");
    }
    return (m_elems[index]);
};

template <typename T>
const T &Array<T>::operator[](const size_t index) const {
    if (index < 0 || index > m_size - 1 || m_elems == NULL) {
        throw std::range_error("out of range");
    }
    return (m_elems[index]);
};

template <typename T>
size_t Array<T>::size() const {
    return (m_size);
};