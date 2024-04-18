#ifndef TIM_H
#define TIM_H

#include <algorithm>
#include <type_traits>
#include <vector>
#include <bits/stdc++.h> 

void insertionSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int l, int m, int r);
void timSort(std::vector<int>& arr, int n);

#endif // TIM_H