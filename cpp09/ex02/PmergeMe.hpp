#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>
#include <iomanip>

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
        void printDataBefore() const;
        void printDataVector() const;
        void printDataList() const;
        bool isSortedVector() const;
        bool isSortedList() const;
    private:
        Vector m_dataBefore;
        Vector m_dataVector;
        List   m_dataList;
};

void        mergeSort(Vector &data, const int begin, const int end);
void        mergeSort(List &data, const int begin, const int end);
long double	get_current_time(void);

template <typename Container>
void printData(const Container &c) {

    for (std::pair<typename Container::const_iterator, typename Container::const_iterator> it(c.begin(), c.end());
        it.first != it.second; ++it.first)
    {
        std::cout << *it.first << " ";
    }
    std::cout << std::endl;
};

template <typename Container>
void insertionSort(Container &data) {
    typedef std::pair< typename Container::iterator, typename Container::iterator> cIt;
    const int vecSize = data.size();
    if (vecSize <= 1) {
        return ;
    }
    typename Container::iterator begin(data.begin());
    for (cIt it(begin, data.end()); it.first != it.second; ++it.first) {
        for (cIt key(it.first, it.first); key.first != begin && *key.first < *(--key.second); --key.first) {
            std::swap(*key.first, *key.second);
        }
    }
}

template <typename Container>
bool isSortedContainer(Container c) {
    typename Container::iterator begin = c.begin();
    typename Container::iterator next = c.begin();
    typename Container::iterator end = c.end();
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