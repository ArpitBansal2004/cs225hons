#include "list.h"

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
    
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

void List::print() {

    for( int num : list_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::list<int>::iterator partition(std::list<int>& lst, std::list<int>::iterator begin, std::list<int>::iterator end) {
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

// Recursive function to perform quicksort on a list
void quickSortRecursive(std::list<int>& lst, std::list<int>::iterator begin, std::list<int>::iterator end) {
    if (begin != end && std::next(begin) != end) {
        auto pivotIter = partition(lst, begin, end);
        quickSortRecursive(lst, begin, pivotIter);
        quickSortRecursive(lst, std::next(pivotIter), end);
    }
}

// Quicksort function for std::list<int>
void List::quickSort() {
    quickSortRecursive(list_, list_.begin(), std::prev(list_.end()));
}