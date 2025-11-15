// Write a program to implement a merge sort algorithm.

#include <stdio.h>

void merge(int a[], int low, int mid, int high){
    int i = low;        // start of left half
    int j = mid + 1;    // start of right half
    int k = low;        // start index for temp array
    int b[50];          // temporary array

    // merge both halves into b[]
    while (i <= mid && j <= high){
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    // copy remaining elements of left half (if any)
    while (i <= mid)
        b[k++] = a[i++];

    // copy remaining elements of right half (if any)
    while (j <= high)
        b[k++] = a[j++];
        
    // copy sorted elements back to original array
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void printArray(int a[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Unsorted array:\n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("Sorted array (Merge Sort):\n");
    printArray(a, n);

    return 0;
}
