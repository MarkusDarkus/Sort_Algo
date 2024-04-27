#ifndef RADIX_H
#define RADIX_H

void insertion_sort(int *array, int offset, int end);

void radix_sort(int *array, int offset, int end, int shift);

int intcmp(const void *aa, const void *bb);

#endif