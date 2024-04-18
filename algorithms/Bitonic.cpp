#include "Bitonic.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include<bits/stdc++.h>


void compAndSwap(std::vector<int> &arr, int i, int j, int dir)
{
    if (dir==(arr[i]>arr[j]))
        std::swap(arr[i],arr[j]);
}


void bitonicMerge(std::vector<int> &arr, int low, int cnt, int dir)
{
	if (cnt>1)
	{
		int k = cnt/2;
		for (int i=low; i<low+k; i++)
			compAndSwap(arr, i, i+k, dir);
		bitonicMerge(arr, low, k, dir);
		bitonicMerge(arr, low+k, k, dir);
	}
}


void bitonicSort(std::vector<int> &arr,int low, int cnt, int dir)
{
	if (cnt>1)
	{
		int k = cnt/2;
		bitonicSort(arr, low, k, 1);
		bitonicSort(arr, low+k, k, 0);
		bitonicMerge(arr,low, cnt, dir);
	}
}


void sort_bitonic_(std::vector<int> &arr)
{
    int up = 1;
    int N = arr.size();
	bitonicSort(arr,0, N, up);
}
