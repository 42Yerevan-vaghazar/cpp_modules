#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &rhs)
    : m_dataBefore(rhs.m_dataBefore), m_dataVector(rhs.m_dataVector), m_dataList(rhs.m_dataList)  {};

PmergeMe::PmergeMe(Vector data) : m_dataBefore(data.begin(), data.end()), m_dataVector(data.begin(), data.end())  {};

PmergeMe::PmergeMe(List data) : m_dataBefore(data.begin(), data.end()), m_dataList(data.begin(), data.end())  {};

PmergeMe::~PmergeMe() {};

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
    if (this != &rhs) {
        m_dataList = rhs.m_dataList;
        m_dataVector = rhs.m_dataVector;
        m_dataBefore = rhs.m_dataBefore;
    }
    return (*this);
};

void PmergeMe::fillContainer(Vector data) {
    m_dataBefore =  Vector(data.begin(), data.end());
    m_dataVector = Vector(data.begin(), data.end());
};

void PmergeMe::fillContainer(List data) {
    m_dataBefore =  Vector(data.begin(), data.end());
    m_dataList = List(data.begin(), data.end());
};

void PmergeMe::fillContainer(int N) {
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> v(N);
    std::generate(v.begin(), v.end(), std::rand);
    this->fillContainer(v);
    this->fillContainer(List(v.begin(), v.end()));
};

void PmergeMe::sortVector() {
    if (m_dataVector.size() < 1) {
        throw std::logic_error("vector is empty");
    }
    mergeSort(m_dataVector, 0, m_dataVector.size());
};

void PmergeMe::sortList() {
    if (m_dataList.size() < 1) {
        throw std::logic_error("vector is empty");
    }
    mergeSort(m_dataList, 0, m_dataList.size());
};

void PmergeMe::printDataBefore() const { 
    printData(m_dataBefore);
};

void PmergeMe::printDataVector() const { 
    printData(m_dataVector);
};

void PmergeMe::printDataList() const { 
    printData(m_dataList);
};

bool PmergeMe::isSortedVector() const {
    return(isSortedContainer(m_dataVector));
};

bool PmergeMe::isSortedList() const {
    return(isSortedContainer(m_dataList));
};

void merge(Vector &data, const int begin, const int mid, const int end) {
    Vector data1(data.begin() + begin, data.begin() + mid);
    Vector data2(data.begin() + mid, data.begin() + end);
    int data1Size = data1.size();
    int data2Size = data2.size();
    int i = 0;
    int j = 0;
    Vector result;
    while (i < data1Size && j < data2Size) {
        if (data1[i] < data2[j]) {
            result.push_back(data1[i++]);
        } else
            result.push_back(data2[j++]);
    }
    while (j < data2Size) {
        result.push_back(data2[j++]);
    }
    while (i < data1Size) {
        result.push_back(data1[i++]);
    }
    int index = begin;
    for (pairVectorIt it(result.begin(), result.end());
        it.first != it.second ; ++it.first) {
        data[index++] = *it.first;
    }
};



void merge(List &data, const int begin, const int mid, const int end) {
    List::iterator itBegin = data.begin();
    List::iterator itMid = data.begin();
    List::iterator itEnd = data.begin();
    std::advance(itBegin, begin);
    std::advance(itMid, mid);
    std::advance(itEnd, end);
    List data1(itBegin, itMid);
    List data2(itMid, itEnd);
    List result;
    pairListIt iter1(data1.begin(), data1.end());
    pairListIt iter2(data2.begin(), data2.end());;

    while (iter1.first != iter1.second && iter2.first != iter2.second) {
        if (*iter1.first < *iter2.first) {
            result.push_back(*(iter1.first++));
        } else
            result.push_back(*(iter2.first++));
    }
    while (iter1.first != iter1.second) {
        result.push_back(*(iter1.first++));
    }
    while (iter2.first != iter2.second) {
        result.push_back(*(iter2.first++));
    }
    List::iterator itBeginTmp = itBegin;
    for (pairListIt it(result.begin(), result.end());
        it.first != it.second ; ++it.first) {
        *(itBeginTmp++) = *it.first;
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

void mergeSort(List &data, const int begin, const int end) {
    if ((end - begin) <= 16) {
        List::iterator itBegin = data.begin();
        List::iterator itEnd = data.begin();
        std::advance(itBegin, begin);
        std::advance(itEnd, end);
        List arr1(itBegin, itEnd);
        insertionSort(arr1);
        List::iterator itBeginTmp = itBegin;
        for (pairListIt it(arr1.begin(), arr1.end());
            it.first != it.second ; ++it.first) {
            *(itBeginTmp++) = *it.first;
        }
        return ;
    }
    const int mid = begin + (end - begin) / 2;
    mergeSort(data, begin, mid);
    mergeSort(data, mid, end);
    merge(data, begin, mid, end);
}


long double	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + (time.tv_usec));
}
