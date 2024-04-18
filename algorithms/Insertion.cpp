#include "Insertion.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


void insertionSort(std::vector<int> &arr)
{
    if (arr.empty()) {
        return;
    }
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}