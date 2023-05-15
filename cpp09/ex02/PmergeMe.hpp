#pragma once
#include <iostream>
#include <vector>
#include <list>

typedef std::vector<int> Vector;
typedef std::list<int> List;
typedef std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> pairVectorIt;
typedef std::pair<std::list<int>::iterator, std::list<int>::iterator> pairListIt;

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(Vector data);
        PmergeMe(List data);
        PmergeMe(const PmergeMe &rhs);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);
        void fillContainer(Vector data);
        void fillContainer(List data);
        void fillContainer(int N);
        void sortVector();
        void sortList();
        void printDataVector() const;
        void printDataList() const;
        bool isSortedVector() const;
        bool isSortedList() const;
    private:
        Vector m_dataVector;
        List   m_dataList;
};

void insertionSort(Vector &data);
void insertionSort(List &data);
void mergeSort(Vector &data, const int begin, const int end);
void mergeSort(List &data, const int begin, const int end);

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