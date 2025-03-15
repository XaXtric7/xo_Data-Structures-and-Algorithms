#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array before sorting
    return 0;
}

// Advantages of Bubble Sort:

// - Simplicity – It is one of the simplest sorting algorithms to understand and implement.
// - Easy to Implement – Requires only a few lines of code, making it good for educational purposes.
// - In-Place Sorting – Does not require additional memory beyond the input array (space complexity O(1)).
// - Stable Sorting Algorithm – It maintains the relative order of equal elements, which is useful in certain applications.
// - Best Case Optimization – If the array is already sorted, it can detect this in O(n) time when using an optimized version with a swap flag.

// Disadvantages of Bubble Sort:

// - Slow for Large Datasets – It has a worst-case and average-case time complexity of O(n²), making it inefficient for large arrays.
// - Unnecessary Comparisons – Even if a part of the array is sorted, the algorithm still makes redundant comparisons.
// - Not Suitable for Practical Use – Due to its inefficiency, it is rarely used in real-world applications where faster sorting algorithms like Merge Sort, Quick Sort, or Heap Sort are preferred.
// - More Swaps – It performs excessive swapping, which increases the time taken compared to other sorting methods like Insertion Sort (which is better for nearly sorted data).
// - Not Adaptive (Without Modification) – The basic version does not stop early if the array becomes sorted in fewer passes unless explicitly modified.