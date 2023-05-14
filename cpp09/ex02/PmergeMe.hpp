#pragma once
#include <iostream>
#include <vector>
#include <list>

typedef std::vector<int> Vector;
typedef std::list<int> List;
typedef std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> pairVectorIt;
typedef std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> pairListIt;

class PmergeMe
{
    public:
        PmergeMe();
        template <typename container>
        PmergeMe(container cont) : m_data(cont.begin(), cont.end()) {};
        template <typename InputIterator>
        PmergeMe(InputIterator begin, InputIterator end) : m_data(begin, end) {};
        PmergeMe(const PmergeMe &rhs);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);
        void addNum(int);
        void sortVector();
        void sortList();
        void printData() const;
        bool isSorted();
    private:
        Vector m_data;
        List   m_dataList;
};


Vector sort(Vector data1, Vector data2);
void insertionSort(Vector &data);
void mergeSort(Vector &data, const int begin, const int end);
void printVector(const Vector &data);

template <typename container>
bool isSortedContainer(container c) {
    typename container::iterator begin = c.begin();
    typename container::iterator next = c.begin();
    typename container::iterator end = c.end();
    if (next != end) {
        ++next;
    }
    while (next != end && *begin <= *next) {
        ++begin;
        ++next;
    }
    if (next == end) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
    std::cout << std::endl;
    return (next == end);
}