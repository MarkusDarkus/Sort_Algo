#include "Gnome.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


void gnomeSort(std::vector<int> &arr)
{
    int n = arr.size();
    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}
