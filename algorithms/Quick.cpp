#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>


template<class T>
void quickSortR(T *a, long N)
{
    long i = 0, j = N - 1;
    T temp, p;
    p = a[N >> 1];
    do {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quickSortR(a, j);
    if (N > i)
        quickSortR(a + i, N - i);
}