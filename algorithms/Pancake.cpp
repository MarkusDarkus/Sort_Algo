#include "Pancake.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include<bits/stdc++.h> 



void flip(std::vector<int> &arr, int i) 
{ 
	int temp, start = 0; 
	while (start < i) 
	{ 
		temp = arr[start]; 
		arr[start] = arr[i]; 
		arr[i] = temp; 
		start++; 
		i--; 
	} 
} 


int findMax(std::vector<int> &arr, int n) 
{ 
    int mi, i; 
    for (mi = 0, i = 0; i < n; ++i) 
	    if (arr[i] > arr[mi]) 
			mi = i; 
    return mi; 
}


void pancakeSort(std::vector<int> &arr) 
{
    int n = arr.size();
	for (int curr_size = n; curr_size > 1; 
							--curr_size) 
	{
		int mi = findMax(arr, curr_size); 
		if (mi != curr_size - 1) 
		{ 
			flip(arr, mi); 
			flip(arr, curr_size - 1); 
		} 
	} 
} 
