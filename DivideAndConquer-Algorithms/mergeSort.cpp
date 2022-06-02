#include "mergeSort.h"
// Takes two arrays, and copies from "from" array to "to array"
void copyTo(int *from, int *to, int start, int end)
{
    for (int i = 0; i < end - start + 1; i++) // copy elements from start to end inclusive
    {
        to[i] = from[i + start];
    }
}

// Merges two subarrays created from array
void merge(int l, int m, int r, int *array)
{

    int *A = new int[m - l + 1]; // use difference between midpoint and start to create appropriate
                                 // subarray
    int *B = new int[r - m];     // us difference between end and midpoint to create appropriate
                                 // subarray

    copyTo(array, A, l, m);     // initializing subarray A
    copyTo(array, B, m + 1, r); // initialzing subarray B

    int i = 0, j = 0, k = l;           // i traverses subarray A, j traverses subarray B, k traverses array "array"
    while (i < m - l + 1 && j < r - m) // traverse both subarrays simultaneously
    {
        if (A[i] <= B[j]) // if element in subarray A is less than element in subarray B
        {
            array[k] = A[i]; // copy element in subarray A back to initial array
            i++;
        }
        else
        {
            array[k] = B[j]; // else copy element in subarray B back to initial array
            j++;
        }
        k++;
    }
    while (i < m - l + 1) // copy any element left in subarray A to main array "array"
    {
        array[k] = A[i];
        i++;
        k++;
    }
    while (j < r - m) // copy any element left in subarray B to main array "array"
    {
        array[k] = B[j];
        j++;
        k++;
    }
    delete A;
    delete B;
}

void mergesort(int *array, int start, int end)
{
    int mid;
    // call recursively till our array is broken up into single element
    // subarrays
    if (start < end)
    {
        // end - start so we get positive difference all the time
        mid = start + ((end - start) / 2); // we get mid point between start and end
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(start, mid, end, array);
    }
}