#include "Selection.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}