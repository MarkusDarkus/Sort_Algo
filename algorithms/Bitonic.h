#ifndef BITONIC_H
#define BITONIC_H

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include<bits/stdc++.h>

void compAndSwap(std::vector<int> &arr, int i, int j, int dir);
void bitonicMerge(std::vector<int> &arr, int low, int cnt, int dir);
void bitonicSort(std::vector<int> &arr,int low, int cnt, int dir);
void sort(std::vector<int> &arr, int N, int up);

#endif // BITONIC_H