#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
// PmergeMe::PmergeMe(const PmergeMe &rhs);
PmergeMe::~PmergeMe() {};
// PmergeMe &PmergeMe::operator=(const PmergeMe &rhs);

void PmergeMe::addNum(int num) {
    m_data.push_back(num);
};

void PmergeMe::sortVector() {
    // insertionSort(m_data);
    mergeSort(m_data, 0, m_data.size());
};

void insertionSort(Vector &data) {
    const int vecSize = data.size();
    if (vecSize <= 1) {
        return ;
    }
    for (int i = 1; i < vecSize; ++i) {
        for (int j = i; j != 0 && data[j] < data[j - 1]; --j) {
            std::swap(data[j], data[j - 1]);
        }
    }
}

void merge(Vector &data, const int begin, const int mid, const int end) {
    Vector data1(data.begin() + begin, data.begin() + mid);
    Vector data2(data.begin() + mid, data.begin() + end);
    size_t i = 0;
    size_t j = 0;
    Vector result;
    while (i < data1.size() && j < data2.size()) {
        if (data1[i] < data2[j]) {
            result.push_back(data1[i++]);
        } else
            result.push_back(data2[j++]);
    }
    while (j < data2.size()) {
        result.push_back(data2[j++]);
    }
    while (i < data1.size()) {
        result.push_back(data1[i++]);
    }
    int index = begin;
    for (pairVectorIt it(result.begin(), result.end());
        it.first != it.second ; ++it.first) {
        data[index++] = *it.first;
    }
};

void mergeSort(Vector &data, const int begin, const int end) {
    if ((end - begin) <= 16) {
        Vector arr1(data.begin() + begin, data.begin() + end);
        insertionSort(arr1);
        int i = begin;
        for (pairVectorIt it(arr1.begin(), arr1.end());
            it.first != it.second ; ++it.first) {
            data[i++] = *it.first;
        }
        return ;
    }
    const int mid = begin + (end - begin) / 2;
    mergeSort(data, begin, mid);
    mergeSort(data, mid, end);
    merge(data, begin, mid, end);
}

void PmergeMe::sortList() {
    // insertionSort(m_data);
    mergeSort(m_dataList, 0, m_data.size());
};

void merge(List &data, const int begin, const int mid, const int end) {
    List::iterator itBegin = data.begin();
    List::iterator itMid = data.begin();
    List::iterator itEnd = data.begin();
    
    for (int start = 0; start < begin; start++) {
        ++itBegin;
    }
    for (int start = 0; start < mid; start++) {
        ++itMid;
    }
    for (int start = 0; start < end; start++) {
        ++itEnd;
    }
    List data1(itBegin, itMid);
    List data2(itMid, itEnd);
    size_t i = 0;
    size_t j = 0;
    List result;
    while (i < data1.size() && j < data2.size()) {
        if (data1.at(i) < data2[j]) {
            result.push_back(data1[i++]);
        } else
            result.push_back(data2[j++]);
    }
    while (j < data2.size()) {
        result.push_back(data2[j++]);
    }
    while (i < data1.size()) {
        result.push_back(data1[i++]);
    }
    int index = begin;
    for (pairVectorIt it(result.begin(), result.end());
        it.first != it.second ; ++it.first) {
        data[index++] = *it.first;
    }
};

void mergeSort(List &data, const int begin, const int end) {
    if ((end - begin) <= 16) {
        List arr1(data.begin() + begin, data.begin() + end);
        insertionSort(arr1);
        int i = begin;
        for (pairVectorIt it(arr1.begin(), arr1.end());
            it.first != it.second ; ++it.first) {
            data[i++] = *it.first;
        }
        return ;
    }
    const int mid = begin + (end - begin) / 2;
    mergeSort(data, begin, mid);
    mergeSort(data, mid, end);
    merge(data, begin, mid, end);
}


void PmergeMe::printData() const { 
    for (pairVectorIt it(m_data.begin(), m_data.end());
        it.first != it.second; ++it.first)
    {
        std::cout << *it.first << " ";
    }
    std::cout << std::endl;
};

bool PmergeMe::isSorted() {
    return(isSortedContainer(m_data));
};

void printVector(const Vector &data) {
    size_t i = 0;
    while (i < data.size())
    {
        std::cout << data[i++] << " ";
    }
    std::cout << std::endl;
}
