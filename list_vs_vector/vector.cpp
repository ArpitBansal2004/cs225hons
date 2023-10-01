#include "vector.h"
#include <iostream>

void List::insert(int number) {

    // list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
    auto it = list_.begin();
    while (it != list_.end() && (*it < number)) {
        ++it;
    }
    list_.insert(it,number);
}

void List::remove(int index) {
    auto it = list_.begin();

    it += index;
    // while(index-- > 0) {
    //     ++it;
    // }

    list_.erase(it);
}

void List::print() {

    for( int num : list_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


// Partitioning function for quicksort
std::vector<int>::iterator partition(std::vector<int>& vec, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    auto pivot = *std::prev(end);
    auto i = begin;
    for (auto j = begin; j != end; ++j) {
        if (*j < pivot) {
            std::swap(*i, *j);
            ++i;
        }
    }
    std::swap(*i, *end);
    return i;
}

// Recursive function to perform quicksort on a vector
void quickSortRecursive(std::vector<int>& vec, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin != end && std::next(begin) != end) {
        auto pivotIter = partition(vec, begin, end);
        quickSortRecursive(vec, begin, pivotIter);
        quickSortRecursive(vec, std::next(pivotIter), end);
    }
}

// Quicksort function for std::vector<int>
void List::quickSort() {
    quickSortRecursive(list_, list_.begin(), std::prev(list_.end()));
}




