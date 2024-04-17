#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


void cocktailSort(std::vector<double> &arr)
{
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        end--;
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;
    }
}