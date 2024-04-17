#ifndef BUBBLE_H
#define BUBBLE_H

#include "Bubble.h"
#include <algorithm>
#include <vector>

void bubbleSort(std::vector<double> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif
