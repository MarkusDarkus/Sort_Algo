#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include<bits/stdc++.h>


void compAndSwap(std::vector<double> &arr, int i, int j, int dir)
{
	if (dir==(arr[i]>arr[j]))
		swap(arr[i],arr[j]);
}


void bitonicMerge(std::vector<double> &arr, int low, int cnt, int dir)
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


void bitonicSort(std::vector<double> &arr,int low, int cnt, int dir)
{
	if (cnt>1)
	{
		int k = cnt/2;
		bitonicSort(arr, low, k, 1);
		bitonicSort(arr, low+k, k, 0);
		bitonicMerge(arr,low, cnt, dir);
	}
}


void sort(std::vector<double> &arr, int N, int up)
{
	bitonicSort(arr,0, N, up);
}
