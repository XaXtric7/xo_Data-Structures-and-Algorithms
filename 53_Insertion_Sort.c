#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    // -1   0    1   2   3   4   5
    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

    // Fast forwarding and 4th and 5th pass will give:
    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
    //      07, 09, 12, 23, 54, 65| --> After the 5th pass

    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}

// ✅ Advantages of Insertion Sort:

// Simple and Easy to Implement – It is one of the easiest sorting algorithms to understand and code.
// Efficient for Small Data Sets – Performs well on small or nearly sorted arrays, with O(n) best-case time complexity.
// In-Place Sorting – Requires no extra memory (space complexity O(1)), making it memory-efficient.
// Stable Sorting Algorithm – Preserves the relative order of equal elements, which is important in certain applications.
// Adaptive (Efficient for Nearly Sorted Data) – If the array is almost sorted, insertion sort runs in O(n) time, making it faster than Bubble Sort and even Quick Sort in such cases.
// Works Well for Online Sorting – It can sort data as it receives it, making it useful for real-time applications.

// ❌ Disadvantages of Insertion Sort:

// Slow for Large Data Sets – Has an average and worst-case time complexity of O(n²), making it inefficient for big arrays.
// More Comparisons and Shifts – In worst cases, elements need to be shifted many times, increasing execution time.
// Not the Best for Unsorted Large Data – For randomly ordered large data, Merge Sort, Quick Sort, or Heap Sort are much faster.
// Recursive Alternative Can Be Better – Recursive algorithms like Merge Sort or Quick Sort divide and conquer, reducing comparisons in large data sets.