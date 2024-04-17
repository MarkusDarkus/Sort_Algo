#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  


void insertionSort(std::vector<double>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}


void bucketSort(std::vector<double>& arr) {
    int n = arr.size();  
    std::vector<std::vector<double>> buckets(n);  
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }  
    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i]);
    }  
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}