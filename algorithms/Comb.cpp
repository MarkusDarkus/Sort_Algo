#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}  


void combSort(std::vector<double>& arr) {
    int n = arr.size();
    int gap = n;
    float shrink = 1.3;
    bool swapped = true; 
    while (gap > 1 || swapped) {
        gap = static_cast<int>(gap / shrink); 
        if (gap < 1) {
            gap = 1;
        } 
        swapped = false; 
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}