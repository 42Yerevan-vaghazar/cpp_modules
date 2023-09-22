#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<unsigned int> Vector;
class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		~Span();
		Span &operator=(const Span &obj);
		void addNumber(unsigned int);
		unsigned int shortestSpan() ;
		unsigned int longestSpan() const;
		template <typename T>
		void fillSpan(std::iterator<std::forward_iterator_tag, T> begin, std::iterator<std::forward_iterator_tag, T> end) {
			while (begin != end) {
				addNumber(*begin);
				++begin;
			}
		}
	private:
		unsigned int m_maxSize;
		Vector m_elems;
};