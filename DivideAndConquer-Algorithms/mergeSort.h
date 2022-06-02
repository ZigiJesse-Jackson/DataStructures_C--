#ifndef MERGESORT_H
#define MERGESORT_H
void copyTo(int *from, int *to, int start, int end);
void merge(int l, int mid, int r, int *array);
void mergesort(int *array, int start, int end);

#endif