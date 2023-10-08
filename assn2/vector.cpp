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


void List::countingSort() {
    int minVal = *std::min_element(list_.begin(), list_.end());
    int maxVal = *std::max_element(list_.begin(), list_.end());
    int range = maxVal - minVal + 1;

    std::vector<int> countingArray(range, 0);

    for (int num : list_) {
        countingArray[num - minVal]++;
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (countingArray[i] > 0) {
            list_[index++] = i + minVal;
            countingArray[i]--;
        }
    }
}

void List::stdSort() {
    std::sort(list_.begin(), list_.end());
}






