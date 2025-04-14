#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Sorted array:\n");
    printArray(A, n);

    return 0;
}

// ✅ Advantages of Merge Sort:
// Stable Sort
//   Maintains the relative order of equal elements.
//   Useful when sorting records with multiple keys (e.g., name and age).
// Time Complexity is Consistent: O(n log n)
//   Performs efficiently on large datasets.
//   Worst, average, and best cases are all O(n log n).
// Parallelizable
//   Easy to implement using multi-threading or parallel computing.
// Works Well with Linked Lists
//   Merge sort can be easily adapted for sorting linked lists (unlike quicksort, which needs random access).
// Divide and Conquer Approach
//   Conceptually simple and elegant recursion-based implementation.

// ❌ Disadvantages of Merge Sort:
// High Space Complexity: O(n)
//   Needs additional space for temporary arrays, unlike in-place sorts like Quick Sort or Heap Sort.
// Not Cache Friendly
//   Due to frequent memory allocation and copying, it may not take full advantage of CPU cache.
// Slower for Small Datasets
//   The overhead of recursion and memory usage makes it inefficient compared to simpler algorithms like Insertion Sort on small datasets.
// More Complex Implementation than Simple Sorts
//   Compared to Bubble or Selection Sort, the recursive implementation may be harder for beginners to debug or trace.
