#include<iostream>
#include<vector>

void smooth_easy(std::vector<int>& arr){
    for(int i = 1; i<arr.size(); ++i)
        arr[i] = (arr[i-1] + arr[i]) / 2;
}

void smooth(std::vector<int>& arr){
    std::vector<int> rhs = arr;
    int n = arr.size();
    for(int i = 0; i < n - 2; ++i){
        int j = (i == n - 1) ? 0 : i + 1;
        rhs[i] = 4 * arr[i] + 2 * arr[j];
    }
    arr = rhs;
}