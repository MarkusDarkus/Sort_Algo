#include<iostream>
#include<vector>

void smooth(std::vector<int>& arr){
    for(int i = 1; i<arr.size(); ++i)
        arr[i] = (arr[i-1] + arr[i]) / 2;
}