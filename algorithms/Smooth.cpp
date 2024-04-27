#include "Smooth.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


int leonardo(int k)
{
	if (k < 2) {
		return 1;
	}
	return leonardo(k - 1) + leonardo(k - 2) + 1;
}


void heapify_smooth(std::vector<int>& arr, int start, int end)
{
	int i = start;
	int j = 0;
	int k = 0;

	while (k < end - start + 1) {
		if (k & 0xAAAAAAAA) {
			j = j + i;
			i = i >> 1;
		}
		else {
			i = i + j;
			j = j >> 1;
		}

		k = k + 1;
	}

	while (i > 0) {
		j = j >> 1;
		k = i + j;
		while (k < end) {
			if (arr[k] > arr[k - i]) {
				break;
			}
			std::swap(arr[k], arr[k - i]);
			k = k + i;
		}

		i = j;
	}
}

// Smooth Sort function
std::vector<int> smooth_sort(std::vector<int>& arr)
{
	int n = arr.size();

	int p = n - 1;
	int q = p;
	int r = 0;
	while (p > 0) {
		if ((r & 0x03) == 0) {
            heapify_smooth(arr, r, q);
		}

		if (leonardo(r) == p) {
			r = r + 1;
		}
		else {
			r = r - 1;
			q = q - leonardo(r);
            heapify_smooth(arr, r, q);
			q = r - 1;
			r = r + 1;
		}

		std::swap(arr[0], arr[p]);
		p = p - 1;
	}

	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		while (j > 0 && arr[j] < arr[j - 1]) {
			std::swap(arr[j], arr[j - 1]);
			j = j - 1;
		}
	}
	return arr;
}

