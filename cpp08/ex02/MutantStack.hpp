#pragma once
#include <iostream>
#include <stack>

template <typename T, typename Distance = ptrdiff_t,
  typename Pointer = T*, typename Reference = T&>
class MutantStack : public std::stack<T>
{
    public:
        struct iterator;
        MutantStack() {};
        MutantStack(const MutantStack &obj) : std::stack<T>(obj) {};
        ~MutantStack() {};
        MutantStack &operator=(const MutantStack &obj) {
            this->stack::operator=(obj);
        };
        iterator begin() {
            return (iterator(&this->top()));
        }
        iterator end() {
            T *tmp = &this->top();
            while (tmp)
            {
                tmp = tmp->next;
            }
            return (iterator(tmp));
        }
        struct iterator {
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef std::bidirectional_iterator_tag  iterator_category;

            iterator() {
                m_ptr = NULL;
            };

            iterator(pointer ptr) {
                m_ptr = ptr;
            };

            iterator(const iterator &obj) {
                m_ptr = obj.m_ptr;
            };

            ~iterator() {};
        
            iterator &operator=(const iterator &obj) {
                m_ptr = obj.m_ptr;
                return (*this);
            };

            bool operator==(const iterator &obj) {
                return (this->m_ptr == obj.m_ptr);
            };

            bool operator!=(const iterator &obj) {
                return (this->m_ptr != obj.m_ptr);
            };

            iterator &operator++() {
                ++m_ptr;
                return (*this);
            };

            iterator &operator--() {
                --m_ptr;
                return (*this);
            };

            reference operator*() {
                return (*m_ptr);
            };

            private:
                pointer m_ptr;
        };
        // std::iterator begin() { return vec.begin(); }
        // iterator end() { return vec.end(); }
        // const_iterator begin() const { return vec.begin(); }
        // const_iterator end() const { return vec.end(); }
        // std::iterator iterator;
};