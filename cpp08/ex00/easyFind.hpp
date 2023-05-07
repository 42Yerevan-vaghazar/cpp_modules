#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int num) {
   return(std::find(container.begin(), container.end(), num));
}